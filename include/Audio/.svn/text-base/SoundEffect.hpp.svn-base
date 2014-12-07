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

#ifndef _SOUNDEFFECT_HPP_
#define _SOUNDEFFECT_HPP_

#include <Config.hpp>
#include <Vector3.hpp>
#include <Vector2.hpp>

namespace ooge
{
	class OOGE_API SoundEffect
	{
	public:
		SoundEffect();
		~SoundEffect();

		void SetPosition(Real x, Real y);
		void SetPosition(const Vector2 &position);
		Vector2 GetPosition() const;

		void SetVelocity(Real x, Real y);
		void SetVelocity(const Vector2 &velocity);
		Vector2 GetVelocity() const;

		void SetDirection(Real x, Real y);
		void SetDirection(const Vector2 &direction);
		Vector2 GetDirection() const;

		void SetPitch(Real pitch);
		Real GetPitch() const;

		void SetMinimumDistance(Real distance);
		Real GetMinimumDistance() const;

		void SetRelativeToListener(bool relative);
		bool GetRelativeToListener() const;

		void SetTimeOffset(Real seconds);
		Real GetTimeOffset() const;

		void SetVolume(Real volume);
		Real GetVolume() const;

		void SetRolloff(Real rolloff);
		Real GetRollOff() const;

		void SetSource(UInt32 source);
		UInt32 GetSource() const;
	private:
		UInt32 mSourceHandle;
	};
}

#endif //_SOUNDEFFECT_HPP_