#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "scenes/scene.h"
#include "dice/dice.h"

using sf::RenderWindow;


class Gameplay : public Scene
{
private:
	Dice* dices[5];
	RenderWindow window;

public:
	Gameplay();
	~Gameplay();

	void init() override;
	void update(float deltaTime) override;
	void draw() override;
	void destroy() override;

	SCENE_TYPE getSceneType() override;
};

#endif // !GAMEPLAY_H
