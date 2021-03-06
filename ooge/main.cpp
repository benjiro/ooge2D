#include <Ooge.hpp>
#include <Common.hpp>
#include "StateManager.hpp"
#include "DemoSprite.hpp"
#include "DemoFont.hpp"
#include "DemoSound.hpp"
#include "DemoGame.hpp"

int main()
{
	std::vector<ooge::State*> states;
	ooge::SceneDescription des;
	des.EnableFullScreen = false;
	des.SceneCuller = new ooge::ScreenCull("culler");
	des.ScreenHeight = 768;
	des.ScreenWidth = 1024;
	des.EnableAudio = true;
	ooge::Scene *scene = new ooge::Scene(&des);
	ooge::MouseListener *mouse = ooge::InputManager::GetSingletonPtr()->GetMouseListener();
	ooge::KeyboardListener *keyboard = ooge::InputManager::GetSingletonPtr()->GetKeyboardListener();
	ooge::StateManager *state = new ooge::StateManager();
	state->AddState(new ooge::DemoSprite("DemoSprite", scene));
	state->SetCurrentState("DemoSprite");
	states.push_back(state->GetCurrentState());
	ooge::DemoFont *fontS = new ooge::DemoFont("DemoFont", scene);
	ooge::DemoSound *soundS = new ooge::DemoSound("DemoSound", scene);
	ooge::DemoGame *gameS = new ooge::DemoGame("DemoGame", scene);
	state->AddState(fontS);
	state->AddState(soundS);
	state->AddState(gameS);
	states.push_back(fontS);
	states.push_back(soundS);
	states.push_back(gameS);

	ooge::Font *font = new ooge::Font("data/arial.ttf", 12);
	ooge::Text *text = new ooge::Text(font, "fps", ooge::Vector2(1,730));
	text->SetColour(0,0,0,255);
	scene->AddRenderable(text);

	int frames = 0;
	float nextUpdate = 0;

	while(scene->GetStatus())
	{
		state->UpdateCurrentState(scene->GetDeltaTime());
		frames++;
		float overtime = clock() - nextUpdate;
		if(overtime > 0)
		{
			float fps = frames / (float)(1+ (float)overtime/(float)CLOCKS_PER_SEC);
			frames = 0;
			nextUpdate = clock() + 1 * CLOCKS_PER_SEC;
			if(state->GetCurrentState())
				text->SetText("FPS: " + ooge::StringUtil::ParseRealToString(fps) + 
				"\nCurrent State: " + state->GetCurrentState()->GetName() + "\t\t\t Next: Space/A\t Back: Backspace/B\tToggle: T/Right Trigger");

		}
		if(keyboard->IsKeyDown('q'))
			scene->RequestShutdown();
		if(keyboard->IsKeyDown(ooge::KEY_F1))
		{
			for(int i = 0; i < states.size(); ++i)
			{
				if(states[i] == state->GetCurrentState())
					states.erase(i + states.begin());
			}
			state->RemoveState(state->GetCurrentState());
			state->SetCurrentState(states[0]);
			text = new ooge::Text(font, "fps", ooge::Vector2(1,730)); 
			scene->AddRenderable(text);
			text->SetColour(0,0,0);
		}
		scene->RenderOneFrame();
	}
	scene->Shutdown();
	delete scene;

	return 0;
}