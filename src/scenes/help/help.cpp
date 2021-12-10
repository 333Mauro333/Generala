#include "help.h"

#include <iostream>

using std::cout;


Help::Help(RenderWindow* window) : Scene()
{
	this->window = window;
	poster = new Poster(window->getSize().x / 2.0f - window->getSize().x / 8.0f, window->getSize().y / 1.1f, window->getSize().x / 4.0f, window->getSize().y / 10.0f, Color::Yellow, Color::Blue);
	font.loadFromFile("res/fonts/segoepr.ttf");
	text.setFont(font);
	text.setCharacterSize(20);
	text.setString("Volver al menú");
	text.setOrigin(text.getGlobalBounds().width / 2.0f, text.getGlobalBounds().height / 2.0f);
	text.setPosition(window->getSize().x / 2.0f, window->getSize().y / 1.125f);

	cout << "Se ha creado una pantalla de ayuda.\n";
}
Help::~Help()
{
	cout << "La pantalla de ayuda ha sido eliminada de la memoria.\n";
}

void Help::update(float deltaTime)
{

}
void Help::draw()
{
	window->draw(back);
	window->draw(text);
}
void Help::destroy()
{

}
void Help::checkClicks(int x, int y)
{

}
