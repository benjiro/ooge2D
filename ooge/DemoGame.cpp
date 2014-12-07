#include "DemoGame.hpp"
#include <Scene.hpp>
#include <SpriteAnimation.hpp>
#include <KeyboardListener.hpp>
#include <MouseListener.hpp>
#include <InputManager.hpp>
#include <Circle.hpp>
#include <Square.hpp>
#include <Font.hpp>
#include <Text.hpp>
#include <Image.hpp>
#include <StringUtil.hpp>

using namespace ooge;

DemoGame::DemoGame(const std::string &name, ooge::Scene *scene)
:mScene(scene), State(name), mKeyboard(InputManager::GetSingletonPtr()->GetKeyboardListener()), mMouseJoint(NULL),
mMouse(InputManager::GetSingletonPtr()->GetMouseListener()), mDrawLine(false)
{
	mObjectType = false;
	mPhysType = ooge::STATIC;
	mCreationType = 0;
	mAngle = 0;
}

DemoGame::~DemoGame()
{
}

void DemoGame::CreateObject(Vector2 &position, int type)
{
	if(type == 0)
	{
		ActorDescription des;
		des.Position = position;
		des.Density = 2.0f;
		des.Friction = 0.2f;

		ooge::Sprite *sprite = new ooge::Sprite("data/box.png", "box");
		sprite->SetOrder(2);
		ooge::PhysicsObject *obj = new ooge::PhysicsObject(sprite, &des, mPhysType, ooge::SQUARE);
		mWorld->AddActor(obj);
		mActiveObjects.push_back(obj);
	}
	if(type == 1)
	{
		ActorDescription des;
		des.Position = position;
		des.Density = 2.0f;
		des.Friction = 0.2f;

		ooge::Sprite *sprite = new ooge::Sprite("data/ball.png", "box");
		sprite->SetOrder(2);
		ooge::PhysicsObject *obj = new ooge::PhysicsObject(sprite, &des, mPhysType, ooge::CIRCLE);
		mWorld->AddActor(obj);
		mActiveObjects.push_back(obj);
	}
}

void DemoGame::CreateChain(ooge::Vector2 &position, int number)
{
	ooge::ActorDescription des;
	des.Density = 0.1f;
	des.Friction = 0.2f;

	b2RevoluteJointDef jd;
	jd.collideConnected = false;

	const float y = position.Y;
	b2Body *prevBody = ground;
	for(int i = 0; i < number; ++i)
	{
		des.Position.Set(position.X+(8.0f*i), y);
		ooge::Sprite *sprite = new ooge::Sprite("data/chain.png", "phsB");
		sprite->SetOrder(2);
		ooge::PhysicsObject *obj = new ooge::PhysicsObject(sprite, &des, ooge::DYNAMIC, ooge::SQUARE);
		mWorld->AddActor(obj);

		b2Vec2 anchor(float(position.X+(8.0f*i)), y);
		jd.Initialize(prevBody, obj->Getb2Body(), anchor);
		mWorld->CreateJoint(&jd);

		mActiveObjects.push_back(obj);
		prevBody = obj->Getb2Body();
	}
}

void DemoGame::Update(float deltaT)
{
	static bool thisflip = false;
	if(mMouse->IsPressed(ooge::BUTTON_LEFT))
	{
		if(!mMouseJoint)
		{
			if(mCreationType == 0)
			{
				mPositions.push_back(mMouse->GetMousePosition());
				ooge::Square *square = new ooge::Square(30,30,"placehold", mMouse->GetMousePosition());
				square->SetColour(255,0,0);
				mScene->AddRenderable(square);
				mPlaceHolder.push_back(square);
			}
			if(mCreationType == 1)
			{
				mPositions.push_back(mMouse->GetMousePosition());
				ooge::Circle *square = new ooge::Circle(30,"placehold", mMouse->GetMousePosition());
				square->SetColour(255,0,0);
				mScene->AddRenderable(square);
				mPlaceHolder.push_back(square);
			}
			if(mCreationType == 2)
			{
				if(mDrawLine = !mDrawLine)
				{
					mPositions.push_back(mMouse->GetMousePosition());
					mDrawLineObj = new ooge::Sprite("data/plank.png", "draw", mMouse->GetMousePosition());
					mPlaceHolder.push_back(mDrawLineObj);
					mScene->AddRenderable(mDrawLineObj);
					mDrawLine = true;
				}
				else
				{
					if(mPositions.size() <= 2)
						mPositions.push_back(mMouse->GetMousePosition());
					mDrawLine = false;
				}
			}
			if(mCreationType == 3)
			{
				if(mDrawLine = !mDrawLine)
				{
					mDrawLineObj = new ooge::Sprite("data/plank.png", "draw", mMouse->GetMousePosition());
					mPlaceHolder.push_back(mDrawLineObj);
					mScene->AddRenderable(mDrawLineObj);
					mPositions.push_back(mMouse->GetMousePosition());
					mDrawLine = true;
				}
				else
				{
					if(mPositions.size() <= 2)
						mPositions.push_back(mMouse->GetMousePosition());
					mDrawLine = false;
				}
			}
		}

		if(mMouseJoint)
		{
			if(mMouseJoint)
			{
				mWorld->DestoryJoint(mMouseJoint);
				mMouseJoint = NULL;
			}
		}
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

			QCallBack1 callback(mousePos);
			mWorld->GetBox2DWorld()->QueryAABB(&callback, aabb);
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
					mMouseJoint = (b2MouseJoint*)mWorld->CreateJoint(&md);
					body->SetAwake(true);
				}
			}
		}
	}

	if(mDrawLine && !mPositions.empty() && mCreationType == 2)
	{
		float x = ((int)(mPositions[0].X - mMouse->GetMousePosition().X) ^ -true) + true;
		float y = ((int)(mPositions[0].Y - mMouse->GetMousePosition().Y) ^ -true) + true;
		if(!thisflip)
		{
			mDrawLineObj->SetPosition(mMouse->GetMousePosition().X - (x/2),mMouse->GetMousePosition().Y - (y/2));
			if(x < 0)
			{
				x = ((int)(mPositions[0].X - mMouse->GetMousePosition().X) ^ -false) + false;
				mDrawLineObj->SetPosition(Vector2(mMouse->GetMousePosition().X + (x/2), mDrawLineObj->GetPosition().Y));
			}

			if(y < 0)
			{
				y = ((int)(mPositions[0].Y - mMouse->GetMousePosition().Y) ^ -false) + false;
				mDrawLineObj->SetPosition(Vector2(mDrawLineObj->GetPosition().X, mMouse->GetMousePosition().Y + (y/2)));
			}
			mDrawLineObj->GetImage()->SetWidth(x);
			mDrawLineObj->GetImage()->SetHeight(y);
			mPosition = Vector2(mMouse->GetMousePosition().X - (x/2),mMouse->GetMousePosition().Y - (y/2));
		}
		else
		{
			mPositions.push_back(mMouse->GetMousePosition());
			mAngle = y/2;
			mDrawLineObj->SetRotation(y/2);
		}

		if(mKeyboard->IsKeyDown(ooge::KEY_SPACE))
		{
			if(thisflip = !thisflip)
				thisflip = true;
			else
				thisflip = false;
		}
	}

	if(mDrawLine && !mPositions.empty() && mCreationType == 3)
	{
		float x = ((int)(mPositions[0].X - mMouse->GetMousePosition().X) ^ -true) + true;
		float y = ((int)(mPositions[0].Y - mMouse->GetMousePosition().Y) ^ -true) + true;
		mDrawLineObj->SetPosition(mMouse->GetMousePosition().X - (x/2),mMouse->GetMousePosition().Y - (y/2));
		if(x < 0)
		{
			x = ((int)(mPositions[0].X - mMouse->GetMousePosition().X) ^ -false) + false;
			mDrawLineObj->SetPosition(Vector2(mMouse->GetMousePosition().X + (x/2), mDrawLineObj->GetPosition().Y));
		}
	
		if(y < 0)
		{
			y = ((int)(mPositions[0].Y - mMouse->GetMousePosition().Y) ^ -false) + false;
			mDrawLineObj->SetPosition(Vector2(mDrawLineObj->GetPosition().X, mMouse->GetMousePosition().Y + (y/2)));
		}

		mDrawLineObj->GetImage()->SetWidth(x);
		mDrawLineObj->GetImage()->SetHeight(y);
		mPosition = Vector2(mMouse->GetMousePosition().X - (x/2),mMouse->GetMousePosition().Y - (y/2));
		//mDrawLineObj->SetRotation(y/2);
	}

	if(mObjectType)
	{
		mText->SetText("Object type: Dynamic");
		mPhysType = ooge::DYNAMIC;
	}
	else
	{
		mText->SetText("Object type: Static");
		mPhysType = ooge::STATIC;
	}

	if(mKeyboard->IsKeyDown('t'))
	{
		if(mObjectType = !mObjectType)
			mObjectType = true;
		else
			mObjectType = false;
	}
	if(mKeyboard->IsKeyDown('y'))
	{
		mCreationType++;
		if(mCreationType > 3)
			mCreationType = 0;
	}

	if(mCreationType == 0)
		mText2->SetText("Type: Square");
	if(mCreationType == 1)
		mText2->SetText("Type: Ball");
	if(mCreationType == 2)
		mText2->SetText("Type: Draw");
	if(mCreationType == 3)
		mText2->SetText("Type: Draw Joint Chain");

	if(mKeyboard->IsKeyDown('c'))
	{
		if(mCreationType != 2)
		{
			for(int i = 0; i < mPositions.size(); ++i)
				CreateObject(mPositions[i], mCreationType);
		}	

		for(int i = 0; i < mPlaceHolder.size(); ++i)
			mScene->RemoveRenderable(mPlaceHolder[i]);

		mPositions.clear();
		mPlaceHolder.clear();
	}

	if(mPositions.size() >= 2 && !mDrawLine && mCreationType == 2)
	{
		ActorDescription des;
		des.Position = mPosition;
		des.Density = 2.0f;
		des.Friction = 0.2f;
		float width = ((int)(mPositions[0].X - mPositions[0 + 1].X) ^ -true) + true;
		if(width < 0)
			width = ((int)(mPositions[0].X - mPositions[0 + 1].X) ^ -false) + false;
		float height = ((int)(mPositions[0].Y - mPositions[0 + 1].Y) ^ -true) + true;
		if(height < 0)
			height = ((int)(mPositions[0].Y - mPositions[0 + 1].Y) ^ -false) + false;
		ooge::PhysicsObject *obj = new ooge::PhysicsObject(width,height, &des, mPhysType);
		ooge::Sprite *sprite = new ooge::Sprite("data/plank.png","plank");
		sprite->SetOrder(2);
		sprite->GetImage()->SetHeight(height);
		sprite->GetImage()->SetWidth(width);
		obj->SetRenderable(sprite);
		obj->SetTransform(Vector2(mPositions[0 + 1].X - (width/2),mPositions[0 + 1].Y - (height/2)), math::ToRadians(mAngle));
		mAngle = 0;
		mWorld->AddActor(obj);
		mActiveObjects.push_back(obj);
		thisflip = false;

		for(int i = 0; i < mPlaceHolder.size(); ++i)
			mScene->RemoveRenderable(mPlaceHolder[i]);

		mPositions.clear();
		mPlaceHolder.clear();
	}

	if(mPositions.size() >= 2 && !mDrawLine && mCreationType == 3)
	{
		float length = mPositions[0 + 1].X - mPositions[0].X; 
		int numberLinks = (int)length/8;

		CreateChain(mPositions[0], numberLinks);

		for(int i = 0; i < mPlaceHolder.size(); ++i)
			mScene->RemoveRenderable(mPlaceHolder[i]);

		mPositions.clear();
		mPlaceHolder.clear();
	}

	if(mKeyboard->IsKeyDown('p'))
		ClearScene();

	if(mMouseJoint)
		mMouseJoint->SetTarget(b2Vec2(mMouse->GetMousePosition().X, mMouse->GetMousePosition().Y));

	mWorld->StepWorld(1.0f/60.f);
}

void DemoGame::ClearScene()
{
	if(mActiveObjects.empty());
	{
		for(int i = 0; i < mActiveObjects.size(); ++i)
		{
			mWorld->RemoveActor(mActiveObjects[i]);
		}
	}
}

void DemoGame::OnEnter()
{
	mWorld = new PhysicsWorld(mScene, ooge::Vector2(0,10), true);
	ooge::Sprite *bg = new ooge::Sprite("data/bg.png", "background", ooge::Vector2(512,384));
	bg->SetOrder(1000);
	bg->SetBlendMode(ooge::None);
	mScene->AddRenderable(bg);

	ooge::Sprite *grass = new ooge::Sprite("data/grass.png", "grass", ooge::Vector2(512,685));
	mScene->AddRenderable(grass);
	grass->SetOrder(1);
	ooge::ActorDescription des;
	ooge::PhysicsObject *g = new ooge::PhysicsObject(Vector2(0,700), Vector2(1024,700), &des, ooge::STATIC);
	mWorld->AddActor(g);
	ground = g->Getb2Body();

	ooge::Font *font = new ooge::Font("data/arial.ttf", 20);
	mText = new ooge::Text(font, "Object type: Static", ooge::Vector2(10,10));
	mText2 = new ooge::Text(font, "Square", ooge::Vector2(10,40));
	mScene->AddRenderable(mText2);
	mScene->AddRenderable(mText);
	mText->SetColour(0,0,0);
	mText2->SetColour(0,0,0);
}

void DemoGame::OnExit()
{
}