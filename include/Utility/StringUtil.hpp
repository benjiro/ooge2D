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

#ifndef _STRING_UTIL_HPP_
#define _STRING_UTIL_HPP_

#include <Config.hpp>
#include <Vector2.hpp>
#include <string>
#include <vector>

#define StringToWString STWS

namespace ooge
{
	class OOGE_API StringUtil
	{
	public:
		static Int32 ParseStringToInt32(const std::string &str);
		static Real ParseStringToReal(const std::string &str);
		static bool	ParseStringToBool(const std::string &str);
		static ooge::Vector2 ParseStringToVec2(const std::string &str);

		static std::string ParseCharToString(Int8 value);
		static std::string ParseInt32ToString(Int32 value);
		static std::string ParseRealToString(Real value);
		static std::string ParseBoolToString(bool value);
		static std::string ParseVec2toString(const ooge::Vector2 &vec2);

		static void ToUpper(std::string &str);
		static void ToLower(std::string &str);
		static void Trim(std::string &str);
		static std::vector<std::string> Tokenize(const std::string &str, const std::string &delimitor);

		static std::wstring StringToWString(const std::string &str);
		static std::string StringUtil::WStringToString(const std::wstring &wString);
	};
}

#endif //_STRING_UTIL_HPP_