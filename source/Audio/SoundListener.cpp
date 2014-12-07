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

#include <SoundListener.hpp>
#include <al.h>
#include <alc.h>

using namespace ooge;

void SoundListener::SetListenerPosition(Real x, Real y, Real z)
{
	alListener3f(AL_POSITION, x, y, z);
}

void SoundListener::SetListenerPosition(Vector3 &position)
{
	SetListenerPosition(position.X, position.Y, position.Z);
	std::cout << alGetError() << std::endl;
}

Vector3 SoundListener::GetListenerPosition()
{
	Vector3 pos;
	alGetListener3f(AL_POSITION, &pos.X, &pos.Y, &pos.X);
	return pos;
}

void SoundListener::SetListenerOrientation(Real x, Real y, Real z)
{
	Real vec[6] = {x, y, z, 0.0f, 1.0f, 0.0f};
	alListenerfv(AL_ORIENTATION, vec);
}

void SoundListener::SetListenerOrientation(Vector3 &orientation)
{
	SetListenerOrientation(orientation.X, orientation.Y, orientation.Z);
}

Vector3 SoundListener::GetListenerOrientation()
{
	Real vec[6];
	alGetListenerfv(AL_ORIENTATION, vec);
	return Vector3(vec[0], vec[1], vec[2]);
}

void SoundListener::SetListenerVelocity(Real x, Real y, Real z)
{
	alListener3f(AL_VELOCITY, x, y, z);
}

void SoundListener::SetListenerVelocity(Vector3 &velocity)
{
	SetListenerVelocity(velocity.X, velocity.Y, velocity.Z);
}

Vector3 SoundListener::GetListenerVelocity()
{
	Vector3 vel;
	alGetListener3f(AL_VELOCITY, &vel.X, &vel.Y, &vel.Z);
	return vel;
}

void SoundListener::SetListenerVolume(Real volume)
{
	//wrap volume from 0 to 100;
	alListenerf(AL_GAIN, volume * 0.01);
}

Real SoundListener::GetListenerVolume()
{
	Real volume;
	alGetListenerf(AL_GAIN, &volume);
	return volume;
}
