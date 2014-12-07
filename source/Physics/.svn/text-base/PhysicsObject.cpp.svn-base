#include <PhysicsObject.hpp>
#include <PhysicsWorld.hpp>
#include <Square.hpp>
#include <Circle.hpp>
#include <Sprite.hpp>
#include <Image.hpp>

using namespace ooge;

PhysicsObject::PhysicsObject(Circle *circle, ActorDescription *des, const PhysicsObjectType type)
: PhysicsActor(), mRenderable(circle)
{
	b2BodyDef bodyDef;

	switch(type)
	{
	case STATIC: bodyDef.type = b2_staticBody; break;
	case KINEMATIC: bodyDef.type = b2_staticBody; break;
	case DYNAMIC: bodyDef.type = b2_dynamicBody; break;
	};

	bodyDef.position.Set(des->Position.X, des->Position.Y);

	mBody = PhysicsWorld::GetSingletonPtr()->GetBox2DWorld()->CreateBody(&bodyDef);

	b2CircleShape pCircle;
	pCircle.m_radius = circle->GetRadius()/1.9;
	des->Shape = &pCircle;

	PhysicsActor::_InitActor(des);
}

PhysicsObject::PhysicsObject(Square *square, ActorDescription *des, const PhysicsObjectType type)
: PhysicsActor(), mRenderable(square)
{
	b2BodyDef bodyDef;

	switch(type)
	{
	case STATIC: bodyDef.type = b2_staticBody; break;
	case KINEMATIC: bodyDef.type = b2_staticBody; break;
	case DYNAMIC: bodyDef.type = b2_dynamicBody; break;
	};

	bodyDef.position.Set(des->Position.X, des->Position.Y);
	mBody = PhysicsWorld::GetSingletonPtr()->GetBox2DWorld()->CreateBody(&bodyDef);

	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(square->GetWidth()/2, square->GetHeight()/2);
	des->Shape = &dynamicBox;

	PhysicsActor::_InitActor(des);
}

PhysicsObject::PhysicsObject(Sprite *sprite, ActorDescription *des, const PhysicsObjectType type, const PhysicsShapeType shapetype)
: PhysicsActor(), mRenderable(sprite)
{
	b2BodyDef bodyDef;

	switch(type)
	{
	case STATIC: bodyDef.type = b2_staticBody; break;
	case KINEMATIC: bodyDef.type = b2_staticBody; break;
	case DYNAMIC: bodyDef.type = b2_dynamicBody; break;
	};

	bodyDef.position.Set(des->Position.X, des->Position.Y);
	mBody = PhysicsWorld::GetSingletonPtr()->GetBox2DWorld()->CreateBody(&bodyDef);

	if(shapetype == SQUARE)
	{
		b2PolygonShape shape;
		shape.SetAsBox(sprite->GetImage()->GetWidth()/2, sprite->GetImage()->GetHeight()/2);
		des->Shape = &shape;
		PhysicsActor::_InitActor(des);
	}
	else if(shapetype == CONVEX)
	{
		b2PolygonShape shape;
		_CreateConvex(&shape);
		des->Shape = &shape;
		PhysicsActor::_InitActor(des);
	}
	else
	{
		b2CircleShape shape;
		shape.m_radius = sprite->GetImage()->GetWidth()/2.1f;
		des->Shape = &shape;
		PhysicsActor::_InitActor(des);
	}
}

PhysicsObject::PhysicsObject(Int32 width, Int32 height, ActorDescription *des, const PhysicsObjectType type)
: PhysicsActor(), mRenderable(0)
{
	b2BodyDef bodyDef;

	switch(type)
	{
	case STATIC: bodyDef.type = b2_staticBody; break;
	case KINEMATIC: bodyDef.type = b2_staticBody; break;
	case DYNAMIC: bodyDef.type = b2_dynamicBody; break;
	};

	bodyDef.position.Set(des->Position.X, des->Position.Y);
	mBody = PhysicsWorld::GetSingletonPtr()->GetBox2DWorld()->CreateBody(&bodyDef);

	b2PolygonShape shape;
	shape.SetAsBox(width/2, height/2);
	des->Shape = &shape;

	PhysicsActor::_InitActor(des);
}

PhysicsObject::PhysicsObject(Vector2 &startPos, Vector2 &endPos, ActorDescription *des, const PhysicsObjectType type)
: PhysicsActor(), mRenderable(0)
{
	b2BodyDef bodyDef;

	switch(type)
	{
	case STATIC: bodyDef.type = b2_staticBody; break;
	case KINEMATIC: bodyDef.type = b2_staticBody; break;
	case DYNAMIC: bodyDef.type = b2_dynamicBody; break;
	};

	bodyDef.position.Set(des->Position.X, des->Position.Y);
	mBody = PhysicsWorld::GetSingletonPtr()->GetBox2DWorld()->CreateBody(&bodyDef);

	b2PolygonShape shape;
	shape.SetAsEdge(b2Vec2(startPos.X, startPos.Y), b2Vec2(endPos.X, endPos.Y));
	des->Shape = &shape;

	PhysicsActor::_InitActor(des);
}

PhysicsObject::~PhysicsObject()
{
}

void PhysicsObject::Update()
{
	if(mRenderable)
	{
		mRenderable->SetPosition(mBody->GetPosition().x, mBody->GetPosition().y);
		mRenderable->SetRotation(math::ToDegrees(mBody->GetAngle()));
	}
}

void PhysicsObject::_CreateConvex(b2PolygonShape *shape)
{
	Sprite *sprite = dynamic_cast<Sprite*>(mRenderable);
	std::vector<ColourUInt8> &pixels = sprite->GetImage()->GetPixelBuffer();

	Int32 top = sprite->GetImage()->GetHeight() - 1;
	Int32 bottom = 0;
	Int32 left = sprite->GetImage()->GetWidth() - 1;
	Int32 right = 0;

	Vector2 diagonalBottomLeft(-1,-1);
	diagonalBottomLeft.Normalise();
	Vector2 diagonalTopLeft(-1, 1);
	diagonalTopLeft.Normalise();
	Vector2 diagonalTopRight(1, 1);
	diagonalTopRight.Normalise();
	Vector2 diagonalBottomRight(1, -1);
	diagonalBottomRight.Normalise();

	Real diaBL = -10000000000000.0f;
	Real diaTL = -10000000000000.0f;
	Real diaTR = -10000000000000.0f;
	Real diaBR = -10000000000000.0f;

	Vector2 centreImage(sprite->GetImage()->GetWidth() / 2.0f, sprite->GetImage()->GetHeight() / 2.0f);

	for(Int32 y = 0; y < sprite->GetImage()->GetHeight(); ++y)
	{
		for(Int32 x = 0; x < sprite->GetImage()->GetWidth(); ++x)
		{
			if(pixels[x * y].A != 0)
			{
				if(y < top)
					top = y;
				if(y > bottom)
					bottom = y;
				if(x < left)
					left = x;
				if(x > right)
					right = x;

				ooge::Vector2 realtivePixel = ooge::Vector2(x,y) - centreImage;
				Real distanceBL = realtivePixel.DotProduct(diagonalBottomLeft);
				Real distanceTL = realtivePixel.DotProduct(diagonalTopLeft);
				Real distanceTR = realtivePixel.DotProduct(diagonalTopRight);
				Real distanceBR = realtivePixel.DotProduct(diagonalBottomRight);

				if(distanceBL > diaBL)
					diaBL = distanceBL;
				if(distanceTL > diaTL)
					diaTL = distanceTL;
				if(distanceTR > diaTR)
					diaTR = distanceTR;
				if(distanceBR > diaBR)
					diaBR = distanceBR;
			}
		}
	}
	Vector2 dir(1.5,1.5);
	Vector2 dir2(3.14,3.14);

	//
	Vector2 vert1 = ((diagonalBottomLeft * (diaBL - left)) * (dir * diagonalBottomLeft) / pow((dir * diagonalBottomLeft).Normalise(),2));
	Vector2 vert2 = ((diagonalTopLeft * (diaTL - top)) * (dir2 * diagonalTopLeft) / pow((dir2 * diagonalTopLeft).Normalise(), 2));
	Vector2 vert3 = ((diagonalTopRight * (diaTR - right)) * (dir * diagonalTopRight) / pow((dir * diagonalTopRight).Normalise(), 2));
	Vector2 vert4 = ((diagonalBottomRight * (diaTR - bottom)) * (dir2 * diagonalBottomRight) / pow((dir2 * diagonalBottomRight).Normalise(), 2));

	vert3.X *= -1;
	vert3.Y *= -1;
	vert4.X *= -1;
	vert4.Y *= -1;
	b2Vec2 vertices[4];
	vertices[0].Set(vert1.X, vert1.Y);
	vertices[1].Set(vert2.X, vert2.Y);
	vertices[2].Set(vert3.X, vert3.Y);
	vertices[3].Set(vert4.X, vert4.Y);

	shape->Set(vertices, 4);
}

Renderable *PhysicsObject::GetRenderable() const
{
	return mRenderable;
}