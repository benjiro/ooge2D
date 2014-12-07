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

#ifndef _IMAGE_HPP_
#define _IMAGE_HPP_

#include <Config.hpp>
#include <Rect.hpp>
#include <Colour.hpp>
#include <string>
#include <vector>

namespace ooge
{
	class OOGE_API Image
	{
	public:
		Image();
		Image(const Image &image);
		Image(const std::string &filename, Int32 loadFlag = 4);
		Image(const UInt8 *data, size_t sizeOf, Int32 loadFlag = 4);
		Image(std::vector<ColourUInt8> &pixelInformation);
		~Image();

		bool CreateTexture();
		bool LoadImageFile(const std::string &fileName);
		bool LoadImageData(const UInt8 *data, size_t sizeOf);

		void SetTextureCoords(const Rect &setCoords);
		const Rect &GetTextureCoords() const;

		void SetTexture(Texture texID);
		Texture GetTexture() const;

		void SetPixelBuffer(std::vector<ColourUInt8> &pixel);
		std::vector<ColourUInt8> &GetPixelBuffer();

		Int32 GetFlags() const;
		void SetHeight(Int32 height) { mHeight = height;}
		void SetWidth(Int32 width) { mWidth = width;}
		Int32 GetHeight() const;
		Int32 GetWidth() const;
	protected:
		void DestoryTexture();
	private:
		UInt32 mHeight;
		UInt32 mWidth;
		Int32 mFlags;

		Texture mTexture;
		Rect mTextureCoords;
		std::vector<ColourUInt8> mPixels;
	};
}

#endif //_IMAGE_HPP_