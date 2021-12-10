#ifndef ANNOTATIONS_H
#define ANNOTATIONS_H

#include "button/button.h"


class Annotations : public Entity
{
private:
	RectangleShape* rectangle;

	RectangleShape* bars[13];
	int points[11];

public:
	Annotations(float x, float y, float w, float h);
	~Annotations();

	void update(float deltaTime) override;
	void draw(RenderWindow* window) override;

	bool isClicked(int x, int y) override;
};

#endif // !ANNOTATIONS_H
