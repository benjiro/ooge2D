#include "DemoSprite.hpp"
#include <PhysicsWorld.hpp>
#include <PhysicsObject.hpp>
#include <Scene.hpp>
#include <SpriteAnimation.hpp>
#include <KeyboardListener.hpp>
#include <MouseListener.hpp>
#include <InputManager.hpp>
#include <Circle.hpp>
#include <Square.hpp>
#include <Font.hpp>
#include <Text.hpp>
#include <StringUtil.hpp>
#include <AnimationSequence.hpp>
#include <ControllerListener.hpp>
#include <Controller.hpp>

using namespace ooge;

DemoSprite::DemoSprite(const std::string &name, Scene *scene)
: mScene(scene), 
mKeyboard(InputManager::GetSingletonPtr()->GetKeyboardListener()), mMouse(InputManager::GetSingletonPtr()->GetMouseListener()),
State(name), mMouseJoint(0)
{
	InputManager::GetSingletonPtr()->AddInputListener("xbox", new ControllerListener());
	mController = dynamic_cast<ControllerListener*>(InputManager::GetSingletonPtr()->GetListenerByName("xbox"))->GetControl(1);
}

DemoSprite::~DemoSprite()
{
}

void DemoSprite::Update(float deltaT)
{
	ooge::Square *square = dynamic_cast<Square*>(mScene->GetRenderable("box"));
	ooge::SpriteAnimation *sprite = dynamic_cast<SpriteAnimation*>(mScene->GetRenderable("gabe"));

	static int demoState = 0;

	if(demoState == 0)
	{
		mText->SetText("A Renderable.");
	}
	if(demoState == 1)
	{
		square->SetAlpha(255);
		mText->SetText("Colour changing a Renderable");
		if(mKeyboard->IsKeyDown('t') || mKeyboard->IsKeyDown(ooge::KEY_LCTRL) || mController->IsYDown())
			square->SetColour(rand()%255, rand()%255, rand()%255);
	}
	if(demoState == 2)
	{
		sprite->SetAlpha(0);
		square->SetScale(1,1);
		square->SetRotation(0);

		mText->SetText("Alpha Blending a Renderable");
		static int alpha = 255;
		static bool flip = false;

		if(flip)
			alpha++;
		else
			alpha--;

		if(alpha >= 255)
			flip = false;
		else if(alpha <= 0)
			flip = true;
		square->SetAlpha(alpha);
	}
	if(demoState == 3)
	{
		square->SetAlpha(255);
		sprite->SetAlpha(0);

		static float rotation = 0.0f;
		static float scale = 0.0f;
		static bool flip = false;		

		if(flip)
		{
			scale = scale + ((scale - 0.01f) - scale)*0.1;
			rotation = rotation + ((rotation - 2.0f) - rotation)*0.1;
		}
		else
		{
			scale = scale + ((scale + 0.01f) - scale)*0.1;
			rotation = rotation + ((rotation + 2.0f) - rotation)*0.1;
		}



		if(scale >= 3)
			flip = true;
		else if(scale <= 0.1)
			flip = false;

		square->SetRotation(rotation);
		square->SetScale(scale,scale);

		mText->SetText("Rotating & Scaling a Renderable");		
	}
	if(demoState == 4)
	{
		square->SetAlpha(0);
		sprite->SetAlpha(255);
		mText->SetText("A Sprite Renderable");
	}
	if(demoState == 5)
	{
		static std::string mode("LOOP");
		mText->SetText("A Animated Sprite\nCurrent Mode: " + mode);

		static bool runonce = false;
		if(!runonce)
		{
			sprite->PlaySequence("running");
			runonce = true;
		}

		static int speed = 150;
		if(mKeyboard->IsKeyDown(ooge::KEY_UP))
			speed += 5;
		if(mKeyboard->IsKeyDown(ooge::KEY_DOWN))
			speed -= 5;

		sprite->GetSequence("running")->SetSpeed(speed);
		square->SetAlpha(0);
		sprite->SetAlpha(255);

		static int type = 0;
		if(type == 0)
		{
			sprite->GetSequence("running")->SetAnimationMode(ooge::LOOP);
			mode = std::string("LOOP");
		}
		if(type == 1)
		{
			sprite->GetSequence("running")->SetAnimationMode(ooge::REVERSE);
			mode = std::string("REVERSE");
		}
		if(type == 2)
		{
			sprite->GetSequence("running")->SetAnimationMode(ooge::BACKFORTH);
			mode = std::string("BACKFORTH");
		}

		if(mKeyboard->IsKeyDown('t'))
		{
			type++;
			sprite->PlaySequence("running");
		}

		if(type > 2)
			type = 0;
	}
	if(demoState == 6)
	{
		static bool firstTime = false;
		if(!firstTime)
		{
			ooge::PhysicsWorld *world = new ooge::PhysicsWorld(mScene, ooge::Vector2(0,10), true);
			firstTime = true;
			sprite->SetAlpha(0);
			sprite->RemoveSequence("running");
			ooge::Sprite *box = new ooge::Sprite("data/box.png", "phsBox", ooge::Vector2(512,384));
			mScene->AddRenderable(box);
			mText->SetText("Back to the old box...Let's add some life to it");
			ooge::ActorDescription des;
			des.Position.Set(0, 700);
			world->AddActor(new ooge::PhysicsObject(1024,10, &des, ooge::STATIC));
		}

		if(mKeyboard->IsKeyDown('t') || mController->IsYDown())
		{
			mScene->GetRenderable("phsBox")->SetAlpha(0);
			mScene->GetRenderable("phsBox")->SetOrder(2);
			ooge::ActorDescription des;
			des.Density = 2.0f;
			des.Restitution = 0.5f;
			des.Position.Set(512, 384);
			ooge::PhysicsWorld::GetSingletonPtr()->AddActor(new PhysicsObject(new ooge::Sprite("data/box.png", "phsBox1"), &des, ooge::DYNAMIC, ooge::SQUARE));
		}

		ooge::PhysicsWorld::GetSingletonPtr()->StepWorld(1.0f/60.0f);
	}
	if(demoState == 7)
	{
		mText->SetText("Joints can be created");
		static bool firstTime = false;
		if(!firstTime)
		{
			sprite->SetAlpha(0);
			ooge::PhysicsWorld *world = ooge::PhysicsWorld::GetSingletonPtr();
			b2BodyDef bd;
			ground = world->GetBox2DWorld()->CreateBody(&bd);
			b2PolygonShape shape;
			shape.SetAsEdge(b2Vec2(0,700), b2Vec2(1024,700));
			ground->CreateFixture(&shape, 0);
			firstTime = true;

			ooge::Sprite *groundspr = new ooge::Sprite("data/grass.png", "grass", ooge::Vector2(512, 685));
			groundspr->SetOrder(1);
			mScene->AddRenderable(groundspr);

			ooge::ActorDescription des;
			des.Density = 0.1f;
			des.Friction = 0.2f;

			b2RevoluteJointDef jd;
			jd.collideConnected = false;

			const float y = 384;
			b2Body *prevBody = ground;
			for(int i = 0; i < 50; ++i)
			{
				des.Position.Set(300+(8.0f*i), y);
				ooge::Sprite *sprite = new ooge::Sprite("data/chain.png", "phsB");
				sprite->SetOrder(2);
				ooge::PhysicsObject *obj = new ooge::PhysicsObject(sprite, &des, ooge::DYNAMIC, ooge::SQUARE);
				world->AddActor(obj);

				b2Vec2 anchor(float(300+(8.0f*i)), y);
				jd.Initialize(prevBody, obj->Getb2Body(), anchor);
				world->CreateJoint(&jd);

				prevBody = obj->Getb2Body();
			}

			prevBody = ground;
			for(int i = 0; i < 50; ++i)
			{
				des.Position.Set(450+(8.0f*i), y);
				ooge::Sprite *sprite = new ooge::Sprite("data/chain.png", "phsB");
				sprite->SetOrder(2);
				ooge::PhysicsObject *obj = new ooge::PhysicsObject(sprite, &des, ooge::DYNAMIC, ooge::SQUARE);
				world->AddActor(obj);

				b2Vec2 anchor(float(450+(8.0f*i)), y);
				jd.Initialize(prevBody, obj->Getb2Body(), anchor);
				world->CreateJoint(&jd);

				prevBody = obj->Getb2Body();
			}

			prevBody = ground;
			for(int i = 0; i < 50; ++i)
			{
				des.Position.Set(600+(8.0f*i), y);
				ooge::Sprite *sprite = new ooge::Sprite("data/chain.png", "phsB");
				sprite->SetOrder(2);
				ooge::PhysicsObject *obj = new ooge::PhysicsObject(sprite, &des, ooge::DYNAMIC, ooge::SQUARE);
				world->AddActor(obj);

				b2Vec2 anchor(float(600+(8.0f*i)), y);
				jd.Initialize(prevBody, obj->Getb2Body(), anchor);
				world->CreateJoint(&jd);

				prevBody = obj->Getb2Body();
			}

			for(int i = 0; i < 10; ++i)
			{
				des.Position.Set(rand()%800, 0);
				ooge::Sprite *sprite = new ooge::Sprite("data/plank.png", "plank");
				sprite->SetOrder(2);
				ooge::PhysicsObject *obj = new ooge::PhysicsObject(sprite, &des, ooge::DYNAMIC, ooge::SQUARE);
				world->AddActor(obj);
			}
		}

		if(mKeyboard->IsKeyDown('f') || mController->IsRightTriggerDown())
		{
			ooge::ActorDescription des;
			des.Density = 0.5f;
			des.Position.Set(0,384);
			des.Bullet = true;
			ooge::Sprite *sprite = new ooge::Sprite("data/box.png", "boxB");
			sprite->SetOrder(2);
			ooge::PhysicsObject *obj = new ooge::PhysicsObject(sprite, &des, ooge::DYNAMIC, ooge::SQUARE);
			ooge::PhysicsWorld::GetSingletonPtr()->AddActor(obj);
			obj->SetLinearVelocity(ooge::Vector2(100,5));
		}

		if(mMouse->IsDown(ooge::BUTTON_LEFT))
		{
			for(b2Body * bodyList = ooge::PhysicsWorld::GetSingletonPtr()->GetBox2DWorld()->GetBodyList(); bodyList; bodyList = bodyList->GetNext())
			{
				b2Vec2 mousePos(mMouse->GetMousePosition().X, mMouse->GetMousePosition().Y);
				b2AABB aabb;
				b2Vec2 d;
				d.Set(0.001f, 0.001f);
				aabb.lowerBound = mousePos - d;
				aabb.upperBound = mousePos + d;

				QCallBack callback(mousePos);
				PhysicsWorld::GetSingletonPtr()->GetBox2DWorld()->QueryAABB(&callback, aabb);
				if(!mMouseJoint)
				{
					if(callback.m_fixture)
					{
						b2Body* body = callback.m_fixture->GetBody();
						b2MouseJointDef md;
						md.bodyA = ground;
						md.bodyB = body;
						md.target = mousePos;
						md.maxForce = 10000.f * body->GetMass();
						mMouseJoint = (b2MouseJoint*)PhysicsWorld::GetSingletonPtr()->CreateJoint(&md);
						body->SetAwake(true);
					}
				}
			}
		}


		if(mMouse->IsPressed(ooge::BUTTON_LEFT))
		{
			if(mMouseJoint)
			{
				PhysicsWorld::GetSingletonPtr()->DestoryJoint(mMouseJoint);
				mMouseJoint = NULL;
			}
		}
		if(mMouse->IsPressed(ooge::BUTTON_RIGHT))
		{
			ooge::ActorDescription des;
			des.Density = 1.0f;
			des.Position=mMouse->GetMousePosition();;
			ooge::Sprite *sprite = new ooge::Sprite("data/plank.png", "plank");
			sprite->SetOrder(2);
			ooge::PhysicsObject *obj = new ooge::PhysicsObject(sprite, &des, ooge::DYNAMIC, ooge::SQUARE);
			PhysicsWorld::GetSingletonPtr()->AddActor(obj);
		}

		if(mMouseJoint)
		{
			mMouseJoint->SetTarget(b2Vec2(mMouse->GetMousePosition().X, mMouse->GetMousePosition().Y));
		}


		ooge::PhysicsWorld::GetSingletonPtr()->StepWorld(1.0f/60.0f);
	}

	if(demoState >= 7)
		demoState = 7;
	if(demoState <= 0)
		demoState = 0;

	if(mKeyboard->IsKeyDown('a') || mKeyboard->IsKeyDown(ooge::KEY_SPACE) || mController->IsADown())
	{
		demoState++;
	}
	if(mKeyboard->IsKeyDown('b') || mKeyboard->IsKeyDown(ooge::KEY_BACKSPACE) || mController->IsBDown())
	{
		demoState--;
	}
	if(mKeyboard->IsKeyDown('d'))
	{
		static bool flip = false;

		if(flip = !flip)
			flip = true;
		else
			flip = false;

		mScene->SetDebugRender(flip);
	}
}

void DemoSprite::OnEnter()
{
	ooge::Sprite *bg = new ooge::Sprite("data/bg.png", "background", ooge::Vector2(512,384));
	bg->SetOrder(1000);
	bg->SetBlendMode(ooge::None);
	mScene->AddRenderable(bg);

	ooge::Font *font = new ooge::Font("data/arial.ttf", 25);
	mText = new ooge::Text(font, "DemoSprite.cpp", Vector2(10,10));
	mScene->AddRenderable(mText);
	mText->SetColour(0,0,255);

	ooge::Square *square = new ooge::Square(120,120, "box", Vector2(512,384));
	mScene->AddRenderable(square);
	square->SetColour(255,0,0);

	ooge::SpriteAnimation *sprite = new ooge::SpriteAnimation("data/gaberun.png", "gabe", 64,64, 1, 6);
	sprite->AddSequence(new ooge::AnimationSequence("running", 0, 0, 6, ooge::LOOP));
	sprite->SetAlpha(0);
	sprite->SetScale(4,4);
	sprite->SetPosition(512,384);
	mScene->AddRenderable(sprite);
}

void DemoSprite::OnExit()
{
	delete PhysicsWorld::GetSingletonPtr();
	mScene->ClearRenderableList();
	//remove ooge scene
}