#ifndef _DEMO_SOUND_HPP_
#define _DEMO_SOUND_HPP_

#include <string>
#include "State.hpp"
#include <vector>

namespace ooge
{
	class Scene; 
	class KeyboardListener;
	class MouseListener;
	class Text;
	class Sound;
	class Sprite;
	class SoundStream;

	class DemoSound : public ooge::State
	{
	public:
		DemoSound(const std::string &name, ooge::Scene *scene);
		~DemoSound();

		virtual void Update(float deltaT);
		virtual void OnEnter();
		virtual void OnExit();
	private:
		ooge::KeyboardListener *mKeyboard;
		ooge::MouseListener *mMouse;
		ooge::Scene *mScene;
		ooge::Text *mText;
		ooge::SoundStream *stream;
		ooge::Sound *mSound;
		ooge::Sound *mWater;
		std::vector<ooge::Sprite*> mActive;
	};
}

#endif //_DEMO_SOUND_HPP_