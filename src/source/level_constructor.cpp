#include "level.h"

void Level::level1_constructor()
{
	for (int i = 0; i < level_size; ++i) {
		brick_coord.x = 14 * ((i % 10) + 1) + (float)Brick::brick_standart_x * (i % 10);
		brick_coord.y = window_y_min + 20 * ((i / 10) + 1) + (float)Brick::brick_standart_y * (i / 10);
		//if (i < 50) {
		//	if (i / 10 == 1 || i / 10 == 5 || i % 10 == 0 || i & 10 == 9)
		//		brick_array[i].set_hit(2);
		//	else
		//		brick_array[i].set_hit(1);
		//}
		//else
			brick_array[i].set_hit(1);
		brick_array[i].set_draw_status(true);
		brick_array[i].set_size(brick_size);
		brick_array[i].set_coord(brick_coord);
	}
}

void Level::level2_constructor()
{
	for (int i = 0; i < level_size; ++i) {
		if (i % 3 == 1)
			i += 3;
		brick_coord.x = 14 * ((i % 10) + 1) + (float)Brick::brick_standart_x * (i % 10);
		brick_coord.y = window_y_min + 20 * ((i / 10) + 1) + (float)Brick::brick_standart_y * (i / 10);
		brick_array[i].set_hit(1);
		brick_array[i].set_draw_status(true);
		brick_array[i].set_size(brick_size);
		brick_array[i].set_coord(brick_coord);
	}
}

void Level::level3_constructor()
{
	for (int i = 0, z = 1; i < level_size; ++i) {
		if (i % 10 == z) {
			i = z * 10;
			++z;
		}
		brick_coord.x = 14 * ((i % 10) + 1) + (float)Brick::brick_standart_x * (i % 10);
		brick_coord.y = window_y_min + 20 * ((i / 10) + 1) + (float)Brick::brick_standart_y * (i / 10);
		if (i >= 90)
			brick_array[i].set_hit(3);
		else
			brick_array[i].set_hit(1);
		brick_array[i].set_draw_status(true);
		brick_array[i].set_size(brick_size);
		brick_array[i].set_coord(brick_coord);
	}
}

void Level::level4_constructor()
{
	for (int i = 0; i < level_size; ++i) {
		brick_coord.x = 14 * ((i % 10) + 1) + (float)Brick::brick_standart_x * (i % 10);
		brick_coord.y = window_y_min + 20 * ((i / 10) + 1) + (float)Brick::brick_standart_y * (i / 10);
		brick_array[i].set_hit(i % 5 + 1);
		brick_array[i].set_draw_status(true);
		brick_array[i].set_size(brick_size);
		brick_array[i].set_coord(brick_coord);
	}
}
