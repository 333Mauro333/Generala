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
	static Texture tex_dices[6];
	Sprite spr_dice;
	bool launching;
	bool selected;
	Vector2f originPosition;

	static void initTextures();
	void rolling(float deltaTime);
	void stop();

public:
	static int amountOfLaunches;

	Dice(Vector2f position, Vector2f size);
	~Dice();

	void update(float deltaTime) override;
	void draw(RenderWindow* window) override;

	void setRandomNumber(int randomNum);
	void launch();

	Sprite getRenderer();
};

#endif // !DICE_H
