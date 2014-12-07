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

#include <MouseListener.hpp>
#include <Common.hpp>

using namespace ooge;

MouseListener::MouseListener()
: mWheelPos(0)
{
}

MouseListener::~MouseListener()
{
}

void MouseListener::Update()
{
	mMouseList.clear();
}

void MouseListener::AddKey(MouseStatus ms)
{
	mMouseList.push_back(ms);
}

bool MouseListener::IsDown(Int32 key)
{
	if(mMouseList.empty())
		return false;

	for(UInt32 i = 0; i < mMouseList.size(); ++i)
	{
		if(mMouseList[i].button == key && mMouseList[i].state == GLFW_PRESS)
		{
			mMouseList.erase(mMouseList.begin() + i);
			return true;
		}
	}
	return false;
}

bool MouseListener::IsPressed(Int32 key)
{
	if(mMouseList.empty())
		return false;

	for(UInt32 i = 0; i < mMouseList.size(); ++i)
	{
		if(mMouseList[i].button == key && mMouseList[i].state == GLFW_RELEASE)
		{
			mMouseList.erase(mMouseList.begin() + i);
			return true;
		}
	}
	return false;
}

Int32 MouseListener::GetWheelPos()
{
	return mWheelPos;
}

void MouseListener::SetWheelPos(Int32 position)
{
	mWheelPos = position;
}

void MouseListener::SetPosition(Real x, Real y)
{
	mPosition.X = x;
	mPosition.Y = y;
}

void MouseListener::SetPosition(ooge::Vector2 &position)
{
	mPosition = position;
}

Vector2 &MouseListener::GetMousePosition()
{
	return mPosition;
}