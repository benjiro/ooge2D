#ifndef _DEMO_FONT_HPP
#define _DEMO_FONT_HPP

#include <string>
#include "State.hpp"

namespace ooge
{
	class Scene; 
	class KeyboardListener;
	class MouseListener;
	class Text;

	class DemoFont : public ooge::State
	{
	public:
		DemoFont(const std::string &name, ooge::Scene *scene);
		~DemoFont();
		
		virtual void Update(float deltaT);
		virtual void OnEnter();
		virtual void OnExit();
	private:
		ooge::KeyboardListener *mKeyboard;
		ooge::MouseListener *mMouse;
		ooge::Scene *mScene;
		ooge::Text *mText;
		ooge::Text *mGuide;
	};
}

#endif //_DEMO_FONT_HPP