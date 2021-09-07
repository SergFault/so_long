#include "../../includes/so_long_bonus.h"

int	process_key(int key, t_dataset *set)
{
	(void) set;
	if (key == ESC)
		leave_game(set);
	if (key == UP)
		move(UP, &set->game->hero_pos, set->game);
	if (key == DOWN)
		move(DOWN, &set->game->hero_pos, set->game);
	if (key == LEFT)
		move(LEFT, &set->game->hero_pos, set->game);
	if (key == RIGHT)
		move(RIGHT, &set->game->hero_pos, set->game);
	return (0);
}
