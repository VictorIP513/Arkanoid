#ifndef BALL_H
#define BALL_H
#include "general.h"
#include "platform.h"
#include "information.h"
#include "level.h"
#include <cmath>

class Ball : public General
{
private:
	Vector2f coord;
	int radius;
	Color color;
	CircleShape ball;
	RenderWindow *window;
	bool active;
	bool speed_counter_reload;
	Vector2f speed;
	Platform *platform;
	Information *information;
	Level *level;
	Vector2f platform_coord;
	Vector2f platform_size;
	Brick *brick_array;
	const int ball_change_speed = 3000;

public:
	Ball(RenderWindow &window, Platform &platform, Information &information, Level &level);
	Ball(RenderWindow &window, Platform &platform, Information &information, Level &level, Color color);
	static Color get_default_color();
	virtual void draw();
	void ball_active();
	void ball_noActive();
	void ball_speed();
	void ball_boundPlatform();
	void ball_boundWall();
	void ball_boundBrick();
	void ball_active_move();
	void ball_noActive_move();
	static const int ball_standart_radius = 8;
	static const int max_ball_speed = 1;
};
#endif BALL_H