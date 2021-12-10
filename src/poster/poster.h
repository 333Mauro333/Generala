#ifndef POSTER_H
#define POSTER_H

#include <iostream>
#include "SFML/Graphics.hpp"
#include "entity/entity.h"

using std::string;
using sf::RectangleShape;
using sf::Font;
using sf::Text;
using sf::Color;


class Poster : public Entity
{
private:
	Color color;
	Color border;
	RectangleShape rectangle;
	RectangleShape internalRectangle;
	Font font;
	Text text;
	bool preSelected;
	bool inhabilited;

public:
	Poster(float x, float y, float w, float h, Color color, Color border);
	~Poster();

	void update(float deltaTime) override;
	void draw(RenderWindow* window) override;
	
	void shine();
	void opaque();
	void inhabilite();

	bool isInside(int x, int y) override;
	bool isShining();
	bool isInhabilited();

	void setTextConfiguration(string display, Color color, unsigned int size, int x, int y);
};

#endif // !POSTER_H
