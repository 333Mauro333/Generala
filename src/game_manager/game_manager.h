#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <iostream>

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
	RenderWindow* window;

	GameManager(unsigned int width, unsigned int height, const std::string windowTitle);
	~GameManager();

	void run();
};


#endif // !GAME_MANAGER_H
