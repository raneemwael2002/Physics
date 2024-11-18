#include "Particle.h"
#include "PhysicsWorld.h"
#include "Collider.h"
#include"Vector2d.h"
Particle::Particle(Vector2d postion, float mass, float drag)
{	
	this->postion = postion;
	this->velocity = Vector2d(0, 0);
	this->forces = Vector2d(1, 1);
	this->mass = mass;
	this->drag = drag;
	this->collider.center = postion;
	this->collider.r = 20;
	collider_aabb.ul = Vector2d(0, 0); 
	collider_aabb.lr = Vector2d(40, 40);

	this->collider_aabb.updatePosition(postion);
	this->collider_sat.updatePosition(postion);
	collider_sat.points.push_back(postion);
	collider_sat.points.push_back (Vector2d((postion.x+40), postion.y));
	collider_sat.points.push_back(Vector2d((postion.x + 40), postion.y+40));
	collider_sat.points.push_back(Vector2d(postion.x , (postion.y+40)));


}

void Particle::Update(float dt)
{

	if (velocity.getMagnitude() > 0) {
		float d = drag * velocity.getMagnitude();
		Vector2d dd =velocity * -0.5f;
		Vector2d dragForce = dd * d;

		forces += dragForce;
	}

	acceleration = forces *(1.0f/ mass);
	//velocity = acceleration * dt;
	postion += velocity * dt;
	forces = Vector2d(0, 0);
	collider.center = postion;
	collider_aabb.updatePosition(postion);
	collider_sat.updatePosition(postion);

}

void Particle::addForce(Vector2d force)
{
	forces += force;

}
