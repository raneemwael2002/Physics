#include "PhysicsWorld.h"
#include "Collider.h"

void PhysicsWorld::addParticle(Particle* particle)
{
	particles.push_back(particle);

}

void PhysicsWorld::Update(float deltaTime) {
	
	for (auto* particle : particles) {
		particle->addForce(particle->forces * particle->mass);
		particle->Update(deltaTime);

	}
}
void PhysicsWorld::CheckAABBcollision()
{
	list<Particle*>::iterator it;
	for (it = particles.begin(); it != particles.end(); ++it)
	{
		Particle* p1 = *it;
		AABBCollider c1 = p1->collider_aabb;

		for (auto itt = std::next(it); itt != particles.end(); ++itt)
		{
			Particle* p2 = *itt;
			AABBCollider c2 = p2->collider_aabb;

			if (c1.checkCollision(c2))
			{
				std::cout << "AABB collision!\n";

				Vector2d v1 = p1->velocity;
				float m1 = p1->mass;

				Vector2d v2 = p2->velocity;
				float m2 = p2->mass;
				Vector2d temp = p1->velocity;
				float massTotal = p1->mass + p2->mass;


				v1.x = ((m1 - m2) / massTotal) + (2 * ((m2 / massTotal) * v2.x));
				v1.y = ((m1 - m2) / massTotal) + (2 * ((m2 / massTotal) * v2.y));

				v2.x = ((m2 - m1) / massTotal) + (2 * ((m1 / massTotal) * temp.x));
				v2.y = ((m2 - m1) / massTotal) + (2 * ((m1 / massTotal) * temp.y));


				p1->velocity = v1;
				p2->velocity = v2;

				std::cout << "P1 Velocity: " << p1->velocity.x << ", " << p1->velocity.y << std::endl;
				std::cout << "P2 Velocity: " << p2->velocity.x << ", " << p2->velocity.y << std::endl;
			}
		}
	}
}
void PhysicsWorld::CheckTwoCircleCollision()
{

	list<Particle*>::iterator it;
	list<Particle*>::iterator begin = particles.begin();
	list<Particle*>::iterator beforend = particles.end();
	beforend--;

	for (it = particles.begin(); it != beforend; it++) {

		Particle* p1 = *it;
		Collider c1 = p1->collider;

		list<Particle*>::iterator itt;
		itt = particles.begin();
		itt++;
		for (; itt != particles.end(); itt++) {

			Particle* p2 = *itt;
			Collider c2 = p2->collider;

			if (c1.checkCollision(c2)) {

				std::cout << "collision!\n" << std::endl;

				Vector2d v1 = p1->velocity;
				float m1 = p1->mass;

				Vector2d v2 = p2->velocity;
				float m2 = p2->mass;
				Vector2d temp = p1->velocity;
				float massTotal = p1->mass + p2->mass;


				v1.x = ((m1 - m2) / massTotal) + (2 * ((m2 / massTotal) * v2.x));
				v1.y = ((m1 - m2) / massTotal) + (2 * ((m2 / massTotal) * v2.y));

				v2.x = ((m2 - m1) / massTotal) + (2 * ((m1 / massTotal) * temp.x));
				v2.y = ((m2 - m1) / massTotal) + (2 * ((m1 / massTotal) * temp.y));


				p1->velocity = v1;
				p2->velocity = v2;

				std::cout << "P1 Velocity: " << p1->velocity.x << ", " << p1->velocity.y << std::endl;
				std::cout << "P2 Velocity: " << p2->velocity.x << ", " << p2->velocity.y << std::endl;


			}

		}



	}

}



void PhysicsWorld::SATcollision()
{
	std::list<Particle*>::iterator it;
	for (it = particles.begin(); it != particles.end(); ++it)
	{
		Particle* p1 = *it;
		SATCollider c1 = p1->collider_sat;

		for (auto itt = std::next(it); itt != particles.end(); ++itt)
		{
			Particle* p2 = *itt;
			SATCollider c2 = p2->collider_sat;

			
			if (c1.checkCollision(c2))
			{
				std::cout << "SAT collision!\n";



				Vector2d v1 = p1->velocity;
				float m1 = p1->mass;

				Vector2d v2 = p2->velocity;
				float m2 = p2->mass;
				Vector2d temp = p1->velocity;
				float massTotal = p1->mass + p2->mass;
				

				v1.x = ((m1 - m2) / massTotal) + (2 * ((m2 / massTotal) * v2.x));
				v1.y = ((m1 - m2) / massTotal) + (2 * ((m2 / massTotal) * v2.y));
					
				v2.x = ((m2 - m1) / massTotal) + (2 * ((m1 / massTotal) * temp.x));
				v2.y = ((m2 - m1) / massTotal) + (2 * ((m1 / massTotal) * temp.y));


				p1->velocity = v1;
				p2->velocity = v2;

				std::cout << "P1 Velocity: " << p1->velocity.x << ", " << p1->velocity.y << std::endl;
				std::cout << "P2 Velocity: " << p2->velocity.x << ", " << p2->velocity.y << std::endl;


			}
		}
	}
}
