#include "entity.h"

#include <iostream>

using std::cout;


Entity::Entity(Vector2f position, Vector2f size)
{
	this->position = position;
	this->size = size;

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
Vector2f Entity::getPosition()
{
	return position;
}
Vector2f Entity::getSize()
{
	return size;
}
