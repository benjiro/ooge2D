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

#ifndef _SOUNDFILE_HPP_
#define _SOUNDFILE_HPP_

#include <Config.hpp>
#include <sndfile.h>
#include <string>

namespace ooge
{
	class OOGE_API SoundFile
	{
	public:
		SoundFile();
		~SoundFile();

		bool OpenRead(const std::string &filename, UInt32 *channels, UInt32 *samplerate, UInt32 *samples);
		bool OpenRead(UInt8 *data, const std::size_t size, UInt32 *channels, UInt32 *samplerate, UInt32 *samples);

		bool OpenWrite(const std::string &filename, UInt32 channels, UInt32 samplerate);

		std::size_t Read(Int16 *buffer, const UInt32 samples);
		std::size_t Write(const Int16 *buffer, const UInt32 samples);

		static sf_count_t MemoryLength(void *userData);
		static sf_count_t MemorySeek(sf_count_t offset, Int32 whence, void *userData);
		static sf_count_t MemoryRead(void *ptr, sf_count_t count, void *userData);
		static sf_count_t MemoryWrite(const void *ptr, sf_count_t count, void *userData);
		static sf_count_t MemoryTell(void *userData);

		Int32 IsFileSupport(const std::string &filename);

		struct MemoryData
		{
			sf_count_t Offset;
			sf_count_t Length;
			UInt8 *Data;
		};
	private:
		SNDFILE *mFile;
		MemoryData mMemoryData;
	};
}

#endif //_SOUNDFILE_HPP_