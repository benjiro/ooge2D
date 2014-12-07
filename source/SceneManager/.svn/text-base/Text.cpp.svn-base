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

#include <Text.hpp>
#include <Font.hpp>
#include <GlyphContainer.hpp>
#include <Common.hpp>

using namespace ooge;


Text::Text(Font *font, const std::string &text, const Vector2 &position, const Vector2 &scale)
: mFont(font), mText(text), mStyle(0),
Renderable(text, position, scale)
{
}

Text::Text(Text &text)
: mFont(text.GetFont()), mText(text.GetText()), mStyle(text.GetFontStyle()),
Renderable(text.GetName() ,text.GetPosition(), text.GetScale(), text.GetRotation(), text.GetColour())
{
}

void Text::SetFontStyle(Int32 style)
{
	mStyle = style;
}

const Int32 Text::GetFontStyle() const
{
	return mStyle;
}

void Text::SetText(const std::string &text)
{
	mText = text;
}

std::string &Text::GetText()
{
	return mText;
}

void Text::SetFont(Font &font)
{
	mFont = &font;
}

Font *Text::GetFont()
{
	return mFont;
}

void Text::Render()
{
	glLoadIdentity();
	glTranslatef(GetPosition().X, GetPosition().Y, 0.0f);
	glRotatef(GetRotation(), 0, 0, 1);
	glScalef(GetScale().X, GetScale().Y, 0.0f);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, mFont->GetTexture());

	//Stores reference to glyph map
	std::map<UInt8, GlyphContainer> fontMap = mFont->GetFontMap();
	//Stores coordinates for underline
	std::vector<Vector2> underlineCoords;

	//Stores the position start and current glyph position
	Vector2 startPosition = GetPosition();
	Vector2 currentPosition = GetPosition();
	
	//padding for underline and new line
	const UInt8 padding = 5;
	
	glBegin(GL_QUADS);

	//Iterate over the text and find glyph and render
	std::string::const_iterator it(mText.begin());
	std::string::const_iterator const endIt(mText.end());
	for(; it != endIt; ++it)
	{
		//work out realtive position
		float xRealtive = currentPosition.X - startPosition.X;
		float yRealtive = currentPosition.Y - startPosition.Y;

		//Start position for underline
		underlineCoords.push_back(Vector2(xRealtive,yRealtive));

		float italics = (mStyle & Italic) ? 12.0f : 0.0f;
		
		//find glyph
		std::map<UInt8, GlyphContainer>::const_iterator find = fontMap.find((*it));
		if(find != fontMap.end())
		{
			//get rid of some verbose
			const GlyphContainer &glyph = (*find).second;

			//If there is a space move position by advanced
			if((*it) == ' ')
				xRealtive += glyph.Advance;

			glTexCoord2f(glyph.TextureCoords.Left, glyph.TextureCoords.Bottom);
			glVertex2f(xRealtive, yRealtive);

			glTexCoord2f(glyph.TextureCoords.Left, glyph.TextureCoords.Top);
			glVertex2f(xRealtive - italics, yRealtive + glyph.LineHeight);

			glTexCoord2f(glyph.TextureCoords.Right, glyph.TextureCoords.Top);
			glVertex2f(xRealtive + glyph.Advance - italics, yRealtive + glyph.LineHeight);

			glTexCoord2f(glyph.TextureCoords.Right, glyph.TextureCoords.Bottom);
			glVertex2f(xRealtive + glyph.Advance, yRealtive);

			//render 4 more times as offsets if bold
			if(mStyle & Bold)
			{
				const static float offsetX[] = {1.0f,-1.0f,0.0,0.0};
				const static float offsetY[] = {0,0,1.0f,-1.0f};
				
				for(int j = 0; j < 4; ++j)
				{
					glTexCoord2f(glyph.TextureCoords.Left, glyph.TextureCoords.Bottom);
					glVertex2f(xRealtive + offsetX[j], yRealtive + offsetY[j]);

					glTexCoord2f(glyph.TextureCoords.Left, glyph.TextureCoords.Top);
					glVertex2f(xRealtive + offsetX[j], yRealtive + glyph.LineHeight + offsetY[j]);

					glTexCoord2f(glyph.TextureCoords.Right, glyph.TextureCoords.Top);
					glVertex2f(xRealtive + glyph.Advance + offsetX[j], yRealtive + glyph.LineHeight + offsetY[j]);

					glTexCoord2f(glyph.TextureCoords.Right, glyph.TextureCoords.Bottom);
					glVertex2f(xRealtive + glyph.Advance + offsetX[j], yRealtive + offsetY[j]);
				}
			}
			//Advance the position
			currentPosition.X += glyph.Advance;
			
			//end position for underline
			underlineCoords.push_back(Vector2(xRealtive + glyph.Advance, yRealtive));
		}
		else
		{
			//Newline move the y down by size of the font plus padding
			if((*it) == '\n')
			{
				currentPosition.Y += mFont->GetFontSize() + padding;
				//reset x position back to start
				currentPosition.X = startPosition.X;
				//delete the last underline position
				underlineCoords.pop_back();
			}
			
			if((*it) == '\t')
			{
				currentPosition.X += (mFont->GetFontSize() + padding) * 4;
				underlineCoords.pop_back();
			}
		}
	}
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//Draw the underline if enabled
	if(mStyle & Underline)
	{
		//work out thickness based on if bold is enabled
		Real thickness = (mStyle & Bold) ? 3.0f : 2.0f;
		Real heightOffset = mFont->GetFontSize() + 3.5f;
		glLineWidth(thickness);
		glBegin(GL_LINES);
		for(UInt32 x = 0; x < underlineCoords.size(); ++x)
		{
			glVertex2f(underlineCoords[x].X, underlineCoords[x].Y + heightOffset);
		}
		glEnd();
	}
}

void Text::Update(Real deltaT)
{
}