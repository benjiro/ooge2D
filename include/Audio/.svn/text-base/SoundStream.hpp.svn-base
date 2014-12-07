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

#ifndef _SOUNDSTREAM_HPP_
#define _SOUNDSTREAM_HPP_

#include <Sound.hpp>
#include <Thread.hpp>
#include <vector>

#define THREAD_UPDATE (20)

namespace ooge
{
	class SoundFile;

	class OOGE_API SoundStream : private Thread, public SoundEffect
	{
	public:
		SoundStream(const std::string &filename, UInt32 bufferSize = 0, UInt32 numberOfBuffers = 4);
		SoundStream(const SoundStream &stream);
		~SoundStream();

		void Play();
		void Stop();
		void Pause(bool pause);

		void SetFile(SoundFile *file);
		SoundFile *GetFile() const;

		void SetLoop(bool loop);
		bool GetLoop() const;
	
		const std::string &GetFileName() const;
		UInt32 GetNumberOfChannels() const;
		UInt32 GetBufferSize() const;
		UInt32 GetNumberOfSamples() const;
		UInt32 GetNumberOfBuffers() const;
		UInt32 GetSampleRate() const;
		UInt32 GetSource() const;
		UInt32 *GetBufferList() const;
		Real GetDuration() const;
	protected:
		void _UpdateAndQueueBuffer(UInt32 buffer);
		void _ClearQueue();
	private:
		virtual void Run();

		std::string mFileName;

		UInt32 mBufferSize;
		UInt32 mChannels;
		UInt32 mSamplerate;
		UInt32 mSamples;
		UInt32 mNumberOfBuffers;
		Real mDuration;
		bool mPlaying;
		bool mLoop;

		SoundFile *mFile;
		UInt32 mSource;
		UInt32 *mBuffer;
	};
}

#endif //_SOUNDSTREAM_HPP_