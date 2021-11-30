#ifndef FADE_H
#define FADE_H

#include <SFML/Graphics.hpp>

using sf::RectangleShape;


class Fade
{
private:
	static RectangleShape blackRectangle;
	static bool fadeOut;
	static bool fadeIn;

public:
	static void fadeIn();
	static void fadeOut();
};

#endif // !FADE_H
