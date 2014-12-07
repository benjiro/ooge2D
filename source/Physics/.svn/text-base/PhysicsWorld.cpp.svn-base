#include <PhysicsWorld.hpp>
#include <PhysicsObject.hpp>
#include <Scene.hpp>

using namespace ooge;

template<> PhysicsWorld *Singleton<PhysicsWorld>::ms_Singleton = 0;

PhysicsWorld::PhysicsWorld(Scene *scene, const Vector2 &gravity, bool sleep, bool debugDraw)
: mScene(scene), mDebugDraw(0)
{
	mb2World = new b2World(b2Vec2(gravity.X, gravity.Y), sleep);

	if(debugDraw)
	{
		mDebugDraw = new PhysicsDebugDraw();
		_DebugDrawing();
	}
}

PhysicsWorld::~PhysicsWorld()
{
	_ClearWorld();
	if(mb2World)
		delete mb2World;
}

void PhysicsWorld::AddActor(PhysicsObject *actor)
{
	if(actor->GetRenderable() != NULL)
		mScene->AddRenderable(actor->GetRenderable());
	mWorldObjects.push_back(actor);
}

void PhysicsWorld::RemoveActor(PhysicsObject *actor)
{
	if(actor->GetRenderable())
		mScene->RemoveRenderable(actor->GetRenderable());

	WorldIt it = mWorldObjects.begin();
	for(; it != mWorldObjects.end(); ++it)
	{
		if((*it) == actor)
		{
			delete (*it);
			mWorldObjects.erase(it);
			return;
		}
	}
}

void PhysicsWorld::_ClearWorld()
{
	WorldIt it = mWorldObjects.begin();
	for(; it != mWorldObjects.end(); ++it)
	{
		if((*it)->GetRenderable())
			mScene->RemoveRenderable((*it)->GetRenderable());
		delete (*it);
	}
	mWorldObjects.clear();
}

Joint *PhysicsWorld::CreateJoint(JointDef *def)
{
	return mb2World->CreateJoint(def);
}

void PhysicsWorld::DestoryJoint(Joint *joint)
{
	mb2World->DestroyJoint(joint);
}

void PhysicsWorld::SetDestructionListener(ActorDestructionListener *listener)
{
	mb2World->SetDestructionListener(listener);
}

void PhysicsWorld::SetContactFilter(ContactFilter *listener)
{
	mb2World->SetContactFilter(listener);
}

void PhysicsWorld::SetContactListener(ContactListener *listener)
{
	mb2World->SetContactListener(listener);
}

void PhysicsWorld::_DebugDrawing()
{
	mb2World->SetDebugDraw(mDebugDraw);
}

void PhysicsWorld::StepWorld(Real timeStep)
{
	ConstWorldIt it = mWorldObjects.begin();
	for(; it != mWorldObjects.end(); ++it)
	{
		if((*it)->mBody->IsActive())
		{
			(*it)->Update();
		}
	}

	mb2World->Step(timeStep, 10,10);

	if(mDebugDraw)
	{
		mb2World->DrawDebugData();
	}
}

b2World *PhysicsWorld::GetBox2DWorld() const
{
	return mb2World;
}

PhysicsWorld &PhysicsWorld::GetSingleton()
{
	assert(ms_Singleton);
	return (*ms_Singleton);
}

PhysicsWorld *PhysicsWorld::GetSingletonPtr()
{
	return ms_Singleton;
}