#include "GameManager.h"

#include <iostream>

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

void GameManager::init()
{
    // Se llama al init de la escena.
}
void GameManager::update(float deltaTime)
{
    init();

    while (window.isOpen())
    {
        checkEvents();

        // Obtener la escena actual para hacer el update.
        
        draw();
    }

    destroy();
}
void GameManager::draw()
{
    window.clear();

    // Se dibuja lo que tenga la escena.

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