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

#include <Circle.hpp>
#include <Common.hpp>

using namespace ooge;

Circle::Circle(Real radius, const std::string &name, const Vector2 &position, const Colour &colour, const Vector2 &scale)
: mRadius(radius),
Renderable(name, position, scale, 0, colour)
{
}

Circle::Circle(const Circle &copy)
: mRadius(copy.GetRadius()),
Renderable(copy.GetName(), copy.GetPosition(), copy.GetScale(), copy.GetRotation(), copy.GetColour())
{
}

void Circle::SetRadius(Real radius)
{
	mRadius = radius;
}

const Real Circle::GetRadius() const
{
	return mRadius;
}

void Circle::Render()
{
	glLoadIdentity();
	glTranslatef(GetPosition().X, GetPosition().Y, 0.0f);
	glRotatef(GetRotation(), 0,0, 1);
	glScalef(GetScale().X, GetScale().Y, 1.0f);

	const Real radius = mRadius/2.0f;
	const Real deg2Rad = math::Pi/180;

	glBegin(GL_LINE_LOOP);
	for(int i = 0; i <= 360; ++i)
	{
		float degInRad = i * deg2Rad;
		glVertex2f(math::Cos(degInRad)*radius, math::Sin(degInRad)*radius);
	} 
	glEnd();
}

void Circle::Update(Real deltaT)
{
	SetRect(Rect(GetPosition().Y - (mRadius/2), GetPosition().X - (mRadius/2), 
		GetPosition().Y + (mRadius/2), GetPosition().X + (mRadius/2)));
}