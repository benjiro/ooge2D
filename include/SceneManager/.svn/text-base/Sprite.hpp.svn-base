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

#ifndef _SPRITE_HPP_
#define _SPRITE_HPP_

#include <Renderable.hpp>
#include <Config.hpp>

namespace ooge
{
	class Image;

	class OOGE_API Sprite : public Renderable
	{
	public:
		Sprite(Image *image, const std::string &name, const Vector2 &position = Vector2(0,0), const Vector2 &scale = Vector2(1.0f,1.0f));
		Sprite(const std::string &imageName, const std::string &name, const Vector2 &position = Vector2(0,0), const Vector2 &scale = Vector2(1.0f,1.0f));
		Sprite(const Sprite &copy);
		~Sprite();

		void SetImage(Image *image);
		Image *GetImage() const;

		void FlipX(bool flip);
		void FlipY(bool flip);
		const bool GetFlipX() const;
		const bool GetFlipY() const;

		virtual void Render();
		virtual void Update(Real deltaT);
	private:
		bool mIsFlippedX;
		bool mIsFlippedY;
		Image *mImage;
	};
}

#endif //_SPRITE_HPP_