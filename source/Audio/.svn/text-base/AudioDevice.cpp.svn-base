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

#include <AudioDevice.hpp>
#include <SoundListener.hpp>
#include <iostream>

using namespace ooge;

template<> AudioDevice *Singleton<AudioDevice>::ms_Singleton = 0;

AudioDevice::AudioDevice()
: mDevice(0), mContext(0)
{
	ALenum result;

	mDevice = alcOpenDevice(NULL);
	if((result = alGetError()) != AL_NO_ERROR)
	{
		std::cerr << "Failed to create Device. " << GetALError(result) << std::endl;
		return;
	}

	mContext = alcCreateContext(mDevice, NULL);
	if((result = alGetError()) != AL_NO_ERROR)
	{
		std::cerr << "Failed to create Context. " << GetALError(result) << std::endl;
		return;
	}
	alcMakeContextCurrent(mContext);

	SoundListener::SetListenerPosition(0.0f, 0.0f, 0.0f);
	SoundListener::SetListenerOrientation(0.0f, 0.0f, -1.0f);
	if((result = alGetError()) != AL_NO_ERROR)
	{
		std::cerr << "Failed to create Context. " << GetALError(result) << std::endl;
		return;
	}
}

AudioDevice::~AudioDevice()
{
	if(mContext)
		alcDestroyContext(mContext);
	if(mDevice)
		alcCloseDevice(mDevice);
}

ALCdevice *AudioDevice::GetDevice() const
{
	return mDevice;
}

ALenum AudioDevice::GetChannelFormat(UInt32 channels)
{
	switch(channels)
	{
	case 1: return AL_FORMAT_MONO16;
	case 2: return AL_FORMAT_STEREO16;
	case 4: return alGetEnumValue("AL_FORMAT_QUAD16");
	case 6: return alGetEnumValue("AL_FORMAT_51CHN16");
	case 7: return alGetEnumValue("AL_FORMAT_61CHN16");
	case 8: return alGetEnumValue("AL_FORMAT_71CHN16");
	default: return AL_FORMAT_MONO16;
	}
}

std::string AudioDevice::GetALError(ALenum err)
{
	switch(err)
	{
	case AL_NO_ERROR: return "AL_NO_ERROR";
	case AL_INVALID: return "AL_INVALID_NAME";
	case AL_INVALID_ENUM: return "AL_INVALID_ENUM";
	case AL_INVALID_VALUE: return "AL_INVALID_VALUE";
	case AL_INVALID_OPERATION: return "AL_INVALID_OPERATION";
	case AL_OUT_OF_MEMORY: return "AL_OUT_OF_MEMORY";
	default: return AL_NO_ERROR;
	};
}

std::string AudioDevice::GetALCError(ALenum err)
{
	switch(err)
	{
	case ALC_NO_ERROR: return "ALC_NO_ERROR";
	case ALC_INVALID_CONTEXT: return "ALC_INVALID_CONTEXT";
	case ALC_INVALID_ENUM: return "ALC_INVALID_ENUM";
	case ALC_INVALID_VALUE: return "ALC_INVALID_VALUE";
	case ALC_INVALID_DEVICE: return "ALC_INVALID_DEVICE";
	case ALC_OUT_OF_MEMORY: return "ALC_OUT_OF_MEMORY";
	default: return AL_NO_ERROR;
	};
}

AudioDevice &AudioDevice::GetSingleton()
{
	assert(ms_Singleton);
	return (*ms_Singleton);
}

AudioDevice *AudioDevice::GetSingletonPtr()
{
	return ms_Singleton;
}