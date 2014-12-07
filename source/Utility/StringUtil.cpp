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

#include <StringUtil.hpp>
#include <Common.hpp>

using namespace ooge;

Int32 StringUtil::ParseStringToInt32(const std::string &str)
{
	Int32 value = 0;
	std::stringstream ss(str);

	ss >> value;

	return value;
}

Real StringUtil::ParseStringToReal(const std::string &str)
{
	Real value = 0.0f;
	std::stringstream ss(str);

	ss >> value;

	return value;
}

bool StringUtil::ParseStringToBool(const std::string &str)
{
	bool value = 0;

	if(str == std::string(0))
		value = false;
	else
		value = true;

	return value;
}

ooge::Vector2 StringUtil::ParseStringToVec2(const std::string &str)
{
	ooge::Vector2 vector;
	std::vector<std::string> list = Tokenize(str,std::string("\t\n\r"));

	if(list.size() > 0)
		vector.X = ParseStringToReal(list[0]);
	else
		vector.Y = ParseStringToReal(list[1]);

	return vector;
}

std::string StringUtil::ParseInt32ToString(Int32 value)
{
	std::stringstream ss;

	ss << value;

	return std::string(ss.str());
}

std::string StringUtil::ParseRealToString(Real value)
{
	std::stringstream ss;

	ss << value;

	return std::string(ss.str());
}

std::string StringUtil::ParseBoolToString(bool value)
{
	if(value == true)
		return std::string("true");
	else
		return std::string("false");		
}

std::string StringUtil::ParseVec2toString(const Vector2 &vec2)
{
	std::stringstream ss;

	ss << vec2;

	return std::string(ss.str());
}

std::string StringUtil::ParseCharToString(Int8 value)
{
	std::stringstream ss;
	
	ss << value;

	return std::string(ss.str());
}

void StringUtil::ToUpper(std::string &str)
{
	std::transform(str.begin(), str.end(), str.begin(), toupper);
}

void StringUtil::ToLower(std::string &str)
{
	std::transform(str.begin(), str.end(), str.begin(), tolower);
}

void StringUtil::Trim(std::string &str)
{
	std::string::size_type pos = str.find_last_not_of(' ');

	if(pos != std::string::npos) 
	{
		str.erase(pos + 1);
		pos = str.find_first_not_of(' ');
		if(pos != std::string::npos) 
			str.erase(0, pos);
	}
	else 
		str.erase(str.begin(), str.end());

}

std::wstring StringUtil::StringToWString(const std::string &str)
{
	std::wstring wString;
	wString.assign(str.begin(),str.end());
	return wString;
}

std::string StringUtil::WStringToString(const std::wstring &wString)
{
	std::string str;
	str.assign(wString.begin(),wString.end());
	return str;
}

std::vector<std::string> StringUtil::Tokenize(const std::string &str, const std::string &delimitor)
{
	//Temp vector for returning
	std::vector<std::string> token;

	//gets position of token
	std::string::size_type lastPos = str.find_first_not_of(delimitor,0);

	//gets position of token end
	std::string::size_type pos = str.find_first_of(delimitor, lastPos);

	while(std::string::npos != pos || std::string::npos != lastPos)
	{
		//adds the token to vector
		token.push_back(str.substr(lastPos, pos - lastPos));

		//moves position to next token
		lastPos = str.find_first_not_of(delimitor, pos);

		//moves position to end of next token
		pos = str.find_first_of(delimitor, lastPos);
	}

	//returns vector of tokens
	return token;
}

