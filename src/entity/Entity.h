#ifndef ENTITY_H
#define ENTITY_H

#include "SFML/Graphics.hpp"

using sf::RenderWindow;


struct Vector2f
{
	float x;
	float y;
};

class Entity
{
public:
	Entity(Vector2f position);
	virtual ~Entity();

	virtual void update(float deltaTime) = 0;
	virtual void draw(RenderWindow* window) = 0;
	virtual bool collisionWith(Entity* entity);
	
	virtual bool isClicked(int x, int y);

	void setSize(float x, float y);

	Vector2f getPosition();
	Vector2f getSize();

private:
	Vector2f position;
	Vector2f size;
};


#endif // !ENTITY_H
