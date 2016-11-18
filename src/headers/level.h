#ifndef LEVEL_H
#define LEVEL_H
#include "general.h"
#include "brick.h"

class Level : public General
{
private:
	int current_level;
	int level_size;
	Brick *brick_array;
	RenderWindow *window;
	Vector2f brick_coord;
	Vector2f brick_size;

public:
	Level(RenderWindow &window);
	void level_reserve_memory();
	void level_delete_memory();
	void level1_constructor();
	void set_level();
	int get_level_size();
	Brick* get_brick_array();
	virtual void draw();
	const int level_max_bricks = 50;
};
#endif LEVEL_H