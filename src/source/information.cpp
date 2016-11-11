#include "information.h"

Information::Information(RenderWindow &window) :
				window(&window),
				level(start_level),
				score(0),
				lives(start_lives),
				line_size((float)line_standart_x, (float)line_standart_y),
				line_coord(0, (float)line_position_y),
				line_color(get_default_line_color())	
{
	load_fonts();
}

Information::Information(RenderWindow &window, int lives) :
				window(&window),
				level(start_level),
				score(0),
				lives(lives),
				line_size((float)line_standart_x, (float)line_standart_y),
				line_coord(0, (float)line_position_y),
				line_color(get_default_line_color())
{
	load_fonts();
}

void Information::load_fonts()
{
	if (!font.loadFromFile("fonts/painter.ttf"))
		cout << "[ERROR] fonts/painter.ttf is not load" << endl;
}

Color Information::get_default_line_color()
{
	return Color::Yellow;
}

Color Information::get_default_font_color()
{
	return Color::Green;
}

void Information::add_lives(int lives)
{
	this->lives += lives;
}

void Information::add_score(int score)
{
	this->score += score;
}

void Information::change_level_text()
{
	level++;
}

void Information::line_draw()
{
	line.setPosition(line_coord);
	line.setSize(line_size);
	line.setFillColor(line_color);
	window->draw(line);
}

void Information::draw_text_level()
{
	text_level.setFont(font);
	text_level.setString("LEVEL: " + to_string(level));
	text_level.setCharacterSize(font_size);
	text_level.setColor(get_default_font_color());
	window->draw(text_level);
}

void Information::draw_text_lives()
{
	text_lives.setFont(font);
	text_lives.setPosition(200, 0);
	text_lives.setString("BALLS: " + to_string(lives));
	text_lives.setCharacterSize(font_size);
	text_lives.setColor(get_default_font_color());
	window->draw(text_lives);
}

void Information::draw_text_score()
{
	text_score.setFont(font);
	text_score.setPosition(400, 0);
	text_score.setString("SCORE: " + to_string(score));
	text_score.setCharacterSize(font_size);
	text_score.setColor(get_default_font_color());
	window->draw(text_score);
}

void Information::information_draw()
{
	draw_text_level();
	draw_text_lives();
	draw_text_score();
}

void Information::draw()
{
	line_draw();
	information_draw();
}