#include "../includes/so_long.h"

int leave_game(t_game *vars)
{

	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int resize_attempt(int keycode, t_game *vars)
{
	(void) keycode;
	(void) vars;
	printf("Resize attempt");
	return (0);
}

int move(int keycode, t_dataset *data)
{
	if (keycode == 65307)
		leave_game(data->game);
	if (keycode == 65361)
		data->game->x -= 10;
	if (keycode == 65362)
		data->game->y -= 10;
	if (keycode == 65363)
		data->game->x += 10;
	if (keycode == 65364)
		data->game->y += 10;
	return (0);
}