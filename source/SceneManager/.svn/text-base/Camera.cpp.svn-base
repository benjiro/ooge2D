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

#include <Camera.hpp>
#include <Common.hpp>

using namespace ooge;

template<> Camera *Singleton<Camera>::ms_Singleton = 0;

Camera::Camera()
	: mPosition(0.0f, 0.0f, 1.0f), mView(0.0f, 0.0f, -1.0f), mUp(0.0f, 1.0f, 0.0f),
				 mWindowHeight(0), mWindowWidth(0), mPerspective(90.0f)
{
}

void Camera::SetPosition(Real x, Real y)
{
	mPosition.SetX(x);
	mPosition.SetY(y);
}

void Camera::SetPosition(Real x, Real y, Real z)
{
	mPosition.Set(x, y, z);
}

void Camera::SetPosition(const Vector2 &pos)
{
	mPosition.SetX(pos.X);
	mPosition.SetY(pos.Y);
}

void Camera::SetPosition(const Vector3 &pos)
{
	mPosition = pos;
}

const Vector3 &Camera::GetPosition() const
{
	return mPosition;
}

void Camera::SetZ(Real z)
{
	mPosition.SetZ(z);
}

Real Camera::GetZ() const
{
	return mPosition.Z;
}

void __stdcall Camera::ResizeCB(Int32 width, Int32 height)
{
	Camera::GetSingletonPtr()->Resize(width, height);
}

void Camera::Resize(Int32 width, Int32 height)
{
	mWindowHeight = static_cast<UInt32>(height);
	mWindowWidth = static_cast<UInt32>(width);

	glViewport(0,0, mWindowWidth, mWindowHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, mWindowWidth, mWindowHeight, 0, 0, 100);
	glMatrixMode(GL_MODELVIEW);
}

UInt32 Camera::GetWindowHeight() const
{
	return mWindowHeight;
}

UInt32 Camera::GetWindowWidth() const
{
	return mWindowWidth;
}

void Camera::Update(Real deltaT)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(mPosition.X, mPosition.Y, mPosition.Z, 
		mPosition.X + mView.X, mPosition.Y + mView.Y, mPosition.Z + mView.Z, 
		mUp.X, mUp.Y, mUp.Z); 
}

Camera &Camera::GetSingleton()
{
	assert(ms_Singleton);
	return(*ms_Singleton);
}

Camera *Camera::GetSingletonPtr()
{
	return ms_Singleton;
}


