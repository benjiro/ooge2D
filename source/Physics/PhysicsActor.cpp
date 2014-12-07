#include <PhysicsActor.hpp>
#include <PhysicsWorld.hpp>
#include <Box2D.h>

using namespace ooge;

PhysicsActor::PhysicsActor()
: mBody(NULL)
{
}

PhysicsActor::~PhysicsActor()
{
	PhysicsWorld::GetSingletonPtr()->GetBox2DWorld()->DestroyBody(mBody);
}

void PhysicsActor::SetMass(Real mass, const Vector2 &centre, Real inerita)
{
	b2MassData massD;
	massD.mass = mass;
	massD.center.x = centre.X;
	massD.center.y = centre.Y;
	massD.I = inerita;

	mBody->SetMassData(&massD);
}

Real PhysicsActor::GetMass() const
{
	return mBody->GetMass();
}

Real PhysicsActor::GetInertia() const
{
	return mBody->GetInertia();
}

void PhysicsActor::ResetMass()
{
	mBody->ResetMassData();
}

void PhysicsActor::SetLinearVelocity(const Vector2 &v)
{
	mBody->SetLinearVelocity(b2Vec2(v.X, v.Y));
}

Vector2 PhysicsActor::GetLinearVelocity() const
{
	return Vector2(mBody->GetLinearVelocity().x, mBody->GetLinearVelocity().y);
}

void PhysicsActor::SetAngularVelocity(Real omega)
{
	mBody->SetAngularVelocity(omega);
}

Real PhysicsActor::GetAngularVelocity() const
{
	return mBody->GetAngularVelocity();
}

Vector2 PhysicsActor::GetLocalCentre() const
{
	return Vector2(mBody->GetLocalCenter().x, mBody->GetLocalCenter().y);
}

Vector2 PhysicsActor::GetWorldCentre() const
{
	return Vector2(mBody->GetWorldCenter().x, mBody->GetWorldCenter().x);
}

void PhysicsActor::SetTransform(const Vector2 &position, Real angle)
{
	mBody->SetTransform(b2Vec2(position.X, position.Y), angle);
}

Vector2 PhysicsActor::GetPosition() const
{
	return Vector2(mBody->GetPosition().x, mBody->GetPosition().y);
}

Real PhysicsActor::GetAngle() const
{
	return mBody->GetAngle();
}

void PhysicsActor::ApplyForce(const Vector2 &force, const Vector2 &point)
{
	mBody->ApplyForce(b2Vec2(force.X, force.Y), b2Vec2(point.X, point.Y));
}

void PhysicsActor::ApplyTorque(Real torque)
{
	mBody->ApplyTorque(torque);
}

void PhysicsActor::ApplyLinearImpulse(const Vector2 &impluse, const Vector2 &point)
{
	mBody->ApplyLinearImpulse(b2Vec2(impluse.X, impluse.Y), b2Vec2(point.X, point.Y));
}

void PhysicsActor::ApplyAngularImpulse(Real impulse)
{
	mBody->ApplyAngularImpulse(impulse);
}

void PhysicsActor::SetLinearDamping(Real linear)
{
	mBody->SetLinearDamping(linear);
}

Real PhysicsActor::GetLinearDamping() const
{
	return mBody->GetLinearDamping();
}

void PhysicsActor::SetAngularDamping(Real angular)
{
	mBody->SetAngularDamping(angular);
}

Real PhysicsActor::GetAngularDamping() const
{
	return mBody->GetAngularDamping();
}

void *PhysicsActor::GetUserData() const
{
	return mBody->GetUserData();
}

void PhysicsActor::SetUserData(void *data)
{
	mBody->SetUserData(data);
}

void PhysicsActor::SetActive(bool flag)
{
	mBody->SetActive(flag);
}

bool PhysicsActor::IsActive() const
{
	return mBody->IsActive();
}

void PhysicsActor::SetAwake(bool flag)
{
	mBody->SetAwake(flag);
}

bool PhysicsActor::IsAwake() const
{
	return mBody->IsAwake();
}

b2Body *PhysicsActor::Getb2Body() const
{
	return mBody;
}

void PhysicsActor::_InitActor(const ooge::ActorDescription *des)
{
	b2FixtureDef def;

	def.density = des->Density;
	def.friction = des->Friction;
	def.isSensor = des->IsSensor;
	def.restitution = des->Restitution;
	def.userData = des->UserData;
	def.shape = des->Shape;

	mBody->CreateFixture(&def);
}
