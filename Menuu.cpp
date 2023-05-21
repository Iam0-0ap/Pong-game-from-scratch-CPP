#include "Menuu.h"


Menuu::Menuu(float width, float height)
{
	if (!font.loadFromFile("Data/ariel.ttf")){}

	//play
	mainMenu[0].setFont(font);
	mainMenu[0].setColor(sf::Color::Blue);
	mainMenu[0].setString("PLAY");
	mainMenu[0].setCharacterSize(50);
	mainMenu[0].setPosition(sf::Vector2f(340,200));

	//exit
	mainMenu[1].setFont(font);
	mainMenu[1].setColor(sf::Color::Red);
	mainMenu[1].setString("EXIT");
	mainMenu[1].setCharacterSize(50);
	mainMenu[1].setPosition(sf::Vector2f(348,300));
	mainMenuSelected=0;
}


Menuu::~Menuu(void)
{
}


//function for drawing main menu
void Menuu::draw(sf::RenderWindow &window)
{
for (int i=0; i<3; i++)
{
	window.draw(mainMenu[i]);
}
}

//move down
void Menuu::moveDown()
{
	if (mainMenuSelected +1 <= Max_main_menu)
	{
		mainMenu[mainMenuSelected].setColor(sf::Color::White);

		mainMenuSelected++;
		if (mainMenuSelected ==3)
		{
			mainMenuSelected=0;
		}
		mainMenu[mainMenuSelected].setColor(sf::Color::Blue);

	}
}

//move up
void Menuu::moveUp()
{
	if (mainMenuSelected - 1 >= -1)
	{
		mainMenu[mainMenuSelected].setColor(sf::Color::White);

		mainMenuSelected--;
		if (mainMenuSelected == -1)
		{
			mainMenuSelected=2;
		}
		mainMenu[mainMenuSelected].setColor(sf::Color::Blue);

	}
}