#include "..\headers\platform.h"
#include "..\headers\ball.h"

Ball::Ball(RenderWindow &window) :
	window(&window),
	coord(500, 500),
	radius(20),
	color(Color::Yellow)
{}

Ball::Ball(RenderWindow &window, Color color) :
	window(&window),
	color(color),
	coord(500, 500),
	radius(20)
{}

Ball::Ball(RenderWindow &window, Color color, int radius) :
	window(&window),
	color(color),
	radius(20),
	coord(500, 500)
{}

void Ball::draw_ball()
{
	ball.setPosition(coord);
	ball.setRadius(radius);
	ball.setFillColor(color);
	window->draw(ball);
}