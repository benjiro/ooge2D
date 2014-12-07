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

#ifndef _CAMERA_HPP_
#define _CAMERA_HPP_

#include <Vector2.hpp>
#include <Vector3.hpp>
#include <Renderable.hpp>
#include <Singleton.hpp>
#include <Config.hpp>

namespace ooge
{
	class OOGE_API Camera : public Object, Singleton<Camera>
	{
	public:
		Camera();

		void SetPosition(Real x, Real y);
		void SetPosition(Real x, Real y, Real z);
		void SetPosition(const Vector2 &pos);
		void SetPosition(const Vector3 &pos);
		const Vector3 &GetPosition() const;

		void SetZ(Real z);
		Real GetZ() const;

		static void __stdcall ResizeCB(Int32 width, Int32 height);
		void Resize(Int32 width, Int32 height);

		UInt32 GetWindowHeight() const;
		UInt32 GetWindowWidth() const;

		virtual void Update(Real deltaT);

		static Camera &GetSingleton();
		static Camera *GetSingletonPtr();

	private:
		Vector3 mPosition;
		Vector3 mView;
		Vector3 mUp;

		Real mPerspective;
		UInt32 mWindowWidth;
		UInt32 mWindowHeight;
	};
}
#endif //_CAMERA_HPP_