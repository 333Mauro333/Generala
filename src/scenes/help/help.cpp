#include "help.h"

#include <iostream>

#include "scene_manager/scene_manager.h"
#include "scenes/main_menu/main_menu.h"

using std::cout;


Help::Help(RenderWindow* window) : Scene()
{
	this->window = window;
	back.setFillColor(Color(175, 0, 0));
	back.setSize({ static_cast<float>(window->getSize().x), static_cast<float>(window->getSize().y) });

	poster = new Poster(window->getSize().x / 2.0f - window->getSize().x / 6.0f, window->getSize().y / 1.2f, window->getSize().x / 3.0f, window->getSize().y / 10.0f, Color::Yellow, Color::Blue);
	font.loadFromFile("res/fonts/segoepr.ttf");
	text.setFont(font);
	text.setCharacterSize(20);
	text.setString("Volver al menú");
	text.setOrigin(text.getGlobalBounds().width / 2.0f, text.getGlobalBounds().height / 2.0f);
	text.setPosition(window->getSize().x / 2.0f, window->getSize().y / 1.125f);
	text.setFillColor(Color::Black);

	instructions.setFont(font);
	instructions.setCharacterSize(20);
	string allInstructions = "";
	allInstructions += "La generala es un juego de mesa muy conocido. En esta\n";
	allInstructions += "versión se va a poder jugar de a uno.\n";
	allInstructions += "Para comenzar, se tiran los dados. Se pueden hacer\n";
	allInstructions += "hasta 3 tiros consecutivos, pero se puede terminar\n";
	allInstructions += "el turno antes si el jugador lo prefiere.\n";
	allInstructions += "El objetivo del juego es completar todas las categorías\n";
	allInstructions += "con la mayor cantidad de puntaje posible.\n";
	allInstructions += "Las categorias son las siguientes:\n";
	allInstructions += "NÚMEROS: Dan tantos puntos como cantidad se hayan\n";
	allInstructions += "sumado. Por ejemplo, cuatro números 3 son 12 puntos\n";
	allInstructions += "para el tres. Dos números 6 son 12 puntos para el seis.\n";
	allInstructions += "ESCALERA: \"1 2 3 4 5\" o \"2 3 4 5 6\". 20 puntos.\n";
	allInstructions += "FULL: Tres números iguales y un par. 30 puntos.\n";
	allInstructions += "PÓKER: 4 números iguales. Son 40 puntos.\n";
	allInstructions += "GENERALA: Los 5 números iguales. 60 puntos.\n";
	allInstructions += "La doble generala también vale 60 puntos.\n";
	instructions.setString(allInstructions);
	instructions.setPosition(10.0f, 50.0f);
	instructions.setFillColor(Color::Black);

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
	window->draw(instructions);
	poster->draw(window);
	window->draw(text);
}
void Help::destroy()
{
	delete poster;
}
void Help::checkClicks(int x, int y)
{
	if (poster->isInside(x, y))
	{
		SceneManager::chargeNewScene(new MainMenu(window));
	}
}
