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

#include <InputListener.hpp>
#include <InputManager.hpp>
#include <KeyboardListener.hpp>
#include <MouseListener.hpp>

using namespace ooge;

InputListener::InputListener()
{
}

InputListener::~InputListener()
{
}

void _stdcall InputListener::KeyboardInputCB(Int32 key, Int32 state)
{
	Key keyP;
	keyP.key = key;
	keyP.state = state;
	InputManager::GetSingletonPtr()->GetKeyboardListener()->AddKey(keyP);
}

void _stdcall InputListener::CharacterInputCB(Int32 key, Int32 state)
{
	if(key >= ' ' && key <= '}')
	{
		Key keyP;
		keyP.key = key;
		keyP.state = state;
		InputManager::GetSingletonPtr()->GetKeyboardListener()->AddKey(keyP);
	}
}

void _stdcall InputListener::MousePositionCB(Int32 x, Int32 y)
{
	InputManager::GetSingletonPtr()->GetMouseListener()->SetPosition(static_cast<Real>(x),static_cast<Real>(y));
}

void _stdcall InputListener::MouseButtonCB(Int32 button, Int32 state)
{
	MouseStatus ms;
	ms.button = button;
	ms.state = state;

	InputManager::GetSingletonPtr()->GetMouseListener()->AddKey(ms);
}

void _stdcall InputListener::MouseWheelCB(Int32 position)
{
	InputManager::GetSingletonPtr()->GetMouseListener()->SetWheelPos(position);
}