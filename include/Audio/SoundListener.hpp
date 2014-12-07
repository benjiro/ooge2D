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

#ifndef _SOUND_LISTENER_HPP_
#define _SOUND_LISTENER_HPP_

#include <Vector3.hpp>

namespace ooge
{
	class OOGE_API SoundListener
	{
	public:
		static void SetListenerPosition(Real x, Real y, Real z);
		static void SetListenerPosition(Vector3 &position);
		static Vector3 GetListenerPosition();

		static void SetListenerOrientation(Real x, Real y, Real z);
		static void SetListenerOrientation(Vector3 &orientation);
		static Vector3 GetListenerOrientation();

		static void SetListenerVelocity(Real x, Real y, Real z);
		static void SetListenerVelocity(Vector3 &velocity);
		static Vector3 GetListenerVelocity();

		static void SetListenerVolume(Real volume);
		static Real GetListenerVolume();
	};
}

#endif //_SOUND_LISTENER_HPP_