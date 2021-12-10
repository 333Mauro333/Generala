#ifndef ANNOTATIONS_H
#define ANNOTATIONS_H

#include <iostream>
#include "button/button.h"
#include "poster/poster.h"
#include "dice/dice.h"

using sf::Text;
using sf::Lines;
using std::string;


enum class CATEGORY { ONE = 1, TWO, THREE, FOUR, FIVE, SIX, STAIRS, FULL, POKER, GENERALA, DOUBLE_GENERALA };

struct POINTS
{
	unsigned int points;
	string str_points;
	Text text;

	Vector2f position;
	bool annotated;
};

class Annotations : public Entity
{
private:
	RectangleShape rectangle;
	RectangleShape line;
	RectangleShape line2;

	static const int posterSize = 13;
	Poster* poster[posterSize];
	POINTS points[12];
	sf::Font font;

	string convertToString(int num);

public:
	Annotations(float x, float y, float w, float h);
	~Annotations();

	void update(float deltaTime) override;
	void draw(RenderWindow* window) override;

	void updateScore(int ind);

	bool isInside(int x, int y) override;
	Poster* getPoster(int ind);
	int getPoints(CATEGORY category, Dice* dice[]);

	static int getPosterArraySize();
};

#endif // !ANNOTATIONS_H
