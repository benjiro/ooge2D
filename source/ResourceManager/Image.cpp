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

#include <Image.hpp>
#include <Loader.hpp>
#include <Math.hpp>
#include <Common.hpp>

using namespace ooge;

Image::Image()
: mTexture(0), mWidth(0), mHeight(0), mTextureCoords()
{
}

Image::Image(const Image &image)
: mTexture(image.GetTexture()), 
mWidth(image.GetWidth()), 
mHeight(image.GetHeight()),
mTextureCoords(image.GetTextureCoords()),
mFlags(image.GetFlags())
{
	//SetPixelBuffer(image.GetPixelBuffer());
}

Image::Image(const std::string &filename, Int32 loadFlags)
: mTexture(0), mWidth(0), mHeight(0), mFlags(loadFlags),
mTextureCoords(0.0f, 0.0f, 1.0f, 1.0f) 
{
	LoadImageFile(filename);
}

Image::Image(const UInt8 *data, size_t sizeOf, Int32 loadFlags)
: mTexture(0), mWidth(0), mHeight(0), mFlags(loadFlags),
mTextureCoords(0.0f, 0.0f, 1.0f, 1.0f) 
{
	LoadImageData(data, sizeOf);
}

Image::Image(std::vector<ColourUInt8> &pixelInformation)
: mTexture(0), mWidth(0), mHeight(0), mFlags(0),
mTextureCoords(0.0f, 0.0f, 1.0f, 1.0f), mPixels(pixelInformation)
{
	CreateTexture();
}

Image::~Image()
{
	DestoryTexture();
}

bool Image::CreateTexture()
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

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

	gluBuild2DMipmaps(GL_TEXTURE_2D, 4, mWidth, mHeight, GL_RGBA, GL_UNSIGNED_BYTE, &mPixels[0]);

	mTexture = static_cast<UInt32>(texture);
	return true;
}

bool Image::LoadImageFile(const std::string &filename)
{
	bool success = Loader::GetSingletonPtr()->ImageFromFile(filename, mPixels, &mWidth, &mHeight, mFlags); 
	if(success)
	{
		CreateTexture();
		return true;
	}
	return false;
}

bool Image::LoadImageData(const UInt8 *data, size_t sizeOf)
{
	bool success = Loader::GetSingletonPtr()->ImageFromMemory(data, sizeOf, mPixels, &mWidth, &mHeight, mFlags);
	if(success)
	{
		CreateTexture();
		return true;
	}
	return false;

}

void Image::DestoryTexture()
{
	GLuint tex = static_cast<GLuint>(mTexture);
	glDeleteTextures(1, &tex);
	mTexture = 0;
	mHeight = 0;
	mWidth = 0;
}

void Image::SetTextureCoords(const Rect &setCoords)
{
	mTextureCoords = setCoords;
}

const Rect &Image::GetTextureCoords() const
{
	return mTextureCoords;
}

void Image::SetTexture(Texture texID)
{
	mTexture = texID;
}

Texture Image::GetTexture() const
{
	return mTexture;
}

Int32 Image::GetWidth() const
{
	return mWidth;
}

Int32 Image::GetHeight() const
{
	return mHeight;
}

Int32 Image::GetFlags() const
{
	return mFlags;
}

void Image::SetPixelBuffer(std::vector<ColourUInt8> &pixel)
{
	mPixels = pixel;
}

std::vector<ColourUInt8> &Image::GetPixelBuffer()
{
	return mPixels;
}