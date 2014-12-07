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

#ifndef _LOADER_HPP_
#define _LOADER_HPP_

#include <Singleton.hpp>
#include <Colour.hpp>
#include <string>
#include <vector>
#include <map>
#include <Config.hpp>

#include <ft2build.h>
#include FT_FREETYPE_H

namespace ooge
{
	class Font;
	class GlyphContainer;

	class OOGE_API Loader : public Singleton<Loader>
	{
	public:
		Loader();
		~Loader();

		bool ImageFromFile(const std::string &filename, std::vector<ColourUInt8> &pixInformaion, UInt32 *width, UInt32 *height, Int32 loadFlags);
		bool ImageFromMemory(const UInt8 *data, size_t bytes, std::vector<ColourUInt8> &pixInformaion, UInt32 *width, UInt32 *height, Int32 loadFlags);
		bool ImageOfScreen(const std::string &filename, Int32 screenH, Int32 screenW);

		bool FontFromFile(const std::string &filename, Font &font, std::vector<UInt8> &textureBuffer, UInt32 *width, UInt32 *height, const std::string &characterSet);
		bool FontFileMemory(const UInt8 *data, size_t bytes /*, Font &font */);

		bool SoundFromFile(const std::string &filename, std::vector<Int16> buffer, Int32 *channels, Int32 *samplerate, Int32 *samples);

		bool AllocateGlyphTexture(FT_Face &face, const std::string &characterSet, std::vector<UInt8> &textureBuffer ,std::map<UInt8, GlyphContainer> &fontMap, UInt32 *width, UInt32 *height);

		static Loader &GetSingleton();
		static Loader *GetSingletonPtr();
	private:
		FT_Library mLibrary;
	};
}

#endif //_LOADER_HPP_