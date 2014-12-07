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

#include <SoundBuffer.hpp>
#include <AudioDevice.hpp>
#include <SoundFile.hpp>
#include <iostream>

using namespace ooge;

SoundBuffer::SoundBuffer(const std::string &filename)
: mDuration(0.0f), mBufferHandle(0)
{
	if(!LoadFromFile(filename))
	{
		std::cerr << "Failed to load sound file " << filename << std::endl;
		return;
	}
}

SoundBuffer::~SoundBuffer()
{
	alDeleteBuffers(1, &mBufferHandle);
}

bool SoundBuffer::LoadFromFile(const std::string &filename)
{
	UInt32 samples;
	UInt32 channels;
	UInt32 samplerate;

	SoundFile *file = new SoundFile();

	if(file->OpenRead(filename, &channels, &samplerate, &samples))
	{
		mBuffer.clear();
		mBuffer.resize(samples);
		if((file->Read(&mBuffer[0], mBuffer.size())) != 0)
		{
			_CreateBuffer(samplerate, channels);
			delete file;
			return true;
		}
	}

	delete file;
	return false;
}

bool SoundBuffer::LoadFromMemory(UInt8 *data, std::size_t sizeOfBytes)
{
	UInt32 samples;
	UInt32 channels;
	UInt32 samplerate;

	SoundFile *file = new SoundFile();

	if(file->OpenRead(data, sizeOfBytes, &channels, &samplerate, &samples))
	{
		mBuffer.clear();
		mBuffer.resize(samples);
		if((file->Read(&mBuffer[0], mBuffer.size())) != 0)
		{
			_CreateBuffer(samplerate, channels);
			delete file;
			return true;
		}
	}

	delete file;
	return false;
}

bool SoundBuffer::SaveToDisk(const std::string &filename)
{
	SoundFile *file = new SoundFile();

	if(file->OpenWrite(filename, GetNumberOfChannels(), GetSampleRate()))
	{
		if((file->Write(&mBuffer[0], mBuffer.size())) != 0)
		{
			delete file;
			return true;
		}
	}

	return false;
}

void SoundBuffer::_CreateBuffer(UInt32 samplesRate, UInt32 channels)
{
	alGenBuffers(1, &mBufferHandle);
	ALenum format = AudioDevice::GetSingletonPtr()->GetChannelFormat(channels);
	if(format == 0)
	{
		std::cerr << "Unsupport number of channels. " << channels << std::endl;
		return;
	}

	ALsizei size = mBuffer.size() * sizeof(Int16);
	alBufferData(mBufferHandle, format, &mBuffer[0], size, samplesRate);
	mDuration = (static_cast<Real>(mBuffer.size()) / samplesRate / channels);
}

UInt32 SoundBuffer::GetNumberOfChannels() const
{
	ALint value;
	alGetBufferi(mBufferHandle, AL_CHANNELS, &value);
	return value;
}

UInt32 SoundBuffer::GetSampleRate() const
{
	ALint value;
	alGetBufferi(mBufferHandle, AL_FREQUENCY, &value);
	return value;
}

UInt32 SoundBuffer::GetBufferHandle() const
{
	return mBufferHandle;
}

std::size_t SoundBuffer::GetNumberOfSamples() const
{
	return mBuffer.size();
}

Real SoundBuffer::GetDuration() const
{
	return mDuration;
}

const Int16 *SoundBuffer::GetBuffer() const
{
	return &mBuffer[0];
}
