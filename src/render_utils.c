/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergey <sergey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:27:51 by sergey            #+#    #+#             */
/*   Updated: 2021/09/29 17:27:51 by sergey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_img	*get_img(t_rend *rend, char ch)
{
	if (ch == WALL_CH)
		return (&rend->wall);
	if (ch == FLOOR_CH)
		return (&rend->floor);
	if (ch == HERO_CH)
		return (&rend->hero);
	if (ch == COLL_CH)
		return (&rend->collectible);
	if (ch == EXIT_CH)
		return (&rend->exit);
	return (&rend->floor);
}

static int	map_on_img(t_dataset *set)
{
	int		i;
	int		j;
	t_rend	*rend;

	rend = set->rend;
	i = 0;
	while (i < set->game->map_width)
	{
		j = 0;
		while (j < set->game->map_height)
		{
			img_on_img(&set->rend->main_img,
				get_img(rend, set->game->map[j][i]),
				i * MODEL_SIZE,
				j * MODEL_SIZE);
			j++;
		}
		i++;
	}
	return (1);
}

static void	obj_on_img(t_dataset *set, char obj)
{
	t_coordinates	pos;

	if (obj == HERO_CH)
		pos = set->game->hero_pos;
	img_on_img(&set->rend->main_img, get_img(set->rend, obj),
		pos.x * MODEL_SIZE,
		pos.y * MODEL_SIZE);
}

static void	objs_on_img(t_dataset *set, t_list *objs, char type)
{
	t_env	*env;

	while (objs)
	{
		env = (t_env *)objs->content;
		img_on_img(&set->rend->main_img, get_img(set->rend, type),
			env->pos.x * MODEL_SIZE,
			env->pos.y * MODEL_SIZE);
		objs = objs->next;
	}
}

int	game_loop(t_dataset *set)
{
	t_rend	*r;

	(void) set;
	r = set->rend;
	check_collisions(set);
	map_on_img(set);
	objs_on_img(set, set->game->collectibles, COLL_CH);
	objs_on_img(set, set->game->exits, EXIT_CH);
	obj_on_img(set, HERO_CH);
	mlx_put_image_to_window(r->mlx, r->win, (r->main_img.img), 0, 0);
	if (set->game->win)
		leave_game(set);
	return (1);
}
