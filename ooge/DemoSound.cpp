#include "DemoSound.hpp"
#include <Sound.hpp>
#include <SoundStream.hpp>
#include <InputManager.hpp>
#include <KeyboardListener.hpp>
#include <MouseListener.hpp>
#include <Text.hpp>
#include <Font.hpp>
#include <SoundListener.hpp>
#include <AudioDevice.hpp>
#include <StringUtil.hpp>
#include <Scene.hpp>
#include "psapi.h"
#include <Sprite.hpp>
#include <SoundBuffer.hpp>

using namespace ooge;

DemoSound::DemoSound(const std::string &name, ooge::Scene *scene)
: mScene(scene), State(name), mKeyboard(InputManager::GetSingletonPtr()->GetKeyboardListener()),
mMouse(InputManager::GetSingletonPtr()->GetMouseListener()), stream(0)
{
}

DemoSound::~DemoSound()
{
}

void DemoSound::Update(float deltaT)
{
	static int currentState = 0;
	static bool firstTime = false;

	if(currentState == 0)
	{
		if(!firstTime)
		{
			ooge::Sprite *sprite = new ooge::Sprite("data/speaker.png", "speaker", ooge::Vector2(512,384));
			ooge::Sprite *source = new ooge::Sprite("data/box.png", "soundSource", ooge::Vector2(512,384));
			ooge::Sprite *water = new ooge::Sprite("data/box.png", "waterfall", ooge::Vector2(512,384));
			mScene->AddRenderable(sprite);
			mScene->AddRenderable(water);
			sprite->SetScale(0.5,0.5);
			mScene->AddRenderable(source);
			mActive.push_back(source);
			mActive.push_back(water);
			mActive.push_back(sprite);
			sprite->SetOrder(50);
			mSound = new ooge::Sound("data/bang.wav","sound",true);
			mWater = new ooge::Sound("data/waterfall.wav", "water", true);
			mWater->Play();
			mSound->Play();
			firstTime = true;
			//mSound->SetPosition(1.0f,0,0);
			SoundListener::SetListenerPosition(512,384,0);
		}
		
		static bool flip = true;
		static float position = 512.f;
		static float yPosition = 384.f;
		if(flip)
		{
			position = position + ((position + 0.1f) - position)*0.1f;
			yPosition = yPosition + ((yPosition + 0.1f) - yPosition)*0.1f;
			mScene->GetRenderable("soundSource")->Move(0.2,0);
			mScene->GetRenderable("waterfall")->Move(0,0.2);
		}
		else
		{
			position = position + ((position - 0.1f) - position)*0.1f;
			yPosition = yPosition + ((yPosition - 0.1f) - yPosition)*0.1f;
			mScene->GetRenderable("soundSource")->Move(-0.2,0);
			mScene->GetRenderable("waterfall")->Move(0,-0.2);
		}

		static int velocity = 0;
		if(mKeyboard->IsKeyDown(ooge::KEY_UP))
			velocity += 2;
		if(mKeyboard->IsKeyDown(ooge::KEY_DOWN))
			velocity -= 2;
		mSound->SetVelocity(velocity,0);

		if(position > 522.0f || yPosition > 394.0f)
			flip = false;
		if(position < 502.0f || yPosition < 374.0f)
			flip = true;
		mSound->SetPosition(position, 384);
		mWater->SetPosition(512,yPosition);
		mText->SetText("Static Sounds\nVelocity: "+StringUtil::ParseInt32ToString(velocity));
	}
	if(currentState == 1)
	{
		if(firstTime)
		{
			delete mWater;
			delete mSound;
			mSound = 0;
			for(int i = 0; i < mActive.size(); ++i)
			{
				mScene->RemoveRenderable(mActive[i]);
			}
			mActive.clear();
			stream = new ooge::SoundStream("data/tatw.ogg");
			stream->Play();
			firstTime = false;
		}
		PROCESS_MEMORY_COUNTERS cout;
		cout.cb = sizeof(cout);
		GetProcessMemoryInfo(GetCurrentProcess(),&cout,cout.cb);
		mText->SetText("Streaming a 700MB File\nMemory Usage: " + ooge::StringUtil::ParseRealToString(cout.WorkingSetSize/1024000) + "MB");
	}

	if(mKeyboard->IsKeyDown(ooge::KEY_SPACE))
		currentState++;
	if(mKeyboard->IsKeyDown(ooge::KEY_BACKSPACE))
		currentState--;

	if(currentState > 4)
		currentState = 4;
	if(currentState < 0)
		currentState = 0;
}

void DemoSound::OnEnter()
{
		ooge::Sprite *bg = new ooge::Sprite("data/bg.png", "background", ooge::Vector2(512,384));
	bg->SetOrder(1000);
	bg->SetBlendMode(ooge::None);
	mScene->AddRenderable(bg);
	ooge::Font *font = new ooge::Font("data/arial.ttf", 20);
	mText = new ooge::Text(font, "", ooge::Vector2(10,10));
	mText->SetColour(0,0,255);
	mScene->AddRenderable(mText);
}

void DemoSound::OnExit()
{
	if(mSound)
	{
			delete mWater;
			delete mSound;
	}
	if(stream)
		delete stream;
	mScene->ClearRenderableList();
}