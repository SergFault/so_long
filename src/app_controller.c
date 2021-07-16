#include "../includes/so_long.h"

int leave_game(int keycode, t_game *vars)
{
	(void) keycode;
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}