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

#ifndef _INPUTKEYS_HPP_
#define _INPUTKEYS_HPP_

namespace ooge
{
	enum Keys
	{
		KEY_SPACE = 32,
		KEY_ESC = 257,
		KEY_F1 = 258,
		KEY_F2 = 259,
		KEY_F3 = 260,
		KEY_F4 = 261,
		KEY_F5 = 262,
		KEY_F6 = 263,
		KEY_F7 = 264,
		KEY_F8 = 265,
		KEY_F9 = 266,
		KEY_F10 = 267,
		KEY_F11 = 268,
		KEY_F12 = 269,
		KEY_F13 = 270,
		KEY_F14 = 271,
		KEY_F15 = 272,
		KEY_F16 = 273,
		KEY_F17 = 274,
		KEY_F18 = 275,
		KEY_F19 = 276,
		KEY_F20 = 277,
		KEY_F21 = 278,
		KEY_F22 = 279,
		KEY_F23 = 280,
		KEY_F24 = 281,
		KEY_F25 = 282,
		KEY_UP = 283,
		KEY_DOWN = 284,
		KEY_LEFT = 285,
		KEY_RIGHT = 286,
		KEY_LSHIFT = 287,
		KEY_RSHIFT = 288,
		KEY_LCTRL = 289,
		KEY_RCTRL = 290,
		KEY_LALT = 291,
		KEY_RALT = 292,
		KEY_TAB = 293,
		KEY_ENTER = 294,
		KEY_BACKSPACE = 295,
		KEY_INSERT = 296,
		KEY_DEL = 297,
		KEY_PAGEUP = 298,
		KEY_PAGEDOWN = 299,
		KEY_HOME = 300,
		KEY_END = 301,
		KEY_KP_0 = 302,
		KEY_KP_1 = 303,
		KEY_KP_2 = 304,
		KEY_KP_3 = 305,
		KEY_KP_4 = 306,
		KEY_KP_5 = 307,
		KEY_KP_6 = 308,
		KEY_KP_7 = 309,
		KEY_KP_8 = 310,
		KEY_KP_9 = 311,
		KEY_KP_DIVIDE = 312,
		KEY_KP_MULTIPLY = 313,
		KEY_KP_SUBTRACT = 314,
		KEY_KP_ADD = 315,
		KEY_KP_DECIMAL = 316,
		KEY_KP_EQUAL = 317,
		KEY_KP_ENTER = 318,
		KEY_LAST = KEY_KP_ENTER
	};

	enum Mouse
	{
		BUTTON_LEFT = 0,
		BUTTON_RIGHT = 1,
		BUTTON_MIDDLE = 2,
		BUTTON_4 = 3,
		BUTTON_5 = 4,
		BUTTON_6 = 5,
		BUTTON_7 = 6,
		BUTTON_8 = 7,
		BUTTON_LAST = BUTTON_8
	};

	enum Control
	{
		CONTROL_DPAD_UP = 0x0001,
		CONTROL_DPAD_DOWN = 0x0002,
		CONTROL_DPAD_LEFT = 0x0004,
		CONTROL_DPAD_RIGHT = 0x0008,
		CONTROL_DPAD_START = 0x0010,
		CONTROL_DPAD_BACK = 0x0020,
		CONTROL_DPAD_LEFT_THUMB = 0x0040,
		CONTROL_DPAD_RIGHT_THUMB = 0x0080,
		CONTROL_DPAD_LEFT_SHOULDER = 0x0100,
		CONTROL_DPAD_RIGHT_SHOULDER = 0x0200,
		CONTROL_DPAD_A = 0x1000,
		CONTROL_DPAD_B = 0x2000,
		CONTROL_DPAD_X = 0x4000,
		CONTROL_DPAD_Y = 0x8000
	};
}

#endif //_INPUTKEYS_HPP_