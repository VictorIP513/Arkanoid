#include "level.h"

Level::Level(RenderWindow &window) :
				current_level(0),
				window(&window),
				level_size(100),
				brick_size((float)Brick::brick_standart_x, (float)Brick::brick_standart_y)
{
	set_level();
}

int Level::get_level_size()
{
	return level_size;
}

int Level::get_current_level()
{
	return current_level;
}

Brick* Level::get_brick_array()
{
	return brick_array;
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

void Level::next_level()
{
	if (current_level)
		level_delete_memory();
	++current_level;
	level_reserve_memory();
}

void Level::set_level()
{
	next_level();
	switch (current_level)
	{
	case 1: {
		level1_constructor();
		break;
	}
	case 2: {
		level2_constructor();
		break;
	}
	case 3: {
		level3_constructor();
		break;
	}
	case 4: {
		level4_constructor();
		break;
	}
	case 5: {
		level5_constructor();
		break;
	}
	case 6: {
		level6_constructor();
		break;
	}
	case 7: {
		level7_constructor();
		break;
	}
	case 8: {
		level8_constructor();
		break;
	}
	case 9: {
		level9_constructor();
		break;
	}
	case 10: {
		level10_constructor();
		break;
	}
	default:
		break;
	}
}

bool Level::level_is_void()
{
	for (int i = 0; i < level_size; ++i)
		if (brick_array[i].get_hit())
			return false;
	return true;
}

void Level::draw()
{
	for (int i = 0; i < level_size; ++i)
		brick_array[i].draw();
}