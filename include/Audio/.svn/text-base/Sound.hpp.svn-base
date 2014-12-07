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

#ifndef _SOUND_HPP_
#define _SOUND_HPP_

#include <SoundEffect.hpp>
#include <string>

namespace ooge
{
	enum SoundStatus
	{
		Playing,
		Stopped,
		Paused
	};

	class SoundBuffer;

	class OOGE_API Sound : public SoundEffect
	{
	public:
		Sound();
		Sound(const std::string &filename, const std::string &name, bool loop = false, Real volume = 100.0f, Real pitch = 1.0f , const Vector3 &position = Vector3(0,0,0), const Vector3 &velocity = Vector3(0,0,0));
		Sound(const Sound& sound);
		~Sound();

		void Play();
		void Stop();
		void Pause();

		void SetLooping(bool loop);
		bool GetLooping() const;

		SoundStatus GetStatus() const;

		void SetBuffer(SoundBuffer *buffer);
		SoundBuffer *GetBuffer() const;

		Real GetDuration() const;

		void SetName(const std::string &name);
		const std::string &GetName() const;
	private:
		UInt32 mSourceHandle;
		std::string mName;

		SoundBuffer *mBuffer;
	};
}

#endif _SOUND_HPP_