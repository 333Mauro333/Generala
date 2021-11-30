#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

using sf::RenderWindow;


class GameManager
{
private:
	RenderWindow window;

	void checkEvents();

public:
	GameManager(unsigned int width, unsigned int height, const std::string windowTitle);
	~GameManager();

	void init();
	void update(float deltaTime);
	void draw();
	void destroy();
};


#endif // !GAME_MANAGER_H
