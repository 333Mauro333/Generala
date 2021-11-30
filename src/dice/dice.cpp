#include "dice.h"

#include <iostream>

using std::cout;
using std::string;


int Dice::amountOfLaunches = 0;
Texture Dice::tex_dices[6];

Dice::Dice(Vector2f position, Vector2f size) : Entity(position, size)
{
	spr_dice.setTexture(tex_dices[0]);
	spr_dice.setOrigin(spr_dice.getGlobalBounds().width / 2.0f, spr_dice.getGlobalBounds().height / 2.0f);
	spr_dice.setPosition({ position.x, position.y });

	launching = false;
	selected = false;

	cout << "Se ha creado un nuevo dice.\n";
}
Dice::~Dice()
{
	cout << "El dice ha sido eliminado de la memoria.\n";
}

void Dice::update(float deltaTime)
{

}
void Dice::draw(RenderWindow* window)
{
	window->draw(spr_dice);
}

void Dice::setRandomNumber(int randomNum)
{
	spr_dice = Sprite(tex_dices[randomNum - 1]);
}
void Dice::launch()
{
	if (!selected && !launching && amountOfLaunches >= 3)
	{

	}
}

void Dice::initTextures()
{
	for (int i = 0; i < 6; i++)
	{
		string str_file = "";
		str_file += "res/sprites/gameplay/dice_";
		str_file += static_cast<char>((i + 1) + 48);
		str_file += ".png";

		tex_dices[i].loadFromFile(str_file);
	}
}
void Dice::rolling(float deltaTime)
{
	spr_dice.rotate(1200 * deltaTime);
}
void Dice::stop()
{
	launching = false;
	spr_dice.setRotation(0);
}
