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

#ifndef _INPUTMANAGER_HPP_
#define _INPUTMANAGER_HPP_

#include <Singleton.hpp>
#include <string>
#include <map>
#include <Config.hpp>

#include <InputKeys.hpp>

namespace ooge
{
	//! Forward Declaration
	class InputListener;
	class KeyboardListener;
	class MouseListener;

	//! Input Managet Class
	/*! This class manages all input within ooge, make sure you call new before creating
	 a new window. This class is a singleton because there should ever only be one manager */
	class OOGE_API InputManager : public Singleton<InputManager>
	{
	public:
		//! Default Constructor
		InputManager();
		~InputManager();


		//! Function AddInputListener
		/*! This function will add a given InputListener poInt32er and then manage */
		InputListener *AddInputListener(const std::string &name, InputListener *addListener);

		//! Function GetListenerByName
		/* This function finds given listener and returns a pointer */
		InputListener *GetListenerByName(const std::string &name) const;
		
		//! Function RemoveInputListener
		/*! This function will remove a given InputListener poInt32er that assosates with the name */
		bool RemoveInputListener(const std::string &name);
		
		//! Function RemoveInputListener
		/*! This function will remove a given InputListener poInt32er from the manager */
		bool RemoveInputListener(InputListener *removeListener);
		
		//! Function ClearInputListeners
		/*! This function will remove all Listener from the manager */
		void ClearInputListeners();
		
		//! Function UpdateListener
		/*! This function will call virtual fuction of InputListener. Call this
		 function before GLFWSwap*/
		void UpdateListener();
		
		//! Function GetKeyboardListener
		/*! This will retreive a poInt32er to Keyboard Listener.
		 Store this poInt32er in a local variable so easy access to
		 Check functions for keyboard*/		
		KeyboardListener *GetKeyboardListener();
		
		//! Function GetMouseListener
		/*! This will retreive a poInt32er to Mouse Listener.
		 Store this poInt32er in a local variable so easy access to
		 Check functions for mouse*/	
		MouseListener *GetMouseListener();

		//! Function GetListener
		/*! This will retreive a pointer to Input Listener list.*/	
		inline std::map<std::string, InputListener*> &GetListenerList()
		{
			return mInputListenerMap;
		}

		//! Function GetSingleton
		/*! This static function retreives reference to itselfs. IE Singleton*/	
		static InputManager &GetSingleton();
		
		//! Function GetSingletonPtr
		/*! This static function retreives poInt32er to itselfs. IE Singleton*/	
		static InputManager *GetSingletonPtr();
		
	private:
		KeyboardListener *mKeyboard; /*!< Holds poInt32er to keyboard Listener. Use the get function to access */
		MouseListener *mMouse; /*!< Holds poInt32er to mouse Listener. Use the get function to access */
		
		std::map<std::string, InputListener*> mInputListenerMap; /*!< Holds names and current listener active. Mouse + Keyboard listener always active*/
		typedef std::map<std::string, InputListener*>::const_iterator ConstInputListenerIt; /*!< provides typedef of const iterator for input map */
		typedef std::map<std::string, InputListener*>::iterator InputListenerIt; /*!< Provides typdef of iterator for input map */
	};
}

#endif //_INPUTMANAGER_HPP_