/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergey <sergey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:24:42 by sergey            #+#    #+#             */
/*   Updated: 2021/09/29 17:24:42 by sergey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	rend_init_models(t_rend *rend)
{
	init_model(rend->mlx, &rend->exit, EXIT_PATH);
	init_model(rend->mlx, &rend->collectible, COLL_PATH);
	init_model(rend->mlx, &rend->floor, GRASS_PATH);
	init_model(rend->mlx, &rend->wall, WALL_PATH);
	init_model(rend->mlx, &rend->hero0, HERO0);
	init_model(rend->mlx, &rend->hero1, HERO1);
	init_model(rend->mlx, &rend->hero2, HERO2);
	init_model(rend->mlx, &rend->hero3, HERO3);
	init_model(rend->mlx, &rend->hero4, HERO4);
	init_model(rend->mlx, &rend->hero5, HERO5);
	init_model(rend->mlx, &rend->enemy0, ENEMY0);
	init_model(rend->mlx, &rend->enemy1, ENEMY1);
	init_model(rend->mlx, &rend->enemy2, ENEMY2);
	init_model(rend->mlx, &rend->enemy3, ENEMY3);
	init_model(rend->mlx, &rend->enemy4, ENEMY4);
	init_model(rend->mlx, &rend->enemy5, ENEMY5);
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
	rend_init_models(rend);
	return (1);
}

static int	init(t_dataset *set, char **argv)
{
	set->game->seed_g = 300;
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
