#include "brick.h"

Brick::Brick(RenderWindow &window) :
				window(&window),
				hit(0),
				draw_status(false)
{}

Vector2f Brick::get_size()
{
	return size;
}

Vector2f Brick::get_coord()
{
	return coord;
}

int Brick::get_hit()
{
	return hit;
}

bool Brick::get_draw_status()
{
	return draw_status;
}

void Brick::set_size(Vector2f size)
{
	this->size = size;
}

void Brick::set_coord(Vector2f coord)
{
	this->coord = coord;
}

void Brick::set_hit(int hit)
{
	this->hit += hit;
}

void Brick::set_draw_status(bool draw_status)
{
	this->draw_status = draw_status;
}

Color Brick::brick_draw_color()
{
	if (hit == 0)
		return Color::Black;
	if (hit == 1)
		return Color::Blue;
	if (hit == 2)
		return Color(255, 127, 39);
	if (hit == 3)
		return Color(64, 64, 128);
	if (hit == 4)
		return Color(128, 0, 0);
	if (hit == 5)
		return Color(192, 192, 192);
}

void Brick::draw()
{
	brick.setPosition(coord);
	brick.setSize(size);
	brick.setFillColor(brick_draw_color());
	window->draw(brick);
}