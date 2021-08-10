#include "../includes/so_long.h"

int leave_game(t_dataset *set)
{
	mlx_destroy_image(set->rend->mlx, set->rend->main_img.img);
	mlx_destroy_image(set->rend->mlx, set->rend->floor.img);
	mlx_destroy_image(set->rend->mlx, set->rend->wall.img);
	mlx_destroy_window(set->rend->mlx, set->rend->win);
	mlx_destroy_display(set->rend->mlx);
	mlx_loop_end(set->rend->mlx);
	free(set->rend->mlx);
	free_data(set);
	exit(0);
}