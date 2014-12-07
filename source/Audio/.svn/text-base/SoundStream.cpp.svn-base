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

#include <SoundStream.hpp>
#include <SoundFile.hpp>
#include <AudioDevice.hpp>

using namespace ooge;

SoundStream::SoundStream(const std::string &filename, UInt32 bufferSize, UInt32 numberOfBuffers)
: mFile(new SoundFile()), mBufferSize(bufferSize), mNumberOfBuffers(numberOfBuffers), mPlaying(false),
mBuffer(new UInt32[mBufferSize]), mFileName(filename),
SoundEffect()
{
	alGenBuffers(mNumberOfBuffers, mBuffer);
	alGenSources(1, &mSource);
	SetSource(mSource);

	if(!mFile->OpenRead(filename, &mChannels, &mSamplerate, &mSamples))
	{
		std::cerr << "Error Opening file. does the file exist??" << std::endl;
		return;
	}

	if((AudioDevice::GetSingletonPtr()->GetChannelFormat(mChannels)) == 0)
	{
		std::cerr << "Unsupport number of channels. " << mChannels << std::endl;
	}

	mDuration = (static_cast<Real>(mSamples) / mSamplerate / mChannels);

	if(mBufferSize == 0)
	{
		mBufferSize = mSamplerate >> 2;
		mBufferSize -= (mBufferSize % sizeof(Int16));
	}
}

SoundStream::SoundStream(const SoundStream &sound)
: mFile(sound.GetFile()), mChannels(sound.GetNumberOfChannels()), mSamplerate(sound.GetSampleRate()),
mSamples(sound.GetNumberOfSamples()), mNumberOfBuffers(sound.GetNumberOfBuffers()), mPlaying(false),
mBuffer(sound.GetBufferList()), mSource(sound.GetSource()), mBufferSize(sound.GetBufferSize()),
mFileName(sound.GetFileName()),
SoundEffect()
{
	SetSource(mSource);
}

SoundStream::~SoundStream()
{
	if(mPlaying)
		Kill();

	if(mFile)
	{
		alSourceStop(mSource);
		alDeleteSources(1, &mSource);
		alDeleteBuffers(mNumberOfBuffers, mBuffer);
		delete mFile;
	}
}

void SoundStream::Play()
{
	mPlaying = true;
	Start();
}

void SoundStream::Pause(bool pause)
{
	mPlaying = pause;
}

void SoundStream::Stop()
{
	alSourceStop(mSource);
	_ClearQueue();
	Kill();
}

void SoundStream::_UpdateAndQueueBuffer(UInt32 buffer)
{
	Int16 *data = new Int16[mBufferSize];
	std::size_t bytesRead = mFile->Read(data, mBufferSize);
	if(bytesRead)
	{
		alBufferData(buffer, AudioDevice::GetSingletonPtr()->GetChannelFormat(mChannels), data, bytesRead * sizeof(Int16), mSamplerate);
		alSourceQueueBuffers(mSource, 1, &buffer);
	}
	delete data;
}

void SoundStream::_ClearQueue()
{
	alSourceStop(mSource);
	int queued;
	alGetSourcei(mSource, AL_BUFFERS_QUEUED, &queued);
	while(queued--)
	{
		UInt32 buffer;
		alSourceUnqueueBuffers(mSource, 1, &buffer);
	}
	alSourcei(mSource, AL_BUFFER, 0);
}

void SoundStream::Run()
{
	Int32 state = 0;
	Int32 queuedBuffers = 0;
	Int32 buffersProccesed = 0;
	UInt32 buffer = 0;

	for(UInt32 x = 0; x < mNumberOfBuffers; x++)
		_UpdateAndQueueBuffer(mBuffer[x]);

	alSourcePlay(mSource);

	while(1)
	{
		if(mPlaying)
		{
			Sleep(THREAD_UPDATE);

			alGetSourcei(mSource, AL_BUFFERS_PROCESSED, &buffersProccesed);

			while(buffersProccesed--)
			{
				buffer = 0;
				alSourceUnqueueBuffers(mSource, 1, &buffer);

				_UpdateAndQueueBuffer(buffer);
			}

			alGetSourcei(mSource, AL_SOURCE_STATE, &state);
			if(state != AL_PLAYING)
			{
				alGetSourcei(mSource, AL_BUFFERS_QUEUED, &queuedBuffers);
				if(queuedBuffers)
				{
					alSourcePlay(mSource);
				}
				else
				{
					if(mLoop)
					{
						mFile->OpenRead(mFileName, &mChannels, &mSamplerate, &mSamples);

						_ClearQueue();

						for(UInt32 x = 0; x < mNumberOfBuffers; x++)
							_UpdateAndQueueBuffer(mBuffer[x]);

						alSourcePlay(mSource);
					}
					else
					{
						Stop();
						break;
					}
				}
			}
		}
	}
}

void SoundStream::SetLoop(bool loop)
{
	mLoop = loop;
}

bool SoundStream::GetLoop() const
{
	return mLoop;
}

void SoundStream::SetFile(ooge::SoundFile *file)
{
	mFile = file;
}

SoundFile *SoundStream::GetFile() const
{
	return mFile;
}

UInt32 SoundStream::GetNumberOfChannels() const
{
	return mChannels;
}

UInt32 SoundStream::GetBufferSize() const
{
	return mBufferSize;
}

UInt32 SoundStream::GetNumberOfSamples() const
{
	return mSamples;
}

UInt32 SoundStream::GetNumberOfBuffers() const
{
	return mNumberOfBuffers;
}

UInt32 SoundStream::GetSampleRate() const
{
	return mSamplerate;
}

UInt32 SoundStream::GetSource() const
{
	return mSource;
}

UInt32 *SoundStream::GetBufferList() const
{
	return mBuffer;
}

const std::string &SoundStream::GetFileName() const
{
	return mFileName;
}

Real SoundStream::GetDuration() const
{
	return mDuration;
}
