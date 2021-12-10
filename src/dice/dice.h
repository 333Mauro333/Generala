#ifndef DICE_H
#define DICE_H

#include <SFML/Graphics.hpp>

#include "entity/entity.h"

using sf::Sprite;
using sf::Texture;
using sf::RenderWindow;


class Dice : public Entity
{
private:
	Texture tex_dices[6];
	Sprite spr_dice;
	bool launching;
	bool selected;
	Vector2f originPosition;

	void initTextures();
	void rolling(float deltaTime);
	void stop();

public:
	static int amountOfLaunches;

	Dice(Vector2f position);
	~Dice();

	void update(float deltaTime) override;
	void draw(RenderWindow* window) override;

	void setRandomNumber(int randomNum);
	void launch();

	bool isClicked(int x, int y) override;

	Sprite getRenderer();
};

#endif // !DICE_H
