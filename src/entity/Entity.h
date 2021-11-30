#ifndef ENTITY_H
#define ENTITY_H


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

	virtual void update() = 0;
	virtual void draw();
	virtual void collisionWith(Entity* entity);

	Vector2f getPosition();

private:
	Vector2f position;
};


#endif // !ENTITY_H
