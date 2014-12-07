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

#ifndef _SOUND_BUFFER_HPP_
#define _SOUND_BUFFER_HPP_

#include <Config.hpp>
#include <vector>

namespace ooge
{
	class OOGE_API SoundBuffer
	{
	public:
		SoundBuffer(const std::string &filename);
		~SoundBuffer();

		bool LoadFromFile(const std::string &filename);
		bool LoadFromMemory(UInt8 *data, std::size_t sizeOfBytes);
		bool SaveToDisk(const std::string &filename);

		UInt32 GetNumberOfChannels() const;
		UInt32 GetSampleRate() const;
		UInt32 GetBufferHandle() const;
		std::size_t GetNumberOfSamples() const;
		Real GetDuration() const;

		const Int16 *GetBuffer() const;
	protected:
		void _CreateBuffer(UInt32 samplesRate, UInt32 channels);
	private:
		UInt32 mBufferHandle;
		Real mDuration;

		std::vector<Int16> mBuffer;
	};
}

#endif //_SOUND_BUFFER_HPP_