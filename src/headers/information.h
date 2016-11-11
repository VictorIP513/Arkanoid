#ifndef INFORMATION_H
#define INFORMATION_H
#include "general.h"

class Information : public General
{
private:
	int score;
	int level;
	int lives;
	RenderWindow *window;
	RectangleShape line;
	Vector2f line_size;
	Vector2f line_coord;
	Color line_color;

public:
	Information(RenderWindow &window);
	Information(RenderWindow &window, int lives);
	static Color get_default_line_color();
	void line_draw();
	virtual void draw();
	static const int start_level = 1;
	static const int start_lives = 3;
	static const int line_standart_x =	gameWidth;
	static const int line_standart_y = 3;
	static const int line_position_y = window_y_min;
};

#endif INFORMATION_H