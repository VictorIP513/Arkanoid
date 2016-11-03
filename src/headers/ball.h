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
	bool active;
	Vector2f speed;

public:
	Ball(RenderWindow & window);
	Ball(RenderWindow & window, Color color);
	void draw();
};