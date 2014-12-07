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

#ifndef _TIMER_HPP_
#define _TIMER_HPP_

#include <windows.h>
#include <Config.hpp>

namespace ooge
{
	class Timer
	{
	public:
		Timer();
		~Timer();

		unsigned long GetTimeElapsed();
		unsigned long GetMilliseconds();
		unsigned long GetMicroseconds();

		void Reset();

	private:
		long mReset;
		DWORD mStartTick;
		LONGLONG mLastTime;
		LARGE_INTEGER mStart;
		LARGE_INTEGER mFreq;
		DWORD mProcMask;
		DWORD mSysMask;
		HANDLE mThread;
	};
}


#endif //_TIMER_HPP_
