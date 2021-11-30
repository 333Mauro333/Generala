#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "scenes/scene.h"


class MainMenu : Scene
{
private:


public:
	MainMenu();
	~MainMenu();

	void init() override;
	void update(float deltaTime) override;
	void draw(RenderWindow window) override;
	void destroy() override;
};


#endif // !MAIN_MENU_H

