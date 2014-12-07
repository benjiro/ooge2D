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

#ifndef _INPUTLISTENER_HPP_
#define _INPUTLISTENER_HPP_

#include <Config.hpp>

namespace ooge
{
	//! Input Listener Base Case
	/*! This class represents the base class which input will be based off */
	class OOGE_API InputListener
	{
	public:
		//! Default Constructor
		InputListener();
		//! Destructor
		virtual ~InputListener();

		//! Pure virtual Update Function
		/*! This function will be called every frame */
		virtual void Update() = 0;
		
		//! Static Function Keyboard Input CallBack
		/*! This function will retrieve all Keyboard input */
		void static _stdcall KeyboardInputCB(Int32 key, Int32 state);
		
		//! Static Function Character Input CallBack
		/*! This function will retrieves Characters from Keyboard input */
		void static _stdcall CharacterInputCB(Int32 key, Int32 state);
		
		//! Static Function Mouse Position CallBack
		/*! This function will retrieve the current mouse Position */
		void static _stdcall MousePositionCB(Int32 x, Int32 y);
		
		//! Static Function Mouse Button CallBack
		/*! This function will retrieve status of mouse input */
		void static _stdcall MouseButtonCB(Int32 button, Int32 state);
		
		//! Static Function Mouse Wheel CallBack
		/*! This function will retrieve the current position of mouse wheel */
		void static _stdcall MouseWheelCB(Int32 position);
	};
}

#endif //_INPUTLISTENER_HPP_