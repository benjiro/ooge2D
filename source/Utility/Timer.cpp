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

#include "Timer.hpp"
#include <algorithm>

using namespace ooge;

Timer::Timer()
{
	Reset();
}

Timer::~Timer()
{
}

void Timer::Reset()
{
	QueryPerformanceFrequency(&mFreq);
	QueryPerformanceCounter(&mStart);

	mStartTick = GetTickCount();
	mLastTime = 0;

	HANDLE proc = GetCurrentProcess();
	GetProcessAffinityMask(proc, &mProcMask, &mSysMask);

	mThread = GetCurrentThread();
}

unsigned long Timer::GetTimeElapsed()
{
	LARGE_INTEGER curTime;

	QueryPerformanceCounter(&curTime);

	return static_cast<unsigned long>(curTime.QuadPart / mFreq.QuadPart);
}

unsigned long Timer::GetMicroseconds()
{
	LARGE_INTEGER curTime;

	SetThreadAffinityMask(mThread, 1);

	QueryPerformanceCounter(&curTime);

	LONGLONG newTime = curTime.QuadPart - mStart.QuadPart;

	unsigned long newTick = static_cast<unsigned long>(1000 * newTime / mFreq.QuadPart);

	unsigned long check = GetTickCount() - mStartTick;
	signed long msecOff = static_cast<signed long>(newTick - check);
	if(msecOff < -100 || msecOff > 100)
	{
		LONGLONG adjust = (std::min)(msecOff * mFreq.QuadPart / 1000, newTime / mLastTime);
		mStart.QuadPart += adjust;
		newTime -= adjust;
	}

	mLastTime = newTime;

	newTick = static_cast<unsigned long>(1000000 * newTime / mFreq.QuadPart);

	return newTick;
}

unsigned long Timer::GetMilliseconds()
{
	LARGE_INTEGER curTime;

	SetThreadAffinityMask(mThread, 1);

	QueryPerformanceCounter(&curTime);

	LONGLONG newTime = curTime.QuadPart - mStart.QuadPart;

	unsigned long newTick = static_cast<unsigned long>(1000 * newTime / mFreq.QuadPart);

	unsigned long check = GetTickCount() - mStartTick;
	signed long msecOff = static_cast<signed long>(newTick - check);
	if(msecOff < -100 || msecOff > 100)
	{
		LONGLONG adjust = (std::min)(msecOff * mFreq.QuadPart / 1000, newTime / mLastTime);
		mStart.QuadPart += adjust;
		newTime -= adjust;

		newTick = static_cast<unsigned long>(1000 * newTime / mFreq.QuadPart);
	}

	mLastTime = newTime;

	return newTick;
}
