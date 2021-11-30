#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "scenes/scene.h"
#include "dice/dice.h"

class Gameplay : Scene
{
private:
	RenderWindow* win;
	Dice* dices[5];

public:
	Gameplay(RenderWindow* window);
	~Gameplay();

	void init() override;
	void update(float deltaTime) override;
	void draw() override;
	void destroy() override;
};

#endif // !GAMEPLAY_H
