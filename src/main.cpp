#include <SFML/Graphics.hpp>
#include "game_manager/game_manager.h"


int main()
{
	GameManager* gameManager = new GameManager(640, 480, "T�tulo escrito ac�");
	gameManager->run();

	return 0;
}
