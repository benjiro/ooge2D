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

#ifndef _SINGLETON_HPP_
#define _SINGLETON_HPP_

#include <assert.h>
#include <Config.hpp>

namespace ooge {
	template <typename T> class OOGE_API Singleton
	{
	protected:
		static T* ms_Singleton;
	public:
		Singleton( void )
		{
			assert( !ms_Singleton );
#if defined( _MSC_VER ) && _MSC_VER < 1200	 
			Int32 offset = (Int32)(T*)1 - (Int32)(Singleton <T>*)(T*)1;
			ms_Singleton = (T*)((Int32)this + offset);
#else
			ms_Singleton = static_cast< T* >( this );
#endif
		}
		~Singleton( void )
		{  assert( ms_Singleton );  ms_Singleton = 0;  }
		static T& GetSingleton( void )
		{	assert( ms_Singleton );  return ( *ms_Singleton ); }
		static T* GetSingletonPtr( void )
		{ return ms_Singleton; }
	};
}
#endif //_SINGLETON_HPP_
