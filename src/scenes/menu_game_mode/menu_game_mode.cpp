#include "menu_game_mode.h"

#include <iostream>

using std::cout;


MenuGameMode::MenuGameMode(RenderWindow* win) : Scene()
{
	this->win = win;

	cout << "Se ha creado una pantalla de modo de juego.\n";
}
MenuGameMode::~MenuGameMode()
{
	cout << "La pantalla de modo de juego ha sido eliminada de la memoria.\n";
}

void MenuGameMode::init()
{

}
void MenuGameMode::update(float deltaTime)
{

}
void MenuGameMode::draw()
{

}
void MenuGameMode::destroy()
{

}
