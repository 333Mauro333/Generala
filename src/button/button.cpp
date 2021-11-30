#include "button.h"

#include <iostream>
#include <SFML/System.hpp>

#include "game_manager/game_manager.h"
#include "scenes/credits/credits.h"

using std::cout;


Button::Button(float w, float h, float x, float y, Color color, string display) : Entity({x, y}, {w, h})
{
	this->color = color;

	rectangle.setSize({w, h});
	rectangle.setOrigin(rectangle.getGlobalBounds().width / 2.0f, rectangle.getGlobalBounds().height / 2.0f);
	rectangle.setPosition(x, y);
	rectangle.setFillColor(Color::Color(239, 127, 26));

	internalRectangle.setSize({ w / 1.05f, h / 1.05f });
	internalRectangle.setOrigin(internalRectangle.getGlobalBounds().width / 2.0f, internalRectangle.getGlobalBounds().height / 2.0f);
	internalRectangle.setPosition(x, y);
	internalRectangle.setFillColor(color);

	if (!font.loadFromFile("res/fonts/segoepr.ttf"))
	{
		cout << "ERROR";
	}
	text.setFont(font);
	text.setFillColor(sf::Color::Red);
	text.setStyle(sf::Text::Bold);
	text.setString(display);

	float multiplier = 0.0f;

	if (display == "JUGAR")
	{
		multiplier = 1.1f;
	}
	else if (display == "OPCIONES")
	{
		multiplier = 1.25f;
	}
	else if (display == "AYUDA")
	{
		multiplier = 1.1f;
	}
	else if (display == "CREDITOS")
	{
		multiplier = 1.25f;
	}
	else if(display == "SALIR")
	{
		multiplier = 1.1f;
	}

	text.setCharacterSize(w * multiplier / text.getString().getSize());
	text.setOrigin(text.getGlobalBounds().width / 2.0f, text.getGlobalBounds().height / 2.0f);
	text.setPosition({ rectangle.getPosition().x, rectangle.getPosition().y});


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
	window->draw(internalRectangle);
	window->draw(text);
}
