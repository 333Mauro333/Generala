#include "button.h"

#include <iostream>

#include "game_manager/game_manager.h"

using std::cout;


Button::Button(float x, float y, float w, float h, Color color) : Entity({x, y}, {w, h})
{
	this->color = color;
	rectangle.setPosition(x, y);
	rectangle.setSize({w, h});
	rectangle.setFillColor(color);

	cout << "Se ha creado un boton.\n";
}
Button::~Button()
{
	cout << "El boton ha sido eliminado de la memoria.\n";
}

void Button::update(float deltaTime)
{

}
void Button::draw()
{
	GameManager::window.draw(rectangle);
}
