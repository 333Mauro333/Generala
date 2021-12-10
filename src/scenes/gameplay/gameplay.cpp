#include "gameplay.h"

#include <iostream>

using std::cout;


Gameplay::Gameplay(RenderWindow* window) : Scene()
{
	this->window = window;
	back.setFillColor(Color(256, 128, 100));
	back.setSize({ static_cast<float>(window->getSize().x), static_cast<float>(window->getSize().y) });

	buttonThrow = new Button(window->getSize().x / 2.0f, window->getSize().y / 1.1f, window->getSize().x / 3.0f, window->getSize().y / 10.0f, Color::Blue, "Tirar");

	dices[0] = new Dice({ window->getSize().x / 6.0f * 1.0f, window->getSize().y / 1.25f });
	dices[1] = new Dice({ window->getSize().x / 6.0f * 2.0f, window->getSize().y / 1.25f });
	dices[2] = new Dice({ window->getSize().x / 6.0f * 3.0f, window->getSize().y / 1.25f });
	dices[3] = new Dice({ window->getSize().x / 6.0f * 4.0f, window->getSize().y / 1.25f });
	dices[4] = new Dice({ window->getSize().x / 6.0f * 5.0f, window->getSize().y / 1.25f });

	for (int i = 0; i < 5; i++)
	{
		dices[i]->setActive(false);
	}

	float annotationsW = window->getSize().x / 1.1f;
	float annotationsH = window->getSize().y / 1.5f;
	annotations = new Annotations(window->getSize().x / 2.0f - annotationsW / 2.0f, window->getSize().y / 100.0f, annotationsW, annotationsH);

	if (!font.loadFromFile("res/fonts/segoepr.ttf"))
	{
		cout << "ERROR";
	}
	else
	{
		cout << "La fuente ha sido cargada exitosamente.\n";
	}

	textMessage.setFont(font);
	textMessage.setFillColor(Color::Black);
	textMessage.setCharacterSize(30);
	textMessage.setPosition(window->getSize().x / 2.0f, window->getSize().y / 1.425f);

	cout << "Se ha creado una pantalla de gameplay.\n";
}
Gameplay::~Gameplay()
{
	cout << "La pantalla de gameplay ha sido eliminada de la memoria.\n";
}

void Gameplay::init()
{

}
void Gameplay::update(float deltaTime)
{
	for (int i = 0; i < 5; i++)
	{
		dices[i]->update(deltaTime);
	}

	annotations->update(deltaTime);
}
void Gameplay::draw()
{
	window->draw(back);
	for (int i = 0; i < 5; i++)
	{
		dices[i]->draw(window);
	}

	buttonThrow->draw(window);
	annotations->draw(window);

	for (int i = 0; i < Annotations::getPosterArraySize(); i++)
	{
		if (annotations->getPoster(i)->isShining())
		{
			showMessagePoints(static_cast<CATEGORY>(i));
		}
	}
}
void Gameplay::destroy()
{
	for (int i = 0; i < 5; i++)
	{
		delete dices[i];
	}
}

void Gameplay::checkClicks(int x, int y)
{
	for (int i = 0; i < 5; i++)
	{
		if (dices[i]->isInside(x, y))
		{
			cout << "Clicked " << i + 1 << "!\n";
			dices[i]->select();
		}
	}

	if (buttonThrow->isInside(x, y))
	{
		for (int i = 0; i < 5; i++)
		{
			dices[i]->launch();
		}
	}
}

void Gameplay::checkMouseCollision(int x, int y)
{
	for (int i = 0; i < Annotations::getPosterArraySize(); i++)
	{
		if (annotations->getPoster(i)->isInside(x, y))
		{
			annotations->getPoster(i)->shine();
			
			switch (i)
			{
			case 0:
				showMessagePoints(CATEGORY::ONE);
				break;

			case 1:
				showMessagePoints(CATEGORY::TWO);
				break;

			case 2:
				showMessagePoints(CATEGORY::THREE);
				break;

			case 3:
				showMessagePoints(CATEGORY::FOUR);
				break;

			case 4:
				showMessagePoints(CATEGORY::FIVE);
				break;

			case 5:
				showMessagePoints(CATEGORY::SIX);
				break;

			case 6:
				showMessagePoints(CATEGORY::STAIRS);
				break;

			case 7:
				showMessagePoints(CATEGORY::FULL);
				break;

			case 8:
				showMessagePoints(CATEGORY::POKER);
				break;

			case 9:
				showMessagePoints(CATEGORY::GENERALA);
				break;

			case 10:
				showMessagePoints(CATEGORY::DOUBLE_GENERALA);
				break;
			}
		}
		else
		{
			annotations->getPoster(i)->opaque();
		}
	}
}

void Gameplay::showMessagePoints(CATEGORY category)
{
	string str_category = "";
	int points = annotations->getPoints(category, dices);

	switch (category)
	{
	case CATEGORY::ONE:
		str_category = "l uno";
		break;
	case CATEGORY::TWO:
		str_category = "l dos";
		break;
	case CATEGORY::THREE:
		str_category = "l tres";
		break;
	case CATEGORY::FOUR:
		str_category = "l cuatro";
		break;
	case CATEGORY::FIVE:
		str_category = "l cinco";
		break;
	case CATEGORY::SIX:
		str_category = "l seis";
		break;
	case CATEGORY::STAIRS:
		str_category = " la escalera";
		break;
	case CATEGORY::FULL:
		str_category = "l full";
		break;
	case CATEGORY::POKER:
		str_category = "l poker";
		break;
	case CATEGORY::GENERALA:
		str_category = " la generala";
		break;
	case CATEGORY::DOUBLE_GENERALA:
		str_category = " la generala doble";
		break;
	default:
		return;
	}

	string message = "Serian " + std::to_string(points);
	message += " a" + str_category + ".";
	textMessage.setString(message);
	textMessage.setOrigin(textMessage.getGlobalBounds().width / 2.0f, textMessage.getOrigin().y);
	window->draw(textMessage);
}
