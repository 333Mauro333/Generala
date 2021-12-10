#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "scenes/scene.h"
#include "game_manager/game_manager.h"
#include "button/button.h"

using sf::RenderWindow;
using sf::Text;
using sf::Font;

class MainMenu : public Scene
{
private:
	RenderWindow* window;
	
	Button* button[3];

	RectangleShape back;
	Font font;
	Font font2;
	Text gameTitle;
	Text credits;

	const float wButtons = 200;
	const float hButtons = 100;


public:
	MainMenu(RenderWindow* window);
	~MainMenu();

	void update(float deltaTime) override;
	void draw() override;
	void destroy() override;
	void checkClicks(int x, int y) override;
};

#endif // !MAIN_MENU_H

