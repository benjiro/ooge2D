#ifndef _PHYSICS_OBJECT_HPP_
#define _PHYSICS_OBJECT_HPP_

#include <PhysicsActor.hpp>

namespace ooge
{
	class Circle;
	class Sprite;
	class Square;
	class Renderable;

	enum PhysicsObjectType
	{
		STATIC,
		KINEMATIC,
		DYNAMIC
	};

	enum PhysicsShapeType
	{
		SQUARE,
		CIRCLE,
		CONVEX,
	};

	class OOGE_API PhysicsObject : public PhysicsActor
	{
	public:
		PhysicsObject(Circle *circle, ActorDescription *des, const PhysicsObjectType type);
		PhysicsObject(Square *sqaure, ActorDescription *des, const PhysicsObjectType type);
		PhysicsObject(Sprite *sprite, ActorDescription *des, const PhysicsObjectType type, const PhysicsShapeType shapetype);
		PhysicsObject(Int32 width, Int32 height, ActorDescription *des, const PhysicsObjectType type);
		PhysicsObject(Vector2 &startPos, Vector2 &endPos, ActorDescription *des, const PhysicsObjectType type);

		~PhysicsObject();

		Renderable *GetRenderable() const;
		void SetRenderable(Renderable *renderable) { mRenderable = renderable; }

		void Update();
	private:
		void _CreateConvex(b2PolygonShape *shape);

		Renderable *mRenderable;
	};
}

#endif //_PHYSICS_OBJECT_HPP_