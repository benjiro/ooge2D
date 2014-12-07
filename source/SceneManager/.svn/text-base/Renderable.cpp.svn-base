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

#include <Renderable.hpp>

using namespace ooge;

Renderable::Renderable(const std::string &name, const Vector2 &position, const Vector2 &scale, const Real angle, const Colour &colour)
: mType(Alpha), mIsDirty(true), mPosition(position), mScale(scale), mRotation(angle), mColour(colour), mName(name), mLayer(0), mIsOrderUpdate(false)
{
}

Renderable::~Renderable()
{
}

void Renderable::SetOrder(UInt32 position)
{
	mLayer = position;
	mIsOrderUpdate = true;
}

UInt32 Renderable::GetOrder() const
{
	return mLayer;
}

void Renderable::SetScale(Real x, Real y)
{
	mScale.Set(x,y);
	mIsDirty = true;
}

void Renderable::SetScale(const Vector2 &scale)
{
	mScale = scale;
}

const Vector2 &Renderable::GetScale() const
{
	return mScale;
}

void Renderable::SetPosition(Real x, Real y)
{
	mPosition.Set(x,y);
	mIsDirty = true;
}

void Renderable::SetPosition(const Vector2 &position)
{
	mPosition = position;
	mIsDirty = true;
}

const Vector2 &Renderable::GetPosition() const
{
	return mPosition;
}

void Renderable::Move(Vector2 move)
{
	mPosition += move;
	mIsDirty = true;
}

void Renderable::Move(Real x, Real y)
{
	mPosition.X += x;
	mPosition.Y += y;
	mIsDirty = true;
}

void Renderable::SetRotation(Real angle)
{
	mRotation = angle;
	mIsDirty = true;
}

Real Renderable::GetRotation() const
{
	return mRotation;
}

void Renderable::SetColour(Real r, Real g, Real b, Real a)
{
	mColour = Colour(r,g,b,a);
}

void Renderable::SetColour(const Colour &colour)
{
	mColour = colour;
}

const Colour &Renderable::GetColour() const
{
	return mColour;
}

void Renderable::SetAlpha(Real a)
{
	mColour.A = a;
}

Real Renderable::GetAlpha() const
{
	return mColour.A;
}

void Renderable::SetName(const std::string &name)
{
	mName = name;
}

const std::string &Renderable::GetName() const
{
	return mName;
}

void Renderable::SetRect(const Rect &rect)
{
	mRect = rect;
}

const Rect &Renderable::GetRect() const
{
	return mRect;
}

void Renderable::SetBlendMode(const BlendType type)
{
	mType = type;
}

BlendType Renderable::GetBlendMode()
{
	return mType;
}

void Renderable::SetDirty(bool isDirty)
{
	mIsDirty = isDirty;
}

bool Renderable::GetDirty() const
{
	return mIsDirty;
}

bool Renderable::GetNeedOrderUpdate() const
{
	return mIsOrderUpdate;
}

void Renderable::SetNeedOrderUpdate(bool update)
{
	mIsOrderUpdate = update;
}