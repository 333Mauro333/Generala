#include "entity.h"

#include <iostream>

using std::cout;


Entity::Entity(Vector2f position)
{
	this->position = position;
	size = { 0.0f, 0.0f };
	active = true;

	cout << "Se ha creado una entidad.\n";
}
Entity::~Entity()
{
	cout << "La entidad se ha eliminado de la memoria.\n\n";
}

bool Entity::collisionWith(Entity* entity)
{
	return position.x + size.x > entity->getPosition().x && position.x < entity->getPosition().x + entity->getSize().x &&
		   position.y + size.y > entity->getPosition().y && position.y < entity->getPosition().y + entity->getSize().y;
}

void Entity::setActive(bool active)
{
	this->active = active;
}
void Entity::setSize(float w, float h)
{
	size = { w, h };
}
void Entity::setPosition(float x, float y)
{
	position = { x, y };
}

Vector2f Entity::getPosition()
{
	return position;
}
Vector2f Entity::getSize()
{
	return size;
}
bool Entity::isActive()
{
	return active;
}
