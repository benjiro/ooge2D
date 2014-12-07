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

#include <Sound.hpp>
#include <SoundBuffer.hpp>
#include <AudioDevice.hpp>

using namespace ooge;

Sound::Sound()
: mBuffer(0),
SoundEffect()
{
	alGenSources(1, &mSourceHandle);
	SetSource(mSourceHandle);
}

Sound::Sound(const std::string &filename, const std::string &name, bool loop, Real volume, Real pitch, const Vector3 &position, const Vector3 &velocity)
: mBuffer(new SoundBuffer(filename)), mName(name), mSourceHandle(0),
SoundEffect()
{
	alGenSources(1, &mSourceHandle);
	SetSource(mSourceHandle);

	alSourcei(mSourceHandle, AL_BUFFER, mBuffer->GetBufferHandle());
	alSourcef(mSourceHandle, AL_PITCH, 1.0f);
	alSourcef(mSourceHandle, AL_GAIN, volume * 0.01);
	alSource3f(mSourceHandle, AL_POSITION, position.X, position.Y, position.Z);
	alSourcei(mSourceHandle, AL_LOOPING, loop);

	ALenum result;
	if((result = alGetError()) != AL_NO_ERROR)
	{
		std::cerr << "Failed to create sound. " << AudioDevice::GetALError(result) << std::endl;
	}
}

Sound::Sound(const Sound& sound)
: mName(sound.GetName()), mSourceHandle(sound.GetSource()),
SoundEffect()
{
	SetSource(sound.GetSource());
	SetBuffer(sound.GetBuffer());
	alSourcef(mSourceHandle, AL_PITCH, sound.GetPitch());
	alSourcef(mSourceHandle, AL_GAIN, sound.GetVolume() * 0.01);
	alSource3f(mSourceHandle, AL_POSITION, sound.GetPosition().X, sound.GetPosition().Y, 0);
	alSource3f(mSourceHandle, AL_VELOCITY, sound.GetVelocity().X, sound.GetVelocity().Y, 0);
	alSourcei(mSourceHandle, AL_LOOPING, sound.GetLooping());

	ALenum result;
	if((result = alGetError()) != AL_NO_ERROR)
	{
		std::cerr << "Failed to create sound. " << AudioDevice::GetALError(result) << std::endl;
	}
}

Sound::~Sound()
{
	if(mBuffer)
	{
		Stop();
		alDeleteSources(1, &mSourceHandle);
		delete mBuffer;
	}
}

SoundStatus Sound::GetStatus() const
{
	Int32 status;
	alGetSourcei(mSourceHandle, AL_SOURCE_STATE, &status);

	switch(status)
	{
		case AL_PLAYING: return Playing;
		case AL_STOPPED: return Stopped;
		case AL_PAUSED: return Paused;
		default: return Stopped;
	};
}

void Sound::Play()
{
	alSourcePlay(mSourceHandle);
		ALenum result;
	if((result = alGetError()) != AL_NO_ERROR)
	{
		std::cerr <<result << std::endl;
	}
}

void Sound::Stop()
{
	alSourceStop(mSourceHandle);
}

void Sound::Pause()
{
	alSourcePause(mSourceHandle);
}

void Sound::SetLooping(bool loop)
{
	alSourcei(mSourceHandle, AL_LOOPING, loop);
}

bool Sound::GetLooping() const
{
	Int32 looping;
	alGetSourcei(mSourceHandle, AL_LOOPING, &looping);
	return looping != 0;
}

void Sound::SetBuffer(SoundBuffer *buffer)
{
	if(buffer)
	{
		mBuffer = buffer;
		alSourcei(mSourceHandle, AL_BUFFER, mBuffer->GetBufferHandle());
	}
	else
		std::cerr << "Failed to set sound buffer. Is it a vaild buffer??" << std::endl;
}

SoundBuffer *Sound::GetBuffer() const
{
	return mBuffer;
}

void Sound::SetName(const std::string &name)
{
	mName = name;
}

const std::string &Sound::GetName() const
{
	return mName;
}

Real Sound::GetDuration() const
{
	return mBuffer ? mBuffer->GetDuration() : 0.0f;
}
