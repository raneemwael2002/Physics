#pragma once
#include "Particle.h"
#include"AABBCollider.h"
#include <list>

using namespace std;

class PhysicsWorld
{
private:
	list<Particle*> particles;
public:
	void addParticle(Particle* particle);
	void Update(float deltaTime);
	void CheckTwoCircleCollision();

	void SATcollision();
	void CheckAABBcollision();

	static const Vector2d gravity;

};