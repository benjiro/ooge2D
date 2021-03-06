#ifndef _PHYSICS_LISTENERS_HPP_
#define _PHYSICS_LISTENERS_HPP_

#include <Box2d.h>
#include <Config.hpp>

namespace ooge
{
	class OOGE_API ActorDestructionListener : public b2DestructionListener
	{
	public:
		virtual ~ActorDestructionListener() {}

		virtual void SayGoodbye(b2Joint *joint) = 0;
		virtual void SayGoodbye(b2Shape *shape) = 0;
	};

	class OOGE_API RayCastCallback : public b2RayCastCallback
	{
	public:
		virtual ~RayCastCallback() {}

		virtual float32 ReportFixture(b2Fixture* fixture, const b2Vec2& point,
									const b2Vec2& normal, float32 fraction) = 0;
	};

	class OOGE_API ContactFilter : public b2ContactFilter
	{
	public:
		virtual ~ContactFilter() {}

		virtual bool ShouldCollide(b2Shape *shape1, b2Shape *shape2);
	};

	class OOGE_API ContactListener : public b2ContactListener
	{
		virtual ~ContactListener() {}

		virtual void BeginContact(b2Contact* contact) { B2_NOT_USED(contact); }
		virtual void EndContact(b2Contact* contact) { B2_NOT_USED(contact); }
		virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
		{
			B2_NOT_USED(contact);
			B2_NOT_USED(oldManifold);
		}
		virtual void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse)
		{
			B2_NOT_USED(contact);
			B2_NOT_USED(impulse);
		}
	};

	class QueryCallback : public b2QueryCallback
	{
	public:
		virtual ~QueryCallback() {}

		virtual bool ReportFixture(b2Fixture* fixture) = 0;
	};
}

#endif //_PHYSICS_LISTENERS_HPP_