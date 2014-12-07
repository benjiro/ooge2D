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

#include <SoundEffect.hpp>
#include <al.h>

using namespace ooge;

SoundEffect::SoundEffect()
{
}

SoundEffect::~SoundEffect()
{
}

void SoundEffect::SetPosition(Real x, Real y)
{
	alSource3f(mSourceHandle, AL_POSITION, x, y, 0);
}

void SoundEffect::SetPosition(const Vector2 &position)
{
	alSource3f(mSourceHandle, AL_POSITION, position.X, position.Y, 0);
}

Vector2 SoundEffect::GetPosition() const
{
	Vector3 position;
	alGetSource3f(mSourceHandle, AL_POSITION, &position.X, &position.Y, &position.Z);
	return Vector2(position.X, position.Y);
}


void SoundEffect::SetVelocity(Real x, Real y)
{
	alSource3f(mSourceHandle, AL_VELOCITY, x, y, 0);
}

void SoundEffect::SetVelocity(const Vector2 &velocity)
{
	alSource3f(mSourceHandle, AL_VELOCITY, velocity.X, velocity.Y, 0);
}

Vector2 SoundEffect::GetVelocity() const
{
	Vector3 vel;
	alGetSource3f(mSourceHandle, AL_VELOCITY, &vel.X, &vel.Y, &vel.Z);
	return Vector2(vel.X, vel.Y);
}

void SoundEffect::SetDirection(Real x, Real y)
{
	alSource3f(mSourceHandle, AL_DIRECTION, x, y, 0);
}

void SoundEffect::SetDirection(const Vector2 &direction)
{
	alSource3f(mSourceHandle, AL_DIRECTION, direction.X, direction.Y, 0);
}

Vector2 SoundEffect::GetDirection() const
{
	Vector3 dir;
	alGetSource3f(mSourceHandle, AL_DIRECTION, &dir.X, &dir.Y, &dir.Z);
	return Vector2(dir.X, dir.Y);
}

void SoundEffect::SetPitch(Real pitch)
{
	alSourcef(mSourceHandle, AL_PITCH, pitch);
}

Real SoundEffect::GetPitch() const
{
	Real pitch;
	alGetSourcef(mSourceHandle, AL_PITCH, &pitch);
	return pitch;
}

void SoundEffect::SetMinimumDistance(Real distance)
{
	alSourcef(mSourceHandle, AL_REFERENCE_DISTANCE, distance);
}

Real SoundEffect::GetMinimumDistance() const
{
	Real distance;
	alGetSourcef(mSourceHandle, AL_REFERENCE_DISTANCE, &distance);
	return distance;
}

void SoundEffect::SetRelativeToListener(bool relative)
{
	alSourcei(mSourceHandle, AL_SOURCE_RELATIVE, relative);
}

bool SoundEffect::GetRelativeToListener() const
{
	Int32 rel;
	alGetSourcei(mSourceHandle, AL_SOURCE_RELATIVE, &rel);
	return rel != 0;
}

void SoundEffect::SetTimeOffset(Real seconds)
{
	alSourcef(mSourceHandle, AL_SEC_OFFSET, seconds);
}

Real SoundEffect::GetTimeOffset() const
{
	Real offset;
	alGetSourcef(mSourceHandle, AL_SEC_OFFSET, &offset);
	return offset;
}

void SoundEffect::SetVolume(Real volume)
{
	alSourcef(mSourceHandle, AL_GAIN, volume * 0.01);
}

Real SoundEffect::GetVolume() const
{
	Real volume;
	alGetSourcef(mSourceHandle, AL_GAIN, &volume);
	return volume / 0.01;
}

void SoundEffect::SetRolloff(Real rolloff)
{
	alSourcef(mSourceHandle, AL_ROLLOFF_FACTOR, rolloff);
}

Real SoundEffect::GetRollOff() const
{
	Real roll;
	alGetSourcef(mSourceHandle, AL_ROLLOFF_FACTOR, &roll);
	return roll;
}

void SoundEffect::SetSource(UInt32 source)
{
	mSourceHandle = source;
}

UInt32 SoundEffect::GetSource() const
{
	return mSourceHandle;
}