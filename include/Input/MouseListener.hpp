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

#ifndef _MOUSELISTENER_HPP_
#define _MOUSELISTENER_HPP_

#include <InputListener.hpp>
#include <Vector2.hpp>
#include <Config.hpp>
#include <vector>

namespace ooge
{
	//! Struct MouseStatus
	/*! This structure reprosents the current state of a mouse*/
	struct MouseStatus
	{
		Int32 button;
		Int32 state;
	};

	//! Mouse Listener Class
	/*! This class is drived from InputListener, it provides
	 layout for processing mouse functions & testing mouse states*/
	class OOGE_API MouseListener : public InputListener
	{
	public:
		//! Default Constructor
		MouseListener();
		//! Destructor
		~MouseListener();

		
		//! Virtual Function Update
		/*! This function clears mouse vector. This will be called each frame
		 from InputManager */
		virtual void Update();

		//! Function AddKey
		/*! This function adds a key to the vector of active mouse states. DON'T CALL THIS FUNCTION Int32ERNAL */
		void AddKey(MouseStatus ms);

		//! Function IsDown
		/*! Call this function to test if a mouse button has been pressed and is down in current frame*/
		bool IsDown(Int32 key);
		
		//! Function IsPressed
		/*! Call this function to test if a mouse button has been pressed in current frame*/
		bool IsPressed(Int32 key);

		//! Overloaded Function SetPosition <Real,Real>
		/*! This function sets the position of the mouse. DON'T CALL THIS FUNCTION Int32ERNAL */
		void SetPosition(Real x, Real y);
		//! Overloaded Function SetPosition <Vector2T<Int32>
		/*! This function sets the position of the mouse. DON'T CALL THIS FUNCTION Int32ERNAL */
		void SetPosition(Vector2 &addVector);
		
		//! Function GetMousePosition
		/*! This returns a refernce to the current position of the mouse. */
		Vector2 &GetMousePosition();

		//! Function SetWheelPos
		/*! This function sets the current position of the mouse wheel. DON'T CALL THIS FUNCTIN Int32ERNAL */
		void SetWheelPos(Int32 position);
		
		//! Function GetWheelPos
		/*! This function returns a Int32 of the current mouse position*/
		Int32 GetWheelPos();

		//debug function
		std::vector<MouseStatus> &GetKeyList() { return mMouseList; }
	private:
		std::vector<MouseStatus> mMouseList; /*!< A vector that holds current states of the mouse, cleared every frame*/
		Vector2 mPosition; /*< Holds current position of the mouse. Updated ever mouse movement*/
		Int32 mWheelPos; /*< Holds current position of mouse wheel. Updated ever wheel movement */
	};
}

#endif //_MOUSELISTENER_HPP_