#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

using sf::RenderWindow;


class GameManager
{
private:
	void checkEvents();
	void init();
	void update(float deltaTime);
	void draw();
	void destroy();

public:
	RenderWindow* window = new RenderWindow(sf::VideoMode(600, 800), "Generala");

	GameManager(unsigned int width, unsigned int height, const std::string windowTitle);
	~GameManager();

	void run();
};


#endif // !GAME_MANAGER_H
