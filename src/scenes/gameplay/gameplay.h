#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "scenes/scene.h"
#include "dice/dice.h"
#include "button/button.h"
#include "annotations/annotations.h"

using sf::RenderWindow;
using sf::Font;
using sf::Text;


class Gameplay : public Scene
{
private:
	RenderWindow* window;
	RectangleShape back;

	Button* buttonThrow;
	Dice* dices[5];

	Annotations* annotations;

	Font font;
	Text textMessage;

	int count;

	void showMessagePoints(CATEGORY category);

public:
	Gameplay(RenderWindow* window);
	~Gameplay();

	void update(float deltaTime) override;
	void draw() override;
	void destroy() override;
	void checkClicks(int x, int y) override;
	void checkMouseCollision(int x, int y);
};

#endif // !GAMEPLAY_H
