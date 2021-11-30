#ifndef BUTTON_H
#define BUTTON_H

#include "entity/entity.h"

#include "SFML/Graphics.hpp"

using sf::Color;
using sf::RectangleShape;
using sf::RenderWindow;
using std::string;


enum class OPTION { JUGAR, OPCIONES, AYUDA, CREDITOS, SALIR };

class Button : public Entity
{
private:
	RectangleShape rectangle;
	RectangleShape internalRectangle;
	Color color;
	sf::Font font;
	sf::Text text;

public:
	Button(float x, float y, float w, float h, Color color, string display);
	~Button();

	void update(float deltaTime) override;
	void draw(RenderWindow* window) override;
};

#endif // !BUTTON_H
