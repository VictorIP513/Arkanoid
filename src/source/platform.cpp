#include "platform.h"

Platform::Platform(RenderWindow &window) :
				window(&window),
				coord((gameWidth - platform_standart_x) / 2, gameHeight - platform_standart_y),
				size((float)platform_standart_x, (float)platform_standart_y),
				color(get_default_color())
{}

Platform::Platform(RenderWindow &window, Color color) :
				window(&window),
				color(color),
				coord((gameWidth - platform_standart_x) / 2, gameHeight - platform_standart_y),
				size((float)platform_standart_x, (float)platform_standart_y)
{}

Color Platform::get_default_color()
{
	return Color::Yellow;
}

void Platform::platform_move()
{
	Vector2i mouse_position = Mouse::getPosition(*window);
	if (mouse_position.x >= 0 && mouse_position.x <= gameWidth - size.x)
		coord.x = (float)mouse_position.x;
	else {
		if (mouse_position.x < 0)
			coord.x = 0;
		else
			coord.x = gameWidth - size.x;
	}
}

void Platform::draw()
{
	platform.setPosition(coord);
	platform.setSize(size);
	platform.setFillColor(color);
	platform_move();
	window->draw(platform);
}