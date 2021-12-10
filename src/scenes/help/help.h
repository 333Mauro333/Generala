#ifndef HELP_H
#define HELP_H

#include "SFML/Graphics.hpp"
#include "scenes/scene.h"
#include "poster/poster.h"

using sf::RenderWindow;
using sf::RectangleShape;
using sf::Font;
using sf::Text;

class Help : public Scene
{
private:
	RenderWindow* window;

	RectangleShape back;
	Poster* poster;

	Font font;
	Text text;
	Text instructions;

public:
	Help(RenderWindow* window);
	~Help();

	void update(float deltaTime) override;
	void draw() override;
	void destroy() override;
	void checkClicks(int x, int y) override;

};


#endif // !HELP_H
