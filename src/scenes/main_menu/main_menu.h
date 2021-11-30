#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "scenes/scene.h"

#include "button/button.h"

using sf::Text;
using sf::Font;

class MainMenu : public Scene
{
private:
	Button* button[5];
	RenderWindow* win;

	RectangleShape back;
	Font font;
	Text gameTitle;

	const float wButtons = 200;
	const float hButtons = 100;

public:
	MainMenu(RenderWindow* win);
	~MainMenu();

	void init() override;
	void update(float deltaTime) override;
	void draw() override;
	void destroy() override;
};


#endif // !MAIN_MENU_H

