#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "scenes/scene.h"

#include "button/button.h"

class MainMenu : public Scene
{
private:
	Button* button;
	sf::RenderWindow* win;

public:
	MainMenu(sf::RenderWindow* win);
	~MainMenu();

	void init() override;
	void update(float deltaTime) override;
	void draw() override;
	void destroy() override;
};


#endif // !MAIN_MENU_H

