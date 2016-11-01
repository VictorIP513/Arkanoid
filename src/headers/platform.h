#pragma once
#include <iostream>
#include <iterator>
#include <SFML/Graphics.hpp>
#include "general.h"


using namespace sf;

class Platform: public General
{
private:
	Vector2f coord;
	Vector2f size;
	Color color;
	RectangleShape platform;
	RenderWindow *window;
	
public:
	Platform(RenderWindow &window);
	Platform(RenderWindow & window, Color color);
	Platform(RenderWindow & window, Color color, Vector2f size);
	void draw_platform();
};