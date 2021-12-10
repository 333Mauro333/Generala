#include "game_manager.h"

#include <iostream>

#include "scene_manager/scene_manager.h"
#include "scenes/main_menu/main_menu.h"

using std::cout;



GameManager::GameManager(unsigned int width, unsigned int height, const std::string windowTitle)
{
    window = new RenderWindow(sf::VideoMode(width, height), windowTitle);

	cout << "Se ha creado un GameManager.\n";
}
GameManager::~GameManager()
{
	cout << "El GameManager ha sido eliminado de la memoria.\n\n";
}

void GameManager::run()
{
    init();

    while (window->isOpen())
    {
        sf::Clock clock;
        float elapsedTime = clock.getElapsedTime().asSeconds();

        update(elapsedTime);

        draw();
    }
    
    destroy();
}

void GameManager::init()
{
    SceneManager::chargeNewScene(new MainMenu(window));
}
void GameManager::update(float deltaTime)
{
    checkEvents();

    SceneManager::getActualScene()->update(deltaTime);
}
void GameManager::draw()
{
    window->clear();

    SceneManager::getActualScene()->draw();

    window->display();
}
void GameManager::destroy()
{
    SceneManager::getActualScene()->destroy();
}
void GameManager::checkEvents()
{
    sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window->close();
        }

        if (event.type == sf::Event::MouseButtonPressed)
        {
            SceneManager::getActualScene()->checkClicks(event.mouseButton.x, event.mouseButton.y);

            std::cout << "new mouse x: " << event.mouseButton.x << std::endl;
            std::cout << "new mouse y: " << event.mouseButton.y << std::endl;
        }

        if (event.type == sf::Event::MouseMoved)
        {
            SceneManager::getActualScene()->checkMouseCollision(event.mouseMove.x, event.mouseMove.y);
        }
    }
}
