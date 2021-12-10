#include "dice.h"

#include <iostream>

#include "game_manager/game_manager.h"

using std::cout;
using std::string;
using sf::Mouse;


int Dice::amountOfLaunches = 0;

Dice::Dice(Vector2f position) : Entity(position)
{
	initTextures();

	originPosition = position;

	spr_dice.setTexture(tex_dices[0]);
	spr_dice.setOrigin(spr_dice.getGlobalBounds().width / 2.0f, spr_dice.getGlobalBounds().height / 2.0f);
	spr_dice.setPosition({ position.x, position.y });

	launching = false;
	selected = false;
	number = 1;

	cout << "Se ha creado un nuevo dice.\n";
}
Dice::~Dice()
{
	cout << "El dice ha sido eliminado de la memoria.\n";
}

void Dice::update(float deltaTime)
{
	if (selected)
	{
		spr_dice.setColor(sf::Color::Green);
	}
	else
	{
		spr_dice.setColor(sf::Color::White);
	}
}
void Dice::draw(RenderWindow* window)
{
	if (isActive())
	{
		window->draw(spr_dice);
	}
}

void Dice::select()
{
	selected = !selected;
}
void Dice::setRandomNumber(int randomNum)
{
	spr_dice = Sprite(tex_dices[randomNum - 1]);

	number = randomNum;
}
void Dice::launch()
{
	if (!isActive())
	{
		setActive(true);
	}

	if (!selected)
	{
		setRandomNumber(rand() % 6 + 1);
		spr_dice.setOrigin(spr_dice.getGlobalBounds().width / 2.0f, spr_dice.getGlobalBounds().height / 2.0f);
		spr_dice.setPosition(originPosition.x, originPosition.y);
	}
}
void Dice::activate()
{
	setActive(true);
}
void Dice::deactivate()
{
	setActive(false);
	selected = false;
}

bool Dice::isInside(int x, int y)
{
	return x >= spr_dice.getPosition().x - spr_dice.getGlobalBounds().width / 2.0f &&
	   	   x <= spr_dice.getPosition().x + spr_dice.getGlobalBounds().width / 2.0f &&
	   	   y >= spr_dice.getPosition().y - spr_dice.getGlobalBounds().height / 2.0f &&
	   	   y <= spr_dice.getPosition().y + spr_dice.getGlobalBounds().height / 2.0f;
}

Sprite Dice::getRenderer()
{
	return spr_dice;
}
int Dice::getNumber()
{
	return number;
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
	if (launching)
	{
		spr_dice.rotate(1200 * deltaTime);
		spr_dice.move(spr_dice.getPosition().x - 400.0f * deltaTime, 0.0f);

		if (spr_dice.getPosition().x < originPosition.x)
		{
			stop();
		}
	}
}
void Dice::stop()
{
	if (launching)
	{
		launching = false;
		spr_dice.setRotation(0);
	}
}
