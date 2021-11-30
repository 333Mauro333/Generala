#ifndef MENU_GAME_MODE
#define MENU_GAME_MODE

#include "scenes/scene.h"


class MenuGameMode : Scene
{
private:
	RenderWindow* win;

public:
	MenuGameMode(RenderWindow* window);
	~MenuGameMode();

	void init() override;
	void update(float deltaTime) override;
	void draw() override;
	void destroy() override;
};

#endif // !MENU_GAME_MODE
