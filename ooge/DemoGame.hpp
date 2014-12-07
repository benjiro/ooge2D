#ifndef _DEMO_GAME_HPP
#define _DEMO_GAME_HPP

#include <string>
#include <vector>
#include "State.hpp"
#include <PhysicsListeners.hpp>
#include <PhysicsWorld.hpp>
#include <PhysicsObject.hpp>

class QCallBack1 : public ooge::QueryCallback
{
public:
	QCallBack1(const b2Vec2& point)
	{
		m_point = point;
		m_fixture = NULL;
	}

	bool ReportFixture(b2Fixture* fixture)
	{
		b2Body* body = fixture->GetBody();
		if (body->GetType() == b2_dynamicBody)
		{
			bool inside = fixture->TestPoint(m_point);
			if (inside)
			{
				m_fixture = fixture;

				// We are done, terminate the query.
				return false;
			}
		}

		// Continue the query.
		return true;
	}

	b2Vec2 m_point;
	b2Fixture* m_fixture;
};

namespace ooge
{
	class PhysicsWorld;
	class Scene; 
	class KeyboardListener;
	class MouseListener;
	class Text;
	class Controller;
	class Square;

	class DemoGame : public ooge::State
	{
	public:
		DemoGame(const std::string &name, ooge::Scene *scene);
		~DemoGame();

		void CreateObject(Vector2 &position, int type);
		void CreateChain(Vector2 &position, int number);
		void ClearScene();
		
		virtual void Update(float deltaT);
		virtual void OnEnter();
		virtual void OnExit();
	private:
		ooge::KeyboardListener *mKeyboard;
		ooge::MouseListener *mMouse;
		ooge::Scene *mScene;
		ooge::Text *mText;
		ooge::Text *mText2;
		ooge::PhysicsWorld *mWorld;
		b2Body *ground;
		b2MouseJoint *mMouseJoint;
		std::vector<PhysicsObject*> mActiveObjects;
		std::vector<Renderable*> mPlaceHolder;
		std::vector<Vector2> mPositions;
		Sprite *mDrawLineObj;
		float mAngle;
		Vector2 mPosition;

		bool mObjectType;
		bool mDrawLine;
		int mCreationType;
		ooge::PhysicsObjectType mPhysType;
	};
}

#endif //_DEMO_GAME_HPP