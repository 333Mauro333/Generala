#ifndef BUTTON_H
#define BUTTON_H

#include "entity/entity.h"

#include "SFML/Graphics.hpp"

using sf::Color;
using sf::RectangleShape;
using sf::RenderWindow;

class Button : public Entity
{
private:
	RectangleShape rectangle;
	Color color;

public:
	Button(float x, float y, float w, float h, Color color);
	~Button();

	void update(float deltaTime) override;
	void draw(RenderWindow* window) override;
};

#endif // !BUTTON_H
