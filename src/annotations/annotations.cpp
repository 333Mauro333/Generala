#include "annotations.h"

#include <iostream>

using std::cout;


Annotations::Annotations(float x, float y, float w, float h) : Entity({x, y})
{
	srand(time(NULL));

	if (!font.loadFromFile("res/fonts/segoepr.ttf"))
	{
		cout << "ERROR";
	}
	else
	{
		cout << "La fuente ha sido cargada exitosamente.\n";
	}

	for (int i = 0; i < 12; i++)
	{
		points[i].points = 0;
		points[i].position = { x + w / 1.125f, y + h / 13 * (i + 1) };
		points[i].text.setFont(font);
		points[i].text.setFillColor(Color::Black);
		points[i].text.setPosition(points[i].position.x, points[i].position.y);
		points[i].text.setString("0");
		points[i].annotated = false;
	}

	rectangle.setPosition(x, y);
	rectangle.setSize({ w, h });
	rectangle.setFillColor(Color(200, 200, 200));

	line.setPosition({ x + w / 2.0f, y });
	line.setSize({ 2.0f, h });
	line.setFillColor(Color::Black);

	line2.setPosition({ x + w / 2.0f + (w / 4.0f), y });
	line2.setSize({ 2.0f, h });
	line2.setFillColor(Color::Black);

	for (int i = 0; i < posterSize; i++)
	{
		poster[i] = new Poster(x, y + (h / 13 * i), w, h / 13, Color::Magenta, Color(128, 128, 128, 128));
	}

	poster[0]->setTextConfiguration("JUGADORES", Color::Black, 20, static_cast<int>(poster[0]->getPosition().x), static_cast<int>(poster[0]->getPosition().y));
	poster[1]->setTextConfiguration("UNO", Color::Black, 20, static_cast<int>(poster[1]->getPosition().x), static_cast<int>(poster[1]->getPosition().y));
	poster[2]->setTextConfiguration("DOS", Color::Black, 20, static_cast<int>(poster[2]->getPosition().x), static_cast<int>(poster[2]->getPosition().y));
	poster[3]->setTextConfiguration("TRES", Color::Black, 20, static_cast<int>(poster[3]->getPosition().x), static_cast<int>(poster[3]->getPosition().y));
	poster[4]->setTextConfiguration("CUATRO", Color::Black, 20, static_cast<int>(poster[4]->getPosition().x), static_cast<int>(poster[4]->getPosition().y));
	poster[5]->setTextConfiguration("CINCO", Color::Black, 20, static_cast<int>(poster[5]->getPosition().x), static_cast<int>(poster[5]->getPosition().y));
	poster[6]->setTextConfiguration("SEIS", Color::Black, 20, static_cast<int>(poster[6]->getPosition().x), static_cast<int>(poster[6]->getPosition().y));
	poster[7]->setTextConfiguration("ESCALERA", Color::Black, 20, static_cast<int>(poster[7]->getPosition().x), static_cast<int>(poster[7]->getPosition().y));
	poster[8]->setTextConfiguration("FULL", Color::Black, 20, static_cast<int>(poster[8]->getPosition().x), static_cast<int>(poster[8]->getPosition().y));
	poster[9]->setTextConfiguration("POKER", Color::Black, 20, static_cast<int>(poster[9]->getPosition().x), static_cast<int>(poster[9]->getPosition().y));
	poster[10]->setTextConfiguration("GENERALA", Color::Black, 20, static_cast<int>(poster[10]->getPosition().x), static_cast<int>(poster[10]->getPosition().y));
	poster[11]->setTextConfiguration("DOBLE GENERALA", Color::Black, 20, static_cast<int>(poster[11]->getPosition().x), static_cast<int>(poster[11]->getPosition().y));
	poster[12]->setTextConfiguration("PUNTAJE TOTAL", Color::Black, 20, static_cast<int>(poster[12]->getPosition().x), static_cast<int>(poster[12]->getPosition().y));

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

	for (int i = 0; i < posterSize; i++)
	{
		poster[i]->draw(window);
	}

	window->draw(line);
	window->draw(line2);

	for (int i = 0; i < 12; i++)
	{
		window->draw(points[i].text);
	}
}

void Annotations::updateScore(int ind)
{
	points[ind].str_points = std::to_string(points[ind].points);
	points[ind].text.setString(points[ind].str_points);
	points[ind].text.setPosition(points[ind].position.x, points[ind].position.y);

	for (int i = 0; i < 11; i++)
	{
		points[11].points += points[i].points;
	}
	points[11].str_points = std::to_string(points[11].points);
	points[11].text.setString(points[11].str_points);
	points[11].text.setPosition(points[11].position.x, points[11].position.y);
}

bool Annotations::isInside(int x, int y)
{
	return true;
}
Poster* Annotations::getPoster(int ind)
{
	return poster[ind];
}
int Annotations::getPoints(CATEGORY category, Dice* dice[])
{
	int dices[5] = {};
	int n = 0;
	int counter = 0;
	int repeatedNum = 0;
	bool two = false;
	bool three = false;
	bool poker = false;

	for (int i = 0; i < 5; i++)
	{
		dices[i] = dice[i]->getNumber();
	}


	switch (category)
	{
	case CATEGORY::ONE:
		for (int i = 0; i < 5; i++)
		{
			if (dices[i] == 1)
			{
				n++;
			}
		}
		break;

	case CATEGORY::TWO:
		for (int i = 0; i < 5; i++)
		{
			if (dices[i] == 2)
			{
				n += 2;
			}
		}
		break;

	case CATEGORY::THREE:
		for (int i = 0; i < 5; i++)
		{
			if (dices[i] == 3)
			{
				n += 3;
			}
		}
		break;

	case CATEGORY::FOUR:
		for (int i = 0; i < 5; i++)
		{
			if (dices[i] == 4)
			{
				n += 4;
			}
		}
		break;

	case CATEGORY::FIVE:
		for (int i = 0; i < 5; i++)
		{
			if (dices[i] == 5)
			{
				n += 5;
			}
		}
		break;

	case CATEGORY::SIX:
		for (int i = 0; i < 5; i++)
		{
			if (dices[i] == 6)
			{
				n += 6;
			}
		}
		break;

	case CATEGORY::STAIRS:
		for (int i = 0; i < 5; i++)
		{
			for (int j = i + 1; j < 5; j++)
			{
				if (dices[j] < dices[i])
				{
					int aux = dices[j];
					dices[j] = dices[i];
					dices[i] = aux;
				}
			}
		}

		if ((dices[0] == 1 && dices[1] == 2 && dices[2] == 3 && dices[3] == 4 && dices[4] == 5) ||
			(dices[0] == 2 && dices[1] == 3 && dices[2] == 4 && dices[3] == 5 && dices[4] == 6))
		{
			n = 20;
		}
		break;

	case CATEGORY::FULL:

		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (dices[j] == i + 1)
				{
					counter++;
					if (counter == 3)
					{
						repeatedNum = i + 1;
						three = true;
					}
				}
			}

			counter = 0;
		}

		if (three)
		{
			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (dices[j] == i + 1 && dices[j] != repeatedNum)
					{
						counter++;
						if (counter == 2)
						{
							two = true;
						}
					}
				}

				counter = 0;
			}
		}

		if (two && three)
		{
			n = 30;
		}
		break;

	case CATEGORY::POKER:

		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (dices[j] == i + 1)
				{
					counter++;

					if (counter == 4)
					{
						poker = true;
					}
				}
			}

			counter = 0;
		}

		if (poker)
		{
			n = 40;
		}
		break;

	case CATEGORY::GENERALA:
	case CATEGORY::DOUBLE_GENERALA:
		bool generala = false;

		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (dices[j] == i + 1)
				{
					counter++;

					if (counter == 5)
					{
						generala = true;
					}
				}
			}

			counter = 0;
		}

		if (generala && !points[9].annotated)
		{
			n = 60;
		}
		else if (generala && points[9].annotated && points[9].points == 60 && !points[10].annotated)
		{
			n = 60;
		}
		break;
	}


	return n;
}

int Annotations::getPosterArraySize()
{
	return posterSize;
}

string Annotations::convertToString(int num)
{
	return std::to_string(num);
}
