#ifndef PLATFORM_H
#define PLATFORM_H
#include "general.h"

class Platform : public General
{
private:
	Color color;
	RectangleShape platform;
	RenderWindow *window;
	Vector2f coord;
	Vector2f size;

public:
	Platform(RenderWindow &window);
	Platform(RenderWindow & window, Color color);
	Vector2f get_coord();
	Vector2f get_size();
	static Color get_default_color();
	virtual void draw();
	void platform_move();
	static const int platform_standart_x = 200;
	static const int platform_standart_y = 20;
};
#endif PLATFORM_H