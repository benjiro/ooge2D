#ifndef _SCENE_DESCRIPTION_HPP
#define _SCENE_DESCRIPTION_HPP

#include <Config.hpp>
#include <string>

namespace ooge
{
	class Cull;

	struct SceneDescription
	{
		SceneDescription()
		{
			ScreenWidth = 800;
			ScreenHeight = 600;
			EnableFullScreen = false;
			EnableAudio = false;
			SceneCuller = NULL;
			WindowName = std::string("OOGE Engine");
		}

		~SceneDescription() {}

		Int32 ScreenHeight;
		Int32 ScreenWidth;
		bool EnableAudio;
		bool EnableFullScreen;
		Cull *SceneCuller;
		std::string WindowName;

	};
}

#endif //_SCENE_DESCRIPTION_HPP