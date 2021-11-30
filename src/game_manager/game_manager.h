#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


class GameManager
{
private:
	void checkEvents();
	void init();
	void update(float deltaTime);
	void draw();
	void destroy();

public:
	int num = 0;
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(800, 600), "Soy el título");

	GameManager(unsigned int width, unsigned int height, const std::string windowTitle);
	~GameManager();

	void run();
};


#endif // !GAME_MANAGER_H
