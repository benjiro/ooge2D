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

#include <Thread.hpp>

using namespace ooge;

Thread::Thread()
{
}

Thread::Thread(ThreadFunc func, void *arg) :
mFunc(func), mArguments(arg)
{
}

void Thread::Kill()
{
	if(mHandle)
	{
		TerminateThread(mHandle, 0);
		mHandle = NULL;
	}
}

void Thread::Run()
{
	if(mFunc)
		mFunc(mArguments);
}

void Thread::Start()
{
	mHandle = reinterpret_cast<HANDLE>(_beginthreadex(NULL, 0, &Thread::ThreadFuncCall, this, 0, &mId));

	if(!mHandle)
		std::cout << "Error creating thread" << std::endl;//error
}

void Thread::Wait()
{
	if(mHandle)
	{
		WaitForSingleObject(mHandle, INFINITE);
		CloseHandle(mHandle);
		mHandle = NULL;
	}
}

UInt32 __stdcall Thread::ThreadFuncCall(void *arguments)
{
	Thread *runningThread = reinterpret_cast<Thread*>(arguments);

	runningThread->Run();

	_endthreadex(0);

	return 0;
}