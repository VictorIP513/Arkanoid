#include "..\headers\platform.h"
#include "..\headers\ball.h"

Ball::Ball(RenderWindow &window) :
	window(&window),
	coord(500, 500),
	radius(20),
	color(Color::Yellow),
	active(false),
	speed(0, 0)
{}

Ball::Ball(RenderWindow &window, Color color) :
	window(&window),
	color(color),
	coord(500, 500),
	radius(20),
	active(false),
	speed(0, 0)
{}

void Ball::draw()
{
	ball.setPosition(coord);
	ball.setRadius(radius);
	ball.setFillColor(color);
	window->draw(ball);
}