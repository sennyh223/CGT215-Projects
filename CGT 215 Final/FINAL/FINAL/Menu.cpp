#include "Menu.h"

using namespace sf;

Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("cocogoose.otf"))
	{
		// error loading font
	
	}

	menu[0].setFont(font);
	menu[0].setFillColor(Color::Blue);
	menu[0].setString("Play");
	menu[0].setPosition(Vector2f(width / 2, height / (MENU_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(Color::White);
	menu[1].setString("Exit");
	menu[1].setPosition(Vector2f(width / 2, height / (MENU_ITEMS + 1) * 2));

	selectedItemIndex = 0;
}

Menu::~Menu()
{

}

void Menu::draw(RenderWindow& window) {
	for (int i = 0; i < MENU_ITEMS; i++) {
		window.draw(menu[i]);
	}		
}

void Menu::MoveUp() 
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Blue);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MENU_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Blue);
	}
}