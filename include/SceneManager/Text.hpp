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

#ifndef _TEXT_HPP_
#define _TEXT_HPP_

#include <Renderable.hpp>
#include <Config.hpp>

namespace ooge
{
	class Font;

	enum FontStyle
	{
		Bold  = (1<<2),
		Italic = (1<<4),
		Underline = (1<<8)
	};

	class OOGE_API Text : public Renderable
	{
	public:
		Text(Font *font, const std::string &text, const Vector2 &position = Vector2(0,0), const Vector2 &scale = Vector2(1,1));
		Text(Text &text);

		void SetFontStyle(Int32 style);
		const Int32 GetFontStyle() const;

		void SetText(const std::string &text);
		std::string &GetText();

		void SetFont(Font &font);
		Font *GetFont();

		virtual void Render();
		virtual void Update(Real deltaT);
	private:
		std::string mText;
		Int32 mStyle;
		Font *mFont;
	};
}

#endif //_TEXT_HPP_