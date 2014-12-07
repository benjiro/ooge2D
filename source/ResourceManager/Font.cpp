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

#include <Font.hpp>
#include <Loader.hpp>
#include <GlyphContainer.hpp>
#include <Image.hpp>
#include <Common.hpp>

using namespace ooge;

std::string Font::mDefaultCharacterSet =
"abcdefghijklmnopqrstuvwxyz"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"1234567890~!@#$%^&*()-=+;:"
"'\",./?[]|\\ <>'\xFF";

Font::Font()
{
}

Font::Font(const std::string &filename, UInt32 fontSize, const std::string &characterSet)
	: mFileName(filename), mSize(fontSize)
{
	Loader::GetSingleton().FontFromFile(filename, *this, mPixelBuffer, &mWidth, &mHeight,mDefaultCharacterSet);
	CreateFontMapTexture();
}

Font::Font(Font &font)
	: mFileName(font.GetFileName()), mSize(font.GetFontSize())
{
}

Font::~Font()
{
	mFontMap.clear();
	glDeleteTextures(1, &mTexture);
}

bool Font::CreateFontMapTexture()
{
	if(!mWidth && !mHeight)
		return false;

	if(!glewIsSupported("GL_ARB_texture_non_power_of_two"))
	{
		mWidth = math::NextPow2(mWidth);
		mHeight = math::NextPow2(mHeight);
	}

	GLint maxsize;
	glGetIntegerv(GL_MAX_TEXTURE_SIZE, &maxsize);
	if(mWidth > static_cast<UInt32>(maxsize) || mHeight > static_cast<UInt32>(maxsize))
	{
		return false;
	}

	GLuint texture = 0;

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA8, mWidth, mHeight, 0, GL_ALPHA, GL_UNSIGNED_BYTE, &mPixelBuffer[0]);

	mTexture = static_cast<UInt32>(texture);

	return true;
}

void Font::SetFileName(const std::string &fileName)
{
	mFileName = fileName;
}

const std::string &Font::GetFileName() const
{
	return mFileName;
}

void Font::SetFontSize(UInt32 size)
{
	mSize = size;
}

const UInt32 Font::GetFontSize() const
{
	return mSize;
}

void Font::SetFontMap(std::map<UInt8,GlyphContainer> &fontMap)
{
	mFontMap = fontMap;
}

std::map<UInt8, GlyphContainer> &Font::GetFontMap()
{
	return mFontMap;
}

const Texture Font::GetTexture() const
{
	return mTexture;
}

const UInt32 Font::GetTextureWidth() const
{
	return mWidth;
}

const UInt32 Font::GetTextureHeight() const
{
	return mHeight;
}
