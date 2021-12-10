#include "annotations.h"

#include <iostream>

using std::cout;


Annotations::Annotations(float x, float y, float w, float h) : Entity({x, y})
{
	for (int i = 0; i < 11; i++)
	{
		points[i] = 0;
	}

	rectangle.setPosition(x, y);
	rectangle.setSize({ w, h });
	rectangle.setFillColor(Color::White);

	cout << "Se ha creado un anotador.\n";
}
Annotations::~Annotations()
{
	cout << "El anotador ha sido eliminado de la memoria.\n";
}

void Annotations::update(float deltaTime)
{

}
void Annotations::draw(RenderWindow* window)
{
	window->draw(rectangle);

	for (int i = 0; i < 11; i++)
	{
		buttons[i]->draw(window);
	}

	//buttons[0]->draw(window);
}

bool Annotations::isClicked(int x, int y)
{
	return true;
}
