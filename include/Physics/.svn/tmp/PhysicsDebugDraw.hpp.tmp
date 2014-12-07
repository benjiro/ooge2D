#ifndef _PHYSICS_DEBUG_DRAW_HPP_
#define _PHYSICS_DEBUG_DRAW_HPP_

#include <Dynamics/b2WorldCallbacks.h>
#include <Config.hpp>

namespace ooge
{
	class PhysicsDebugDraw : public b2DebugDraw
	{
		virtual void DrawPolygon(const b2Vec2* vertices, Int32 vertexCount, const b2Color& color);
		virtual void DrawSolidPolygon(const b2Vec2* vertices, Int32 vertexCount, const b2Color& color);
		virtual void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color);
		virtual void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color);
		virtual void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color);
		virtual void DrawTransform(const b2Transform& xf);
	};
};

#endif //_PHYSICS_DEBUG_DRAW_HPP_