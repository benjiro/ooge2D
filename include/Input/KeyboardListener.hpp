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

#ifndef _KEYBOARDLISTENER_HPP_
#define _KEYBOARDLISTENER_HPP_

#include <InputListener.hpp>
#include <Config.hpp>
#include <vector>

namespace ooge
{
	//! Struct Key
	/*! This structure reprosents an action of a key
	 it will be used to store actions of keys*/
	struct Key
	{
		Int32 key;
		Int32 state;
	};

	//! Keyboard Listener Class
	/*! This class is drived from InputListener, it provides
	 layout for processing keyboard function & testing keys*/
	class OOGE_API KeyboardListener : public InputListener
	{
	public:
		//! Default Constructor
		KeyboardListener();
		//! Destructor
		~KeyboardListener();

		//! Virtual Function Update
		/*! This function clears keyboard vector. This will be called each frame
		 from InputManager */
		virtual void Update();

		//! Function IsKeyDown
		/*! This function will check the given key is down and return bool true or false */
		bool IsKeyDown(Int32 key);

		//! Function AddKey
		/*! This function adds a key to the vector of active keys. DON'T CALL THIS FUNCTION Int32ERNAL */
		void AddKey(Key addKey);

		//debug function
		std::vector<Key> &GetKeyList() { return mKeyList; }
	protected:

		//! Function RemoveKey
		/*! This function removes a key from the given position in the vector */
		void _RemoveKey(size_t position);
	private:
		std::vector<Key> mKeyList; /*!< A vector which holds the active key press each frame*/
	};
}

#endif //_KEYBOARDLISTENER_HPP_