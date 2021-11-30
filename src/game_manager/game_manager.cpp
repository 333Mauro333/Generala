#include "game_manager.h"

#include <iostream>

#include "scene_manager/scene_manager.h"
#include "scenes/main_menu/main_menu.h"

using std::cout;


GameManager::GameManager(unsigned int width, unsigned int height, const std::string windowTitle)
{
	window.create(sf::VideoMode(width, height), windowTitle);

	cout << "Se ha creado un GameManager.\n";
}
GameManager::~GameManager()
{
	cout << "El GameManager ha sido eliminado de la memoria.\n\n";
}

void GameManager::run()
{
    init();

    while (window.isOpen())
    {
        sf::Clock clock;
        float elapsedTime = clock.getElapsedTime().asSeconds();

        update(elapsedTime);

        draw();
    }
    
}

void GameManager::init()
{
    SceneManager::chargeNewScene(new MainMenu());
}
void GameManager::update(float deltaTime)
{
    checkEvents();

    SceneManager::getActualScene()->update(deltaTime);
}
void GameManager::draw()
{
    window.clear();

    SceneManager::getActualScene()->draw();

    window.display();
}
void GameManager::destroy()
{
    // Se 
}
void GameManager::checkEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}