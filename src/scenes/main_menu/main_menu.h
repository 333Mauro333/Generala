#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "scenes/scene.h"


class MainMenu : public Scene
{
private:


public:
	MainMenu();
	~MainMenu();

	void init() override;
	void update(float deltaTime) override;
	void draw() override;
	void destroy() override;
};


#endif // !MAIN_MENU_H

