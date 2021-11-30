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
	Entity(Vector2f position, Vector2f size);
	virtual ~Entity();

	virtual void update() = 0;
	virtual void draw() = 0;
	virtual bool collisionWith(Entity* entity);
	
	bool isClicked();

	Vector2f getPosition();
	Vector2f getSize();

private:
	Vector2f position;
	Vector2f size;
};


#endif // !ENTITY_H
