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

#include <InputManager.hpp>
#include <InputListener.hpp>
#include <KeyboardListener.hpp>
#include <MouseListener.hpp>

using namespace ooge;

template<> InputManager *Singleton<InputManager>::ms_Singleton = 0;

InputManager::InputManager()
: mKeyboard(new KeyboardListener()), mMouse(new MouseListener())
{
	AddInputListener(std::string("keyboard"), mKeyboard);
	AddInputListener(std::string("mouse"), mMouse);
}

InputManager::~InputManager()
{
	ClearInputListeners();
}

InputListener *InputManager::AddInputListener(const std::string &name, InputListener *addListener)
{
	ConstInputListenerIt it = mInputListenerMap.find(name);
	if(it != mInputListenerMap.end())
		return (*it).second; // already in system

	mInputListenerMap.insert(std::pair<std::string, InputListener *>(name, addListener));
	addListener->Update();
	return addListener;
}

InputListener *InputManager::GetListenerByName(const std::string &name) const
{
	ConstInputListenerIt it = mInputListenerMap.find(name);
	return (it != mInputListenerMap.end()) ? (*it).second : NULL;
}

bool InputManager::RemoveInputListener(const std::string &name)
{
	InputListenerIt it = mInputListenerMap.find(name);
	if(it != mInputListenerMap.end())
	{
		delete (*it).second;
		mInputListenerMap.erase(it);
		return true;
	}
	return false;
}

bool InputManager::RemoveInputListener(InputListener *removeListener)
{
	InputListenerIt it = mInputListenerMap.begin();
	for(; it != mInputListenerMap.end(); ++it)
	{
		if(it->second == removeListener)
		{
			delete (*it).second;
			mInputListenerMap.erase(it);
			return true;
		}
	}
	return false;
}

void InputManager::ClearInputListeners()
{
	if(!mInputListenerMap.empty())
	{
		InputListenerIt it = mInputListenerMap.begin();
		for(; it != mInputListenerMap.end(); ++it)
		{
			delete (*it).second;
		}
	}

	mInputListenerMap.clear();
}
		  
void InputManager::UpdateListener()
{
	ConstInputListenerIt it = mInputListenerMap.begin();
	for(; it != mInputListenerMap.end(); ++it)
	{
		(*it).second->Update();
	}
}

KeyboardListener *InputManager::GetKeyboardListener()
{
	return mKeyboard;
}

MouseListener *InputManager::GetMouseListener()
{
	return mMouse;
}

InputManager &InputManager::GetSingleton()
{
	assert(ms_Singleton);
		return (*ms_Singleton);
}

InputManager *InputManager::GetSingletonPtr()
{
	return ms_Singleton;
}