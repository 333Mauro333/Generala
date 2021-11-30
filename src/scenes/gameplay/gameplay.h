#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "scenes/scene.h"


class Gameplay : Scene
{
private:

public:
	Gameplay();
	~Gameplay();

	void init() override;
	void update(float deltaTime) override;
	void draw(RenderWindow window) override;
	void destroy() override;
};

#endif // !GAMEPLAY_H
