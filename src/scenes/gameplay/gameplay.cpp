#include "gameplay.h"

#include <iostream>

using std::cout;


Gameplay::Gameplay(RenderWindow* win) : Scene()
{
	this->win = win;

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
