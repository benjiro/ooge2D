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

#ifndef _MUTEX_HPP_
#define _MUTEX_HPP_

#include <Windows.h>
#include <Config.hpp>

namespace ooge
{
	//! Mutex Class
	/*! This class provides functionallity of Mutual excusion which provides a
	method of avoid the simultaneous use of a common resource
	
	To Use: Just call Lock before thread starts and Unlock after it finish
	Recommended use a mutex with Lock class to provide a fallback if the thread fails*/
	class OOGE_API Mutex
	{
	public:
		//! Default Constructor
		Mutex();
		//! DeConstructor
		~Mutex();

		//! Method for Locking thread
		/*! By calling this method it will make sure the thread is safe */
		void Lock();
		//! Method for Unlocking thread
		/*! By calling this method it will unlock the mutex on the thread*/
		void Unlock();
	private:
		CRITICAL_SECTION mHandle; /*!< Thread that is being mutexed */
	};
}

#endif //_MUTEX_HPP_