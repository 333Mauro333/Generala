#include "main_menu.h"

#include <iostream>

#include "scene_manager/scene_manager.h"
#include "scenes/gameplay/gameplay.h"

using std::cout;


MainMenu::MainMenu(RenderWindow* window) : Scene()
{
	this->window = window;

	back.setSize({ static_cast<float>(window->getSize().x), static_cast<float>(window->getSize().y) });
	back.setFillColor(Color::Color(141, 73, 37));

	button[0] = new Button(window->getSize().x / 2.0f, window->getSize().y / 6 * 2.3f - hButtons / 2.0f, wButtons, hButtons, Color::Yellow, "JUGAR");
	button[1] = new Button(window->getSize().x / 2.0f, window->getSize().y / 6 * 3.1f - hButtons / 2.0f, wButtons, hButtons, Color::Yellow, "OPCIONES");
	button[2] = new Button(window->getSize().x / 2.0f, window->getSize().y / 6 * 3.9f - hButtons / 2.0f, wButtons, hButtons, Color::Yellow, "AYUDA");
	button[3] = new Button(window->getSize().x / 2.0f, window->getSize().y / 6 * 4.7f - hButtons / 2.0f, wButtons, hButtons, Color::Yellow, "CREDITOS");
	button[4] = new Button(window->getSize().x / 2.0f, window->getSize().y / 6 * 5.5f - hButtons / 2.0f, wButtons, hButtons, Color::Yellow, "SALIR");

	font.loadFromFile("res/fonts/over_the_rainbow.ttf");
	gameTitle.setFont(font);
	gameTitle.setCharacterSize(40);
	gameTitle.setFillColor(Color::White);
	gameTitle.setString("GENERALA");
	gameTitle.setOrigin(gameTitle.getGlobalBounds().width / 2.0f, gameTitle.getGlobalBounds().height / 2.0f);
	gameTitle.setPosition(window->getSize().x / 2.0f, window->getSize().y / 7.0f);

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
	window->draw(back);

	for (int i = 0; i < 5; i++)
	{
		button[i]->draw(window);
	}

	window->draw(gameTitle);
}
void MainMenu::destroy()
{

}

void MainMenu::checkClicks(int x, int y)
{
	if (button[0]->isInside(x, y))
	{
		SceneManager::chargeNewScene(new Gameplay(window));
	}
}
