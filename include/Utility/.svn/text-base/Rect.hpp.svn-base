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

#ifndef _RECT_HPP_
#define _RECT_HPP_

#include <Config.hpp>
#include <Common.hpp>
#include <Vector2.hpp>

namespace ooge
{
	//! Rectangle Class
	/*! Basic Bounding Box implementation used for collision detection
	4-----3
	|	  |
	|     |
	1-----2
	*/
	template<typename T>
	class OOGE_API RectT
	{
	public:
		//! Variables of RectT
		/*! These variables make up the bounding box*/
		T Left;		/*!< Template value Left. */
		T Top;		/*!< Template value Top. */
		T Right;	/*!< Template value Right*/
		T Bottom;	/*!< Template value Bottom*/

		//! Default Constructor
		RectT() : 	
			Left(0),
			Top(0),
			Right(0),
			Bottom(0)
		{
		}

		//! Overloaded Constructor
		RectT(const T left, const T top, const T right, const T bottom) :
			Left(left),
			Top(top),
			Right(right),
			Bottom(bottom)
		{
		}

		//! Function GetWidth
		/*! This function retrieves the width of the Bounding Box */
		inline T GetWidth() const 
		{ 
			return Right - Left; 
		}

		//! Function GetHeight
		/*! This function retrieves the height of the Bounding Box */
		inline T GetHeight() const 
		{ 
			return Bottom - Top; 
		}

		//! Function Contains
		/*! This function checks to see if the given points are within the Bounding Box */
		bool Contains(const T x, const T y) const
		{
			return (x >= Left) && (x <= Right) && (y >= Top) && (y <= Bottom);
		}

		//! Function Int32ersect
		/*! This function checks to see if the given bouding box Intersects */
		bool Intersect(const RectT<T> &rect) const
		{
			return !(Left > rect.Right || Right < rect.Left || Top > rect.Bottom || Bottom < rect.Top);
		}

		//! Function RenderRect
		/*! This Function sends a draw call of the bounding box to GL */
		void RenderRect() const
		{
			glBegin(GL_LINE_LOOP);
			{
				glVertex2f(Bottom, Left);
				glVertex2f(Top, Left);
				glVertex2f(Top, Right);
				glVertex2f(Bottom, Right);
			}
			glEnd();
		}

		inline friend std::ostream &operator<<(std::ostream &o, const RectT &v)
		{
			o << v.Left << " " << v.Top << " " << v.Right << " " << v.Bottom;
			return o;
		}
	};

	//! Common Used types
	typedef RectT<Real> Rect;
	typedef RectT<Int32> RectInt32;
}

#endif //_RECT_HPP_