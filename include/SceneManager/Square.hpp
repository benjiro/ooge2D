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

#ifndef _SQUARE_HPP_
#define _SQUARE_HPP_

#include <Renderable.hpp>
#include <Config.hpp>

namespace ooge
{
	class OOGE_API Square : public Renderable
	{
	public:
		Square(Int32 width, Int32 height, const std::string &name, const Vector2 &position = Vector2(0,0), 
			const Colour &colour = Colour(255,255,255,255), const Vector2 &scale = Vector2(1,1));
		Square(const Square &copy);

		void SetWidth(Int32 width);
		Int32 GetWidth() const;

		void SetHeight(Int32 height);
		Int32 GetHeight() const;

		virtual void Render();
		virtual void Update(Real deltaT);
	private:
		Int32 mWidth;
		Int32 mHeight;
	};
}

#endif //_SQUARE_HPP_