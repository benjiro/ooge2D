#ifndef _TESTSTATE_HPP_
#define _TESTSTATE_HPP_

#include <string>
#include <vector>
#include "State.hpp"
#include <PhysicsListeners.hpp>
#include <PhysicsWorld.hpp>

class QCallBack : public ooge::QueryCallback
{
public:
	QCallBack(const b2Vec2& point)
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
	class PhysicsObject;
	class Scene; 
	class KeyboardListener;
	class MouseListener;
	class Text;
	class Controller;

	class DemoSprite : public ooge::State
	{
	public:
		DemoSprite(const std::string &name, ooge::Scene *scene);
		~DemoSprite();
		
		virtual void Update(float deltaT);
		virtual void OnEnter();
		virtual void OnExit();
	private:
		ooge::KeyboardListener *mKeyboard;
		ooge::MouseListener *mMouse;
		ooge::Scene *mScene;
		ooge::Text *mText;
		ooge::Controller *mController;
		b2Body *ground;
		b2MouseJoint *mMouseJoint;
	};
}

#endif //_TESTSTATE_HPP_