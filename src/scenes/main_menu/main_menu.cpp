#include "main_menu.h"

#include <iostream>

using std::cout;


MainMenu::MainMenu(RenderWindow* win) : Scene()
{
	this->win = win;
	button = new Button(10, 10, 300, 200, Color::Green);

	cout << "Se ha creado una pantalla de menu principal.\n";
}
MainMenu::~MainMenu()
{
	cout << "La pantalla de menu principal ha sido eliminada de la memoria.\n";
}

void MainMenu::init()
{

}
void MainMenu::update(float deltaTime)
{

}
void MainMenu::draw()
{
	button->draw(win);
}
void MainMenu::destroy()
{

}
