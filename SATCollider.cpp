#include "SATCollider.h"

void SATCollider::updatePosition(Vector2d position)
{
	Vector2d delta = this->position - position;
	for (int i = 0; i < points.size(); i++)
	{
		points[i] -= delta;

	}

	this->position = position;
}


bool SATCollider::checkCollision(SATCollider other)
{

	vector<Vector2d> normals = getNormals();
	for (int i = 0; i < normals.size(); i++) {

		Vector2d otherShape = other.projectShape(normals[i]);
		Vector2d shape = projectShape(normals[i]);

		if (shape.y < otherShape.x) return false;
		if (shape.x > otherShape.y) return false;

	}

	normals = other.getNormals();
	for (int i = 0; i < normals.size(); i++) {

		Vector2d otherShape = other.projectShape(normals[i]);
		Vector2d shape = projectShape(normals[i]);

		if (shape.y < otherShape.x || shape.x > otherShape.y) return false;
		
	}

	return true;
}

vector<Vector2d> SATCollider::getNormals()
{
	vector<Vector2d> normals;
	for (int i = 0; i < points.size()-1; i++) {

		Vector2d side = points[i + 1] - points[i];
		normals.push_back(side.getNormal().getNormalized());

	}

	Vector2d side = points[0] - points[points.size() - 1];
	normals.push_back(side.getNormal().getNormalized());

	return normals;
}

Vector2d SATCollider::projectShape(Vector2d axis)
{

	float dot = points[0].Dot(axis);
	float min = dot;
	float max = dot;

	for (int i = 1; i < points.size(); i++) {

		dot = points[i].Dot(axis);
		if (dot < min)min = dot;
		if (dot < max)max = dot;


	}

	return Vector2d(min,max);
}
