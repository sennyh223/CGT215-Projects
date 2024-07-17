#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;
using namespace std;

#define MENU_ITEMS 2

class Menu
{
public:
	Menu(float width, float height);
	~Menu();

	void draw(RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }

private:
	int selectedItemIndex;
	Font font;
	Text menu[MENU_ITEMS];

};

