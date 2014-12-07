#ifndef _PHYSICS_WORLD_HPP_
#define _PHYSICS_WORLD_HPP_

#include <Box2D.h>
#include <Config.hpp>
#include <Vector2.hpp>
#include <PhysicsListeners.hpp>
#include <PhysicsDebugDraw.hpp>
#include <Singleton.hpp>
#include <vector>

namespace ooge
{
	class Scene;
	class PhysicsObject;

	typedef b2Joint Joint;
	typedef b2JointDef JointDef;
	typedef b2RevoluteJointDef RevoluteDef;
	typedef b2PrismaticJointDef PrismaticDef;
	typedef b2DistanceJointDef DistanceDef;
	typedef b2PulleyJointDef PulleyDef;
	typedef b2MouseJointDef MouseDef;
	typedef b2GearJointDef GearDef;
	typedef b2LineJointDef LineDef;
	typedef b2WeldJointDef WeldDef;
	typedef b2FrictionJointDef FrictionDef;

	class OOGE_API PhysicsWorld : public Singleton<PhysicsWorld>
	{
	public:
		PhysicsWorld(Scene *scene, const Vector2 &gravity, bool sleep, bool debugDraw = false);
		~PhysicsWorld();

		void AddActor(PhysicsObject *actor);
		void RemoveActor(PhysicsObject *actor);

		Joint *CreateJoint(JointDef *def);
		void DestoryJoint(Joint *joint);

		void SetDestructionListener(ActorDestructionListener *listener);
		void SetContactFilter(ContactFilter *listener);
		void SetContactListener(ContactListener *listener);

		void StepWorld(Real timeStep);

		b2World *GetBox2DWorld() const;

		static PhysicsWorld &GetSingleton();
		static PhysicsWorld *GetSingletonPtr();
	protected:
		void _ClearWorld();
	private:
		void _DebugDrawing();

		typedef std::vector<PhysicsObject*>::iterator WorldIt;
		typedef std::vector<PhysicsObject*>::const_iterator ConstWorldIt;
		std::vector<PhysicsObject*> mWorldObjects;

		PhysicsDebugDraw *mDebugDraw;
		b2World *mb2World;
		Scene *mScene;
	};
}

#endif //_PHYSICS_WORLD_HPP