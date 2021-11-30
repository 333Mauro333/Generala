#ifndef MENU_GAME_MODE
#define MENU_GAME_MODE

#include "scenes/scene.h"


class MenuGameMode : Scene
{
private:

public:
	MenuGameMode();
	~MenuGameMode();

	void init() override;
	void update(float deltaTime) override;
	void draw(RenderWindow window) override;
	void destroy() override;
};

#endif // !MENU_GAME_MODE
