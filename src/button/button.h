#ifndef BUTTON_H
#define BUTTON_H

#include "entity/entity.h"

#include "SFML/Graphics.hpp"

using sf::RectangleShape;
using sf::RenderWindow;
using sf::Color;
using sf::Font;
using sf::Text;
using std::string;


enum class OPTION { JUGAR, OPCIONES, AYUDA, CREDITOS, SALIR };

class Button : public Entity
{
private:
	RectangleShape rectangle;
	RectangleShape internalRectangle;
	Color color;
	Font font;
	Text text;

public:
	Button(float x, float y, float w, float h, Color color, string display);
	~Button();

	bool isClicked(int x, int y) override;

	void update(float deltaTime) override;
	void draw(RenderWindow* window) override;

	void setString(string name);

	Text getText();
};

#endif // !BUTTON_H
