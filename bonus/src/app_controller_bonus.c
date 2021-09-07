#include "../../includes/so_long_bonus.h"

int	leave_game(t_dataset *set)
{
	mlx_destroy_image(set->rend->mlx, set->rend->main_img.img);
	mlx_destroy_image(set->rend->mlx, set->rend->floor.img);
	mlx_destroy_image(set->rend->mlx, set->rend->wall.img);
	mlx_destroy_image(set->rend->mlx, set->rend->collectible.img);
	mlx_destroy_image(set->rend->mlx, set->rend->exit.img);
	mlx_destroy_image(set->rend->mlx, set->rend->hero.img);
	mlx_destroy_window(set->rend->mlx, set->rend->win);
	mlx_destroy_display(set->rend->mlx);
	mlx_loop_end(set->rend->mlx);
	free(set->rend->mlx);
	ft_lstclear(&(set->game->collectibles), free_env_obj);
	ft_lstclear(&(set->game->exits), free_env_obj);
	free_data(set);
	free_map(set->game->map, set->game->map_height);
	exit(0);
}
