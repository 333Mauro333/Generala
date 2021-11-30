#include "credits.h"

#include <iostream>

using std::cout;


Credits::Credits(RenderWindow* win) : Scene()
{
	this->win = win;

	cout << "Se ha creado una pantalla de creditos.\n";
}
Credits::~Credits()
{
	cout << "La pantalla de creditos se ha eliminado de la memoria.\n";
}

void Credits::init()
{

}
void Credits::update(float deltaTime)
{

}
void Credits::draw()
{

}
void Credits::destroy()
{

}
