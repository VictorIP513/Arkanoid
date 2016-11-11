#ifndef BALL_H
#define BALL_H
#include "general.h"
#include "platform.h"

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
	Vector2f platform_coord;
	Vector2f platform_size;
	const int ball_change_speed = 50000;

public:
	Ball(RenderWindow &window, Platform &platform);
	Ball(RenderWindow &window, Platform &platform, Color color);
	static Color get_default_color();
	virtual void draw();
	void ball_active();
	void ball_noActive();
	void ball_speed();
	void ball_boundPlatform();
	void ball_boundWall();
	void ball_active_move();
	void ball_noActive_move();
	static const int ball_standart_radius = 8;
	static const int max_ball_speed = 1;
};
#endif BALL_H