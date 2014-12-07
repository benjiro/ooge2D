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

#ifndef _FONT_HPP_
#define _FONT_HPP_

#include <Config.hpp>
#include <string>
#include <map>
#include <vector>
#include <Colour.hpp>
#include <GlyphContainer.hpp>

namespace ooge
{
	class OOGE_API Font
	{
	public:
		Font();
		Font(Font &font);
		Font(const std::string &filename, UInt32 fontSize, const std::string &characterSet = mDefaultCharacterSet);
		~Font();

		bool CreateFontMapTexture();

		void SetFileName(const std::string &fileName);
		const std::string &GetFileName() const;

		void SetFontSize(UInt32 size);
		const UInt32 GetFontSize() const;

		const Texture GetTexture() const;
		const UInt32 GetTextureWidth() const;
		const UInt32 GetTextureHeight() const;

		void SetFontMap(std::map<UInt8, GlyphContainer> &fontMap);
		std::map<UInt8, GlyphContainer> &GetFontMap();
	private:
		static std::string mDefaultCharacterSet;

		UInt32 mSize;
		UInt32 mWidth;
		UInt32 mHeight;
		Texture mTexture;
		std::string mFileName;
		std::vector<UInt8> mPixelBuffer;
		std::map<UInt8, GlyphContainer> mFontMap; 
	};
}

#endif //_FONT_HPP_