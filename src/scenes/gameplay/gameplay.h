#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "scenes/scene.h"


class Gameplay : Scene
{
private:
	RenderWindow* win;

public:
	Gameplay(RenderWindow* window);
	~Gameplay();

	void init() override;
	void update(float deltaTime) override;
	void draw() override;
	void destroy() override;
};

#endif // !GAMEPLAY_H