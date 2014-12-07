#include "DemoFont.hpp"
#include <Scene.hpp>
#include <KeyboardListener.hpp>
#include <MouseListener.hpp>
#include <InputManager.hpp>
#include <Text.hpp>
#include <Font.hpp>
#include <Sprite.hpp>

using namespace ooge;

DemoFont::DemoFont(const std::string &name, ooge::Scene *scene)
: mScene(scene), State(name), mKeyboard(InputManager::GetSingletonPtr()->GetKeyboardListener()),
mMouse(InputManager::GetSingletonPtr()->GetMouseListener())
{
}

DemoFont::~DemoFont()
{
}

void DemoFont::Update(float deltaT)
{
	static int currentState = 0;

	if(currentState == 0)
	{
		mGuide->SetText("Static Text Renderable");
	}
	if(currentState == 1)
	{
		static std::string mode("NONE");
		mGuide->SetText("A Text Renderable has Styles\n"+mode);

		static int modeS = 0;
		if(modeS == 0)
		{
			mText->SetFontStyle(ooge::Bold);
			mode = std::string("BOLD");
		}
		if(modeS == 1)
		{
			mText->SetFontStyle(ooge::Italic);
			mode = std::string("ITALIC");
		}
		if(modeS == 2)
		{
			mText->SetFontStyle(ooge::Underline);
			mode = std::string("UNDERLINE");
		}
		if(modeS == 3)
		{
			mText->SetFontStyle(ooge::Underline || ooge::Bold || ooge::Italic);
			mode = std::string("ALL");
		}

		if(mKeyboard->IsKeyDown('t'))
			modeS++;

		if(modeS > 3)
			modeS = 0;

	}
	if(currentState == 2)
	{
		static bool firstTime = true;
		static float rotation = 0;
		static float alpha = 0;
		static bool onTouch = false;


		if(firstTime)
		{
			ooge::Font *font = new ooge::Font("data/ghettomarquee.ttf", 20);
			ooge::Text *text = new ooge::Text(font, "The quick brown fox jumps over the lazy dog", ooge::Vector2(50,50));
			mScene->AddRenderable(text);
			text->SetColour(0,0,0);
			firstTime = false;
		}

		rotation = rotation + ((rotation - 2.0f) - rotation)*0.1;
		alpha = alpha + ((alpha + 2.0f) - alpha)*0.5;

		if(alpha > 255)
			alpha = 0;

		if(mMouse->IsDown(ooge::BUTTON_LEFT))
			onTouch = true;
		if(mMouse->IsPressed(ooge::BUTTON_LEFT))
			onTouch = false;

		if(onTouch)
			mText->SetPosition(mMouse->GetMousePosition());

		mText->SetAlpha(alpha);
		mText->SetRotation(rotation);
	}

	if(mKeyboard->IsKeyDown(ooge::KEY_SPACE))
		currentState++;
	if(mKeyboard->IsKeyDown(ooge::KEY_BACKSPACE))
		currentState--;

	if(currentState >= 2)
		currentState = 2;
	if(currentState <= 0)
		currentState = 0;
}

void DemoFont::OnEnter()
{
	ooge::Sprite *bg = new ooge::Sprite("data/bg.png", "background", ooge::Vector2(512,384));
	bg->SetOrder(1000);
	bg->SetBlendMode(ooge::None);
	mScene->AddRenderable(bg);
	ooge::Font *font = new ooge::Font("data/arial.ttf", 20);
	mText = new ooge::Text(font, "The quick brown fox jumps over the lazy dog", ooge::Vector2(300,384));
	mGuide = new ooge::Text(font, "", ooge::Vector2(10,10));
	mGuide->SetColour(0,0,255);
	mText->SetColour(0,0,255);
	mScene->AddRenderable(mText);
	mScene->AddRenderable(mGuide);
}

void DemoFont::OnExit()
{
	mScene->ClearRenderableList();
}