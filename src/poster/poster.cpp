#include "poster.h"

using std::cout;


Poster::Poster(float x, float y, float w, float h, Color color, Color border = Color::Black) : Entity({ x, y })
{
	this->color = color;
	this->border = border;
	preSelected = false;
	inhabilited = false;

	rectangle.setPosition(x, y);
	rectangle.setSize({ w, h });
	rectangle.setFillColor(border);
	internalRectangle.setPosition(x + 3, y + 3);
	internalRectangle.setSize({ w - 6, h - 6 });
	internalRectangle.setFillColor(color);

	cout << "Se ha creado un cartel.\n";
}
Poster::~Poster()
{
	cout << "El cartel ha sido eliminado de la memoria.\n";
}

void Poster::update(float deltaTime)
{

}
void Poster::draw(RenderWindow* window)
{
	window->draw(rectangle);
	window->draw(internalRectangle);
	window->draw(text);
}

void Poster::shine()
{
	if (!inhabilited)
	{
		preSelected = true;
		rectangle.setFillColor(Color(200, 200, 200));
		internalRectangle.setFillColor(Color(200, 200, 200));
	}
}
void Poster::opaque()
{
	if (!inhabilited)
	{
		preSelected = false;
		rectangle.setFillColor(border);
		internalRectangle.setFillColor(color);
	}
}
void Poster::inhabilite()
{
	rectangle.setFillColor(Color(100, 100, 100));
	inhabilited = true;
}

bool Poster::isInside(int x, int y)
{
	return x >= rectangle.getPosition().x &&
		   x <= rectangle.getPosition().x + rectangle.getSize().x &&
		   y >= rectangle.getPosition().y &&
		   y <= rectangle.getPosition().y + rectangle.getSize().y;
}
bool Poster::isShining()
{
	return preSelected;
}
bool Poster::isInhabilited()
{
	return inhabilited;
}

void Poster::setTextConfiguration(string display, Color color, unsigned int size, int x, int y)
{
	if (!font.loadFromFile("res/fonts/segoepr.ttf"))
	{
		cout << "ERROR";
	}
	else
	{
		cout << "La fuente ha sido cargada exitosamente.\n";
	}

	text.setFont(font);
	text.setFillColor(color);
	text.setStyle(sf::Text::Bold);
	text.setString(display);
	text.setCharacterSize(size);
	text.setPosition(x + 10.0f, y + 5.0f);
}
