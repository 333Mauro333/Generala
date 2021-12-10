#include "gameplay.h"

#include <iostream>

using std::cout;


Gameplay::Gameplay(RenderWindow* window) : Scene()
{
	this->window = window;

	buttonThrow = new Button(window->getSize().x / 2.0f, window->getSize().y / 1.1f, window->getSize().x / 3.0f, window->getSize().y / 10.0f, Color::Blue, "Tirar");

	dices[0] = new Dice({ window->getSize().x / 6.0f * 1.0f, window->getSize().y / 1.25f });
	dices[1] = new Dice({ window->getSize().x / 6.0f * 2.0f, window->getSize().y / 1.25f });
	dices[2] = new Dice({ window->getSize().x / 6.0f * 3.0f, window->getSize().y / 1.25f });
	dices[3] = new Dice({ window->getSize().x / 6.0f * 4.0f, window->getSize().y / 1.25f });
	dices[4] = new Dice({ window->getSize().x / 6.0f * 5.0f, window->getSize().y / 1.25f });

	for (int i = 0; i < 5; i++)
	{
		dices[i]->setActive(false);
	}

	cout << "Se ha creado una pantalla de gameplay.\n";
}
Gameplay::~Gameplay()
{
	cout << "La pantalla de gameplay ha sido eliminada de la memoria.\n";
}

void Gameplay::init()
{

}
void Gameplay::update(float deltaTime)
{
	for (int i = 0; i < 5; i++)
	{
		dices[i]->update(deltaTime);
	}
}
void Gameplay::draw()
{
	for (int i = 0; i < 5; i++)
	{
		dices[i]->draw(window);
	}

	buttonThrow->draw(window);
}
void Gameplay::destroy()
{
	for (int i = 0; i < 5; i++)
	{
		delete dices[i];
	}
}

void Gameplay::checkClicks(int x, int y)
{
	for (int i = 0; i < 5; i++)
	{
		if (dices[i]->isClicked(x, y))
		{
			cout << "Clicked " << i + 1 << "!\n";
			dices[i]->select();
		}
	}

	if (buttonThrow->isClicked(x, y))
	{
		for (int i = 0; i < 5; i++)
		{
			dices[i]->launch();
		}
	}
}

SCENE_TYPE Gameplay::getSceneType()
{
	return SCENE_TYPE::MAIN_MENU;
}
