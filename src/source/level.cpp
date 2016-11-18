#include "level.h"

Level::Level(RenderWindow &window) :
				current_level(0),
				window(&window)
{
	set_level();
}

void Level::level_reserve_memory()
{
	brick_array = (Brick*) operator new(sizeof(Brick) * level_size);
	for (int i = 0; i < level_size; ++i)
		new(&brick_array[i]) Brick(*window);
}

void Level::level_delete_memory()
{
	for (int i = 0; i < level_size; ++i)
		brick_array[i].~Brick();
	operator delete(brick_array);
}

void Level::level1_constructor()
{
	level_size = 50;
	level_reserve_memory();
	for (int i = 0; i < level_size; ++i) {
		brick_coord.x = 14 * ((i % 10) + 1) + (float)Brick::brick_standart_x * (i % 10);
		brick_coord.y = window_y_min + 20 * ((i / 10) + 1) + (float)Brick::brick_standart_y * (i / 10);
		brick_size.x = Brick::brick_standart_x;
		brick_size.y = Brick::brick_standart_y;
		brick_array[i].set_hit(1);
		brick_array[i].set_draw_status(true);
		brick_array[i].set_size(brick_size);
		brick_array[i].set_coord(brick_coord);
	}
}

void Level::set_level()
{
	if (current_level == 0) {
		++current_level;
		level1_constructor();
		return;
	}
	if (current_level == 1) {
		level_delete_memory();
		++current_level;
		//level2_constructor();
	}
}

int Level::get_level_size()
{
	return level_size;
}

Brick* Level::get_brick_array()
{
	return brick_array;
}

void Level::draw()
{
	for (int i = 0; i < level_size; ++i)
			brick_array[i].draw();
}