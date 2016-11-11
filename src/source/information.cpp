#include "information.h"

Information::Information(RenderWindow &window) :
				window(&window),
				level(start_level),
				score(0),
				lives(start_lives),
				line_size((float)line_standart_x, (float)line_standart_y),
				line_coord(0, (float)line_position_y),
				line_color(get_default_line_color())
{}

Information::Information(RenderWindow &window, int lives) :
				window(&window),
				level(start_level),
				score(0),
				lives(lives),
				line_size((float)line_standart_x, (float)line_standart_y),
				line_coord(0, (float)line_position_y),
				line_color(get_default_line_color())
{}

Color Information::get_default_line_color()
{
	return Color::Yellow;
}

void Information::line_draw()
{
	line.setPosition(line_coord);
	line.setSize(line_size);
	line.setFillColor(line_color);
	window->draw(line);
}

void Information::draw()
{
	line_draw();
}
