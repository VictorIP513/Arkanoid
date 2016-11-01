#pragma once
#include <iostream>
#include <iterator>
#include <SFML/Graphics.hpp>
#include "general.h"


using namespace sf;

class Ball : public General
{
private:
	Vector2f coord;
	int radius;
	Color color;
	CircleShape ball;
	RenderWindow *window;

public:
	Ball(RenderWindow & window);
	Ball(RenderWindow & window, Color color);
	Ball(RenderWindow & window, Color color, int radius);
	void draw_ball();
};