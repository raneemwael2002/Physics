#include<SFML/Graphics.hpp>

#include"Vector2d.h"
#include"Renderer.h"
#include"Particle.h"
#include"PhysicsWorld.h"
#include <iostream>
int main() {

	sf::RenderWindow window(sf::VideoMode(600, 600), "PHYSICS!");
	//sf::RectangleShape shape(sf::Vector2f(40.f, 40.f)); 
	//sf::RectangleShape shape2(sf::Vector2f(40.f, 40.f));
	sf::CircleShape shape(20.f); 
	sf::CircleShape shape2(20.f);
	
	window.setFramerateLimit(60);

	shape.setFillColor(sf::Color::Red);
	shape2.setFillColor(sf::Color::Yellow);

	
	Renderer render;

	render.AddDrawable(&shape);
	render.AddDrawable(&shape2);

	PhysicsWorld world;

	Particle p(Vector2d(20, 20), 1, 1);		
	Particle p2(Vector2d(400, 20), 1, 1);	

	
	float radius = shape.getRadius();   //Circleshape
	float radius2 = shape2.getRadius(); //Circleshape

	//float width = shape.getPosition().x;	//Rectshape
	//float height = shape.getPosition().y;   //Rectshape



	//p.collider_aabb.ul = p.collider_aabb.position;			//Rect
	//p.collider_aabb.lr = p.collider_aabb.position + Vector2d(width, height);  //Rect

	//p2.collider_aabb.ul = p2.collider_aabb.position ;   //Rect
	//p2.collider_aabb.lr = p2.collider_aabb.position + Vector2d(width, height);	//Rect

	p.collider_aabb.ul = p.collider_aabb.position;		//Circle
	p.collider_aabb.lr = p.collider_aabb.position + Vector2d(2 * radius, 2 * radius);   //Circle

	p2.collider_aabb.ul = p2.collider_aabb.position;			//Circle
	p2.collider_aabb.lr = p2.collider_aabb.position + Vector2d(2 * radius, 2 * radius);	//Circle


	world.addParticle(&p);
	world.addParticle(&p2);


	Clock clock;
	float dt = 0.02f;

	p.velocity = (Vector2d(50.f, 0));
	p2.velocity = (Vector2d(-50.f, 0));


	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {
				window.close();
			}



		}


		world.CheckTwoCircleCollision();
		//world.CheckAABBcollision();
	  // world.SATcollision();
		world.Update(dt);
		
		

		shape.setPosition(p.postion.x, p.postion.y);
		shape2.setPosition(p2.postion.x, p2.postion.y);

		render.Render(&window);

	}


}


