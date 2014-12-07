#ifndef _ACTOR_DESCRIPTION_HPP_
#define _ACTOR_DESCRIPTION_HPP_

#include <Vector2.hpp>

namespace ooge
{
	struct OOGE_API ActorDescription
	{
		ActorDescription()
		{
			UserData = NULL;
			GroupID = 0;
			Position.Set(0.0f, 0.0f);
			Angle = 0.0f;
			LinearVelocity.Set(0.0f, 0.0f);
			AngularVelocity = 0.0f;
			LinearDamping = 0.0f;
			AngularDamping = 0.0f;
			Friction = 0.2f;
			Restitution = 0.0f;
			Density = 0.0f;
			AllowSleep = true;
			Awake = true;
			FixedRotation = false;
			Active = true;
			Bullet = false;
			IsSensor = false;
			Shape = NULL;
		}

		virtual ~ActorDescription() {}

		void *UserData;
		Vector2 Position;
		Vector2 LinearVelocity;
		Int16 GroupID;
		Real AngularVelocity;
		Real LinearDamping;
		Real AngularDamping;
		Real Friction;
		Real Restitution;
		Real Density;
		Real Angle;
		bool AllowSleep;
		bool Awake;
		bool FixedRotation;
		bool Bullet;
		bool Active;
		bool IsSensor;
		b2Shape *Shape;
	};
}

#endif //_ACTOR_DESCRIPTION_HPP_