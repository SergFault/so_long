/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergey <sergey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:24:31 by sergey            #+#    #+#             */
/*   Updated: 2021/09/29 17:24:31 by sergey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

static void	set_img_null(t_img *img)
{
	img->img = NULL;
	img->address = NULL;
	img->bpp = 0;
	img->line_length = 0;
	img->endian = 0;
	img->width = 0;
	img->height = 0;
}

static void	img_init(t_dataset *set)
{
	set_img_null(&set->rend->main_img);
	set_img_null(&set->rend->floor);
	set_img_null(&set->rend->floor);
	set_img_null(&set->rend->collectible);
	set_img_null(&set->rend->exit);
	set_img_null(&set->rend->hero0);
	set_img_null(&set->rend->hero1);
	set_img_null(&set->rend->hero2);
	set_img_null(&set->rend->hero3);
	set_img_null(&set->rend->hero4);
	set_img_null(&set->rend->hero5);
	set_img_null(&set->rend->enemy0);
	set_img_null(&set->rend->enemy1);
	set_img_null(&set->rend->enemy2);
	set_img_null(&set->rend->enemy3);
	set_img_null(&set->rend->enemy4);
	set_img_null(&set->rend->enemy5);
}

void	init_data(t_dataset *set)
{
	set->rend->mlx = NULL;
	set->rend->win = NULL;
	set->game->enemies = NULL;
	img_init(set);
	set->game->hero_pos.x = 0;
	set->game->hero_pos.y = 0;
	set->game->map_width = 0;
	set->game->map_height = 0;
	set->game->map = NULL;
	set->game->exits = NULL;
	set->game->collectibles = NULL;
}

void	game_init(t_game *game)
{
	t_coordinates	pos;

	game->time = 0;
	pos = get_pos(HERO_CH, game);
	game->movements = 0;
	game->win = 0;
	game->collectibles = scan_objects(game, COLL_CH);
	game->exits = scan_objects(game, EXIT_CH);
	game->hero_pos.x = pos.x;
	game->hero_pos.y = pos.y;
	game->map[pos.y][pos.x] = FLOOR_CH;
}
