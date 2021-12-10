#include "gameplay.h"

#include <iostream>

using std::cout;


Gameplay::Gameplay() : Scene()
{
	dices[0] = new Dice({ window.getSize().x / 6.0f * 1.0f, window.getSize().y / 1.25f });
	dices[1] = new Dice({ window.getSize().x / 6.0f * 2.0f, window.getSize().y / 1.25f });
	dices[2] = new Dice({ window.getSize().x / 6.0f * 3.0f, window.getSize().y / 1.25f });
	dices[3] = new Dice({ window.getSize().x / 6.0f * 4.0f, window.getSize().y / 1.25f });
	dices[4] = new Dice({ window.getSize().x / 6.0f * 5.0f, window.getSize().y / 1.25f });

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

SCENE_TYPE Gameplay::getSceneType()
{
	return SCENE_TYPE::MAIN_MENU;
}
