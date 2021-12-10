#include <SFML/Graphics.hpp>
#include "game_manager/game_manager.h"


int main()
{
	GameManager* gameManager = new GameManager(600, 800, "GENERALA");
	gameManager->run();

	return 0;
}
