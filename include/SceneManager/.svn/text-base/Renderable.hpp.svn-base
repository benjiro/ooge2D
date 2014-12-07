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

#ifndef _RENDERABLE_HPP_
#define _RENDERABLE_HPP_

#include <Vector2.hpp>
#include <Rect.hpp>
#include <Colour.hpp>
#include <Object.hpp>
#include <Config.hpp>

namespace ooge
{
	enum BlendType
	{
		Alpha = 	1,
		Add = 		2,
		Multiply = 	3,
		None = 		4
	};

	class OOGE_API Renderable : public Object
	{
	public:
		Renderable(const std::string &name, const Vector2 &position = Vector2(0.0f,0.0f), const Vector2 &scale = Vector2(1.0f,1.0f) , const Real rotation = 0, const Colour &colour = Colour(255,255,255,255));
		virtual ~Renderable();

		void SetOrder(UInt32 position);
		UInt32 GetOrder() const;

		void SetScale(Real x, Real y);
		void SetScale(const Vector2 &scale);
		const Vector2 &GetScale() const;

		void SetPosition(Real x, Real y);
		void SetPosition(const Vector2 &position);
		const Vector2 &GetPosition() const;

		void SetRotation(Real angle);
		Real GetRotation() const;

		void Move(Vector2 move);
		void Move(Real x, Real y);

		void SetColour(Real r, Real g, Real b, Real a = 255.0f);
		void SetColour(const Colour &colour);
		const Colour &GetColour() const;

		void SetAlpha(Real a);
		Real GetAlpha() const;

		void SetName(const std::string &name);
		const std::string &GetName() const;

		void SetRect(const Rect &rect);
		const Rect &GetRect() const;

		void SetBlendMode(const BlendType type);
		BlendType GetBlendMode();

		void SetDirty(bool isDirty);
		bool GetDirty() const;

		void SetNeedOrderUpdate(bool update);
		bool GetNeedOrderUpdate() const;

		virtual void Render() = 0;
		virtual void Update(Real delta) = 0;
	private:
		Vector2 mPosition;
		Vector2 mScale;
		Real mRotation;
		UInt32 mLayer;

		BlendType mType;

		Rect mRect;
		Colour mColour;

		std::string mName;

		bool mIsDirty;
		bool mIsOrderUpdate;
	};
}

#endif //_RENDERABLE_HPP_