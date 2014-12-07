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

#include <Square.hpp>
#include <Common.hpp>

using namespace ooge;

Square::Square(Int32 width, Int32 height, const std::string &name, const Vector2 &position, const Colour &colour, const Vector2 &scale)
: mWidth(width), mHeight(height),
Renderable(name, position, scale, 0, colour)
{
}

Square::Square(const Square &copy)
: mWidth(copy.GetWidth()), mHeight(copy.GetHeight()),
Renderable(copy.GetName(), copy.GetPosition(), copy.GetScale(), copy.GetRotation(), copy.GetColour())
{
}

void Square::SetWidth(Int32 width)
{
	mWidth = width;
}

Int32 Square::GetWidth() const
{
	return mWidth;
}

void Square::SetHeight(Int32 height)
{
	mHeight = height;
}

Int32 Square::GetHeight() const
{
	return mHeight;
}

void Square::Render()
{
	glLoadIdentity();
	glTranslatef(GetPosition().X, GetPosition().Y, 0.0f);
	glRotatef(GetRotation(), 0, 0, 1);
	glScalef(GetScale().X, GetScale().Y, 1.0f);

	Int32 width = mWidth / 2;
	Int32 height = mHeight / 2;


	glBegin(GL_QUADS);

	glVertex2i(width, -height);
	glVertex2i(-width, -height);
	glVertex2i(-width, height);
	glVertex2i(width, height);

	glEnd();
}

void Square::Update(Real deltaT)
{
	SetRect(Rect(GetPosition().Y - (mHeight/2), GetPosition().X - (mWidth/2), 
		GetPosition().Y + (mHeight/2), GetPosition().X + (mWidth/2)));
}