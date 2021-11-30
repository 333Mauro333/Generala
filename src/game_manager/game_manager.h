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
	GameManager(unsigned int width, unsigned int height, const std::string windowTitle);
	~GameManager();

	void run();

	static RenderWindow window;
};


#endif // !GAME_MANAGER_H
