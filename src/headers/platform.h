#ifndef PLATFORM_H
#define PLATFORM_H
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
	Color get_default_color();
	void platform_move();
	void draw();
	static const int platform_standart_x = 200;
	static const int platform_standart_y = 20;
};
#endif