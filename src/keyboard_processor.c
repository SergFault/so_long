#include "../includes/so_long.h"


//static void move_up(t_game *game, char object)
//{
//
//}

int process_key(int key, t_dataset *set)
{
	(void) set;
	if (key == ESC)
		leave_game(set);
	if (key == UP)
		move(UP, &set->game->hero_pos, set->game->map);
	if (key == DOWN)
		move(DOWN, &set->game->hero_pos, set->game->map);
	if (key == LEFT)
		move(LEFT, &set->game->hero_pos, set->game->map);
	if (key == RIGHT)
		move(RIGHT, &set->game->hero_pos, set->game->map);
	return (0);
}