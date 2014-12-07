#ifndef _PHYSICS_ACTOR_HPP_
#define _PHYSICS_ACTOR_HPP_

#include <Box2d.h>
#include <Config.hpp>
#include <Vector2.hpp>
#include <ActorDescription.hpp>

namespace ooge
{
	class OOGE_API PhysicsActor
	{
	public:
		PhysicsActor();
		~PhysicsActor();

		void SetMass(Real mass, const Vector2 &centre, Real inerita);
		Real GetMass() const;
		Real GetInertia() const;
		void ResetMass();

		void SetLinearVelocity(const Vector2 &v);
		Vector2 GetLinearVelocity() const;

		void SetAngularVelocity(Real omega);
		Real GetAngularVelocity() const;

		Vector2 GetLocalCentre() const;
		Vector2 GetWorldCentre() const;

		void SetTransform(const Vector2 &position, Real angle);
		Vector2 GetPosition() const;
		Real GetAngle() const;

		void ApplyForce(const Vector2 &force, const Vector2 &point);
		void ApplyTorque(Real torque);
		void ApplyLinearImpulse(const Vector2 &impluse, const Vector2 &point);
		void ApplyAngularImpulse(Real impulse);

		Vector2 GetLocalPoint(const Vector2 &worldPoint) const;
		Vector2 GetLocalVector(const Vector2 &worldVector) const;
		Vector2 GetLinearVelocityFromWorldPoint(const Vector2 &worldPoint) const;
		Vector2 GetLinearVelocityFromLocalPoint(const Vector2 &localPoint) const;

		void SetLinearDamping(Real linear);
		Real GetLinearDamping() const;

		void SetAngularDamping(Real angular);
		Real GetAngularDamping() const;

		void *GetUserData() const;
		void SetUserData(void *data);

		void SetActive(bool flag);
		bool IsActive() const;
		void SetAwake(bool flag);
		bool IsAwake() const;

		b2Body *Getb2Body() const;
	private:
		friend class PhysicsObject;
		friend class PhysicsWorld;

		void _InitActor(const ActorDescription *des);
		
		b2Body *mBody;
	};
}

#endif //_PHYSICS_ACTOR_HPP_