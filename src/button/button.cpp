#include "button.h"

#include <iostream>

#include "game_manager/game_manager.h"
#include "scenes/credits/credits.h"

using std::cout;
using sf::RenderWindow;


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
void Button::draw(RenderWindow* window)
{
	window->draw(rectangle);
}
