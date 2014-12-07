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

#ifndef _CONFIG_HPP_
#define _CONFIG_HPP_

//OOGE version format - Major Minor Patch
#define OOGE_VERSION_MAJOR 0
#define OOGE_VERSION_MINOR 6
#define OOGE_VERSION_PATCH 0
#define OOGE_VERSION ((OOGE_VERSION_MAJOR << 8) | (OOGE_VERSION_MINOR << 4) | (OOGE_VERSION_PATCH))
//OOGE code name - based on Japaneses era names
#define OOGE_VERSION_NAME "Taika"

//Windows system definitions
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
	#define OOGE_WINDOWS
	#ifndef WIN32_LEAN_AND_MEAN
		#define WIN32_LEAN_AND_MEAN
	#endif //WIN32_LEAN_AND_MEAN

	#ifndef NOMINMAX
		#define NOMINMAX
	#endif //NOMINMAX

	#ifdef OOGE_DYNAMIC
		#ifdef OOGE_EXPORT
			#define OOGE_API __declspec(dllexport)
		#else //API Export
			#define OOGE_API __declspec(dllimport)
		#endif //API Import

		#ifdef _MSC_VER //Disable annoying message
			#pragma warning (disable : 4251)
		#endif //_MSC_VER
	#else
		#define OOGE_API //Static Linking
	#endif //OOGE_DYNAMIC
#endif //OOGE_WINDOWS

//check linux
//check mac
//check andorid
//check ipohone

#ifdef _MSC_VER //Disable annoying msc warnings
	#pragma warning (disable : 4244)
	#pragma warning (disable : 4748)
	#pragma warning (disable : 4804)
#endif //_MSC_VER

namespace ooge
{
	#ifdef OOGE_DOUBLE_PRECISION //Enable double precision
		typedef double Real;
	#else
		typedef float Real;
	#endif // OOGE_DOUBLE_PRECISION

	//Texture handler
	typedef unsigned int Texture; 

	//OOGE data types
	typedef unsigned char UInt8;
	typedef signed char Int8;

	typedef unsigned short UInt16;
	typedef signed short Int16;

	typedef unsigned int UInt32;
	typedef signed int Int32;
}

#endif //_CONFIG_HPP_