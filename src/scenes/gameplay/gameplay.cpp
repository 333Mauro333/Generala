#include "gameplay.h"

#include <iostream>

using std::cout;


Gameplay::Gameplay(RenderWindow* win) : Scene()
{
	this->win = win;

	dices[0] = new Dice({ win->getSize().x / 6.0f * 1.0f, win->getSize().y / 1.25f }, { dices[0]->getRenderer().getGlobalBounds().width, dices[0]->getRenderer().getGlobalBounds().height });
	dices[1] = new Dice({ win->getSize().x / 6.0f * 2.0f, win->getSize().y / 1.25f }, { dices[1]->getRenderer().getGlobalBounds().width, dices[1]->getRenderer().getGlobalBounds().height });
	dices[2] = new Dice({ win->getSize().x / 6.0f * 3.0f, win->getSize().y / 1.25f }, { dices[2]->getRenderer().getGlobalBounds().width, dices[2]->getRenderer().getGlobalBounds().height });
	dices[3] = new Dice({ win->getSize().x / 6.0f * 4.0f, win->getSize().y / 1.25f }, { dices[3]->getRenderer().getGlobalBounds().width, dices[3]->getRenderer().getGlobalBounds().height });
	dices[4] = new Dice({ win->getSize().x / 6.0f * 5.0f, win->getSize().y / 1.25f }, { dices[4]->getRenderer().getGlobalBounds().width, dices[4]->getRenderer().getGlobalBounds().height });

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

}
void Gameplay::draw()
{

}
void Gameplay::destroy()
{

}
