/*
This file is apart of ooge(object-oriented 2D game engine)

-------------------------------------------------------------------
Copyright (c) 2010 Benjamin Evenson

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
-------------------------------------------------------------------
*/

#include <Loader.hpp>
#include <SOIL.h>
#include <Font.hpp>
#include <Common.hpp>
#include <GlyphContainer.hpp>
#include <sndfile.h>
#include FT_GLYPH_H
#include FT_MODULE_H


using namespace ooge;

template<> Loader *Singleton<Loader>::ms_Singleton = 0;

Loader::Loader()
{
	if(FT_Init_FreeType(&mLibrary))
		std::cout << "Freetype initalisation vaild" << std::endl;
}

Loader::~Loader()
{
	if(mLibrary)
		FT_Done_Library(mLibrary);
}

bool Loader::ImageFromFile(const std::string &filename, std::vector<ColourUInt8> &pixInformaion, UInt32 *width, UInt32 *height, Int32 loadFlags)
{
	Int32 tChannels, tWidth, tHeight;
	UInt8 *image = SOIL_load_image(filename.c_str(), &tWidth, &tHeight, &tChannels, loadFlags);

	if(image)
	{
		*width = static_cast<UInt32>(tWidth);
		*height = static_cast<UInt32>(tHeight);

		pixInformaion.clear();
		pixInformaion.resize(tHeight * tWidth);

		memcpy(&pixInformaion[0], image, tHeight * tWidth * 4);

		SOIL_free_image_data(image);

		return true;
	}
	return false;
}

bool Loader::ImageFromMemory(const UInt8 *data, size_t bytes, std::vector<ColourUInt8> &pixInformaion, UInt32 *width, UInt32 *height, Int32 loadFlags)
{
	Int32 tChannels, tWidth, tHeight;
	UInt8 *image = SOIL_load_image_from_memory(data, bytes, &tWidth, &tHeight, &tChannels, loadFlags);

	if(image)
	{
		*width = static_cast<UInt32>(tWidth);
		*height = static_cast<UInt32>(tHeight);

		pixInformaion.clear();
		pixInformaion.resize(tWidth * tHeight);

		memcpy(&pixInformaion[0], image, tWidth * tHeight * 4);

		return true;
	}
	return false;
}

bool Loader::ImageOfScreen(const std::string &filename, Int32 screenH, Int32 screenW)
{
	Int32 result = SOIL_save_screenshot(filename.c_str(), SOIL_SAVE_TYPE_BMP, 0, 0, screenW, screenH); 

	if(result == 0)
	{
		std::cout << "Error Saving Screenshot: " << SOIL_last_result() << std::endl;
		return false;
	}
	else
		return true;
}

bool Loader::FontFromFile(const std::string &filename, Font &font, std::vector<UInt8> &textureBuffer, UInt32 *width, UInt32 *height, const std::string &characterSet)
{
	FT_Face face;

	if(FT_New_Face(mLibrary, filename.c_str(), 0, &face))
	{
		std::cout << "Can't find font file or unsupported" << std::endl;
		return false;
	}

	if(FT_Set_Char_Size(face, font.GetFontSize() << 6, font.GetFontSize() << 6, 96, 96))
	{
		std::cout << "Failed to set font size" << std::endl;
		return false;
	}

	//Do funky stuff of creating a font texture
	if(!AllocateGlyphTexture(face, characterSet, textureBuffer, font.GetFontMap(), width, height))
	{
		std::cout << "Failed to Allocate Texture for Font" << std::endl;
		return false;
	}

	return true;
}

bool Loader::AllocateGlyphTexture(FT_Face &face, const std::string &characterSet, std::vector<UInt8> &textureBuffer, std::map<UInt8, GlyphContainer> &fontMap, UInt32 *width, UInt32 *height)
{	
	textureBuffer.clear();

	UInt32 textureWidth = 512;
	UInt32 textureHeight = 0;
	UInt32 textureRows = 1;
	const int padding = 5;
	Int32 maxDescent = 0; 
	Int32 maxAcent = 0;
	UInt32 spaceOnLine = textureWidth - padding;

	//Loop through characterset to find texture size and store all glyphs in map
	std::string::const_iterator it(characterSet.begin());
	std::string::const_iterator const endIt(characterSet.end());
	for(; it < endIt; ++it)
	{
		//UInt32 to handle bigger character sets like Japanese
		UInt32 character = FT_Get_Char_Index(face, (*it));
		if((*it) == '\xFF')
			character = 0;

		//Load given glyph for current character
		FT_Load_Glyph(face, character, FT_LOAD_DEFAULT);
		//Render glyph to bitmap format
		FT_Render_Glyph(face->glyph, FT_RENDER_MODE_NORMAL);

		//work out position of next character horiAdvance * 64 + padding
		//freetype works in 64th of a pixel
		UInt32 advance = (face->glyph->metrics.horiAdvance >> 6) + padding;
		//Check to see if current advance is greater then texture width, adjust texture height
		if(advance > spaceOnLine)
		{
			spaceOnLine = textureWidth - padding;
			++textureRows;
		}

		//How much space we have left
		spaceOnLine -= advance;

		//keep track of maxAcent, distance from baseline to highest outline point
		maxAcent = math::Max(face->glyph->bitmap_top, maxAcent);
		//keep track of maxDescent, distance from baseline to lowest outline point
		maxDescent = math::Max(face->glyph->bitmap.rows - face->glyph->bitmap_top, maxDescent);


		//Fill in blank data recompute later
		GlyphContainer *glyph = new GlyphContainer();
		glyph->Advance = 0;
		glyph->LineHeight = 0;
		glyph->TextureCoords = Rect();

		//Add Character and Glyph to the Map
		fontMap.insert(std::pair<UInt8, GlyphContainer>((*it), *glyph));

		//Clean up
		delete glyph;
	}

	//work out texture height now that max acent & descent & number of rows outed out
	textureHeight = math::NextPow2((maxAcent + maxDescent + padding) * textureRows + padding);

	//Resize pixel buffer to size of image
	char *pixelBuffer = new char[textureWidth * textureHeight];
	//Assign buffer to 0, prevent funky alpha blending
	for(UInt32 o = 0; o < textureWidth * textureHeight; o++)
		pixelBuffer[o] = 0;

	//Keep track off where in the texture we are
	UInt32 offsetX = padding;
	UInt32 offsetY = padding + maxAcent;

	//Loop through every Glyph and render it into pixel buffer
	std::map<UInt8, GlyphContainer>::iterator glyphIt = fontMap.begin();
	for(; glyphIt != fontMap.end(); ++glyphIt)
	{
		//Get index from width freetype for given character
		UInt32 character = FT_Get_Char_Index(face, (*glyphIt).first);
		//Unknown character?
		if((*glyphIt).first == '\xFF')
			character = 0;

		//Render Glyph into bitmap
		FT_Load_Glyph(face, character, FT_LOAD_DEFAULT);
		FT_Render_Glyph(face->glyph, FT_RENDER_MODE_NORMAL);
		FT_BitmapGlyph bitmap = (FT_BitmapGlyph)face->glyph;

		//Get advance to update offsets
		UInt32 advance = (face->glyph->metrics.horiAdvance >> 6) + padding;
		//If overflowed off texture offset down the Y and reset OffsetX
		if(advance > textureWidth - offsetX)
		{
			offsetX = padding;
			offsetY += (maxAcent + maxDescent + padding);
		}

		//Loop through and find each pixel on each row and copy it into the pixel buffer
		//Copy data into pixel buffer based on offsetX and offsetY position
		for(Int32 row = 0; row < face->glyph->bitmap.rows; ++row)
		{
			for(Int32 pixel = 0; pixel < face->glyph->bitmap.width; ++pixel)
			{
				pixelBuffer[(offsetX + face->glyph->bitmap_left + pixel) + 
							  (offsetY - face->glyph->bitmap_top + row) * textureWidth] = 
				face->glyph->bitmap.buffer[pixel + row * face->glyph->bitmap.pitch];
			}
		}

		//Recompute Texturecoords and Width of glyph
		(*glyphIt).second.Advance = advance - padding;
		(*glyphIt).second.TextureLine = (maxAcent + maxDescent) * 1.0f / textureHeight;
		(*glyphIt).second.TextureCoords = Rect((offsetX * 1.0f) / textureWidth, (((offsetY - maxAcent) * 1.0f) / textureHeight) + (*glyphIt).second.TextureLine, 
			(offsetX + (*glyphIt).second.Advance  * 1.0f) / textureWidth, ((offsetY - maxAcent) * 1.0f) / textureHeight);
		(*glyphIt).second.LineHeight = maxAcent + maxDescent;

		//move offsetX into the texture
		offsetX += advance;

		//FT_Done_Glyph((FT_Glyph)bitmap);
	}

	//Done with face now clean up
	FT_Done_Face(face);

	//Copy the buffer into
	textureBuffer.resize(textureWidth * textureHeight);
	memcpy(&textureBuffer[0], pixelBuffer, textureWidth * textureHeight);

	delete [] pixelBuffer;

	*width = textureWidth;
	*height = textureHeight;

	return true;
}

bool Loader::SoundFromFile(const std::string &filename, std::vector<Int16> buffer, Int32 *channels, Int32 *samplerate, Int32 *samples)
{
	SF_INFO fileinfo;
	SNDFILE *file = sf_open(filename.c_str(), SFM_READ, &fileinfo);

	if(file)
	{
		*channels = fileinfo.channels;
		*samplerate = fileinfo.samplerate;
		*samples = *channels * fileinfo.frames;
		std::size_t d= *channels * fileinfo.frames; 

		buffer.clear();
		buffer.resize(d);
		sf_read_short(file, &buffer[0], d);

		return true;
	}
	else
		return false;
}

Loader &Loader::GetSingleton()
{
	assert(ms_Singleton);
	return (*ms_Singleton);
}

Loader *Loader::GetSingletonPtr()
{
	return ms_Singleton;
}