#include "../../includes/so_long_bonus.h"

#include <mlx.h>

static int	init_model(void *mlx, t_img *img, char *path)
{
	img->img = mlx_xpm_file_to_image(mlx, path, &(img->width),
			& (img->height));
	img->address = mlx_get_data_addr(img->img, &img->bpp,
			& img->line_length, &img->endian);
	return (1);
}

static int	rend_init(t_rend *rend, t_game *game)
{
	rend->mlx = mlx_init();
	rend->win = mlx_new_window(rend->mlx, game->map_width * MODEL_SIZE,
			game->map_height * MODEL_SIZE, "SO_LONG");
	rend->main_img.img = mlx_new_image(rend->mlx, game->map_width * MODEL_SIZE,
			game->map_height * MODEL_SIZE);
	rend->main_img.address = mlx_get_data_addr(rend->main_img.img,
			&rend->main_img.bpp,
			&rend->main_img.line_length,
			&rend->main_img.endian);
	init_model(rend->mlx, &rend->exit, EXIT_PATH);
	init_model(rend->mlx, &rend->collectible, COLL_PATH);
	init_model(rend->mlx, &rend->floor, GRASS_PATH);
	init_model(rend->mlx, &rend->wall, WALL_PATH);
	init_model(rend->mlx, &rend->hero, HERO);
	return (1);
}

static int	init(t_dataset *set, char **argv)
{
	init_data(set);
	map_init(set->game, argv);
	enemy_init(set);
	rend_init(set->rend, set->game);
	game_init(set->game);
	return (1);
}

int	main(int argc, char **argv)
{
	t_rend		rend;
	t_game		game;
	t_dataset	set;

	(void) argv;
	if (argc == 2)
	{
		set.game = &game;
		set.rend = &rend;
		init(&set, argv);
		mlx_hook(rend.win, 33, 1L << 17, leave_game, &set);
		mlx_key_hook(rend.win, process_key, &set);
		mlx_loop_hook(rend.mlx, game_loop, &set);
		mlx_loop(rend.mlx);
	}
	else
		ft_putstr_fd(ARGS_ERROR, 2);
}
