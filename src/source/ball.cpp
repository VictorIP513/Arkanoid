#include "ball.h"
#include <iostream>

Ball::Ball(RenderWindow &window, Platform &platform) :
				window(&window),
				radius(ball_standart_radius),
				coord((gameWidth - ball_standart_radius) / 2, 500),
				color(get_default_color()),
				active(false),
				speed(0, 0),
				platform(&platform)
{}

Ball::Ball(RenderWindow &window, Platform &platform, Color color) :
				window(&window),
				color(color),
				radius(ball_standart_radius),
				coord((gameWidth - ball_standart_radius) / 2, 500),
				active(false),
				speed(0, 0),
				platform(&platform)
{}

Color Ball::get_default_color()
{
	return Color::Cyan;
}

void Ball::ball_active()
{
	if ((active == false) && Keyboard::isKeyPressed(Keyboard::Space) || Mouse::isButtonPressed(Mouse::Button::Left))
		active = true;
}

void Ball::ball_noActive()
{
	if (coord.y + radius * 2 > platform_coord.y)
		if ((coord.x < platform_coord.x) || (coord.x > platform_coord.x + platform_size.x)) {
			active = false;
			speed_counter_reload = true;
		}
}

void Ball::ball_speed()
{
	static int counter = 0;
	if (speed_counter_reload == true) {
		speed_counter_reload = false;
		counter = 0;
	}
	++counter;
	if ((abs(speed.y) < max_ball_speed) && (abs(speed.x) < max_ball_speed))
		if (counter > ball_change_speed) {
			if (speed.x > 0)
				speed.x += 1 * get_gamespeed();
			else
				speed.x -= 1 * get_gamespeed();
			if (speed.y > 0)
				speed.y += 1 * get_gamespeed();
			else
				speed.y -= 1 * get_gamespeed();
			counter = 0;
		}
	//std::cout << "SPEED: " << abs(speed.y) << "  |  " << counter << std::endl;
}

void Ball::ball_boundPlatform()
{
	if (coord.y + radius * 2 > platform_coord.y)
		if (coord.x > platform_coord.x && coord.x < platform_coord.x + platform_size.x)
			speed.y *= -1;
}

void Ball::ball_boundWall()
{
	if (coord.y <= window_y_min)
		speed.y *= -1;
	if (coord.x < 0 || coord.x + radius * 2 > gameWidth)
		speed.x *= -1;
}

void Ball::ball_active_move()
{
	if (speed.x == 0 && speed.y == 0) {
		speed.x = get_gamespeed();
		speed.y = get_gamespeed();
	}
	coord.x += speed.x;
	coord.y -= speed.y;
}

void Ball::ball_noActive_move()
{
	speed.x = 0;
	speed.y = 0;
	coord.x = platform_coord.x + platform_size.x / 2;
	coord.y = platform_coord.y - radius * 2;
}

void Ball::draw()
{
	ball.setPosition(coord);
	ball.setRadius((float)radius);
	ball.setFillColor(color);
	platform_coord = platform->get_coord();
	platform_size = platform->get_size();
	ball_active();
	ball_noActive();
	if (active) {
		ball_active_move();
		ball_speed();
		ball_boundPlatform();
		ball_boundWall();
	}
	else
		ball_noActive_move();
	window->draw(ball);
}