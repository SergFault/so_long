/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergey <sergey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:23:56 by sergey            #+#    #+#             */
/*   Updated: 2021/09/29 17:23:56 by sergey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

static int	coordinates_intersect(t_coordinates a, t_coordinates b)
{
	if ((a.x == b.x) && (a.y == b.y))
		return (1);
	return (0);
}

static int	hero_cols(t_dataset *set)
{
	t_coordinates	her_pos;
	int				c;
	t_list			*iter;

	her_pos = set->game->hero_pos;
	iter = set->game->collectibles;
	c = 0;
	while (iter)
	{
		if (coordinates_intersect(((t_env *)(iter)->content)->pos, her_pos))
		{
			ft_lstdelone(&set->game->collectibles, c, free_env_obj);
			return (1);
		}
		else
			iter = (iter)->next;
		c++;
	}
	return (1);
}

static int	hero_exit(t_dataset *set)
{
	t_coordinates	her_pos;
	t_list			*exits;

	her_pos = set->game->hero_pos;
	exits = set->game->exits;
	while (exits)
	{
		if ((coordinates_intersect(((t_env *)(exits)->content)->pos,
				her_pos)) & (set->game->collectibles == 0))
			leave_game(set, WIN);
		exits = exits->next;
	}
	return (1);
}

static int	hero_enemies(t_dataset *set)
{
	t_coordinates	her_pos;
	int				c;
	t_list			*iter;

	her_pos = set->game->hero_pos;
	iter = set->game->enemies;
	c = 0;
	while (iter)
	{
		if (coordinates_intersect(((t_env *)(iter)->content)->pos, her_pos))
			leave_game(set, LOOSE);
		else
			iter = (iter)->next;
		c++;
	}
	return (1);
}

void	check_collisions(t_dataset *set)
{
	hero_cols(set);
	hero_enemies(set);
	hero_exit(set);
}
