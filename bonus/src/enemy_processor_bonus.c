/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_processor_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergey <sergey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:24:15 by sergey            #+#    #+#             */
/*   Updated: 2021/09/29 17:24:15 by sergey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

static void	change_en_pos(char axis, int val, t_coordinates *pos)
{
	if (axis == 'x')
		pos->x += val;
	else if (axis == 'y')
		pos->y += val;
}

void	move_enemy(int direction, t_coordinates *pos, t_game *game)
{
	if (direction == UP && (!check_wall(pos->x, pos->y - 1, game->map)))
		change_en_pos('y', -1, pos);
	if (direction == DOWN && (!check_wall(pos->x, pos->y + 1, game->map)))
		change_en_pos('y', 1, pos);
	if (direction == LEFT && (!check_wall(pos->x - 1, pos->y, game->map)))
		change_en_pos('x', -1, pos);
	if (direction == RIGHT && (!check_wall(pos->x + 1, pos->y, game->map)))
		change_en_pos('x', 1, pos);
}

void	move_enemies(t_list *enemies, t_game *game)
{
	if (game->time % (6 * TICK) == 0)
	{
		while (enemies)
		{
			if (random_g(&game->seed_g, 4) == 1)
				move_enemy(UP, enemies->content, game);
			else if (random_g(&game->seed_g, 4) == 2)
				move_enemy(LEFT, enemies->content, game);
			else if (random_g(&game->seed_g, 4) == 3)
				move_enemy(DOWN, enemies->content, game);
			else if (random_g(&game->seed_g, 4) == 4)
				move_enemy(RIGHT, enemies->content, game);
			enemies = enemies->next;
		}
	}
}

static t_coordinates	get_rnd_space(t_dataset *set, int height, int width,
								   t_coordinates *coord)
{
	int				i;
	int				j, s;
	t_coordinates	hero_pos;
	i = 0;
	j = 0;
	s = 20;

	(void)height;
	(void)width;

	hero_pos = set->game->hero_pos;
	while (coord->x == 0)
	{
		i = random_g(&(set->game->seed_g), height - 1);
		j = random_g(&(set->game->seed_g), width - 1);
		while (i)
		{
			while (j)
			{
				if ((set->game->map[i][j] == FLOOR_CH && i != hero_pos.y)
					&& j != hero_pos.x
					&& !(i == hero_pos.y && j == hero_pos.x))
					return (*(coordinates_init(coord, j, i)));
				j--;
			}
			i--;
		}
	}
	return (*coord);
}

void	enemy_init(t_dataset *set)
{
	int				c;
	t_list			*lst;
	t_env			*enemy;
	t_coordinates	temp_coord;

	c = ENEMIES_NUM;
	lst = NULL;
	while (c)
	{
		temp_coord.x = 0;
		temp_coord.y = 0;
		enemy = (t_env *)malloc(sizeof(t_env));
		enemy->pos = get_rnd_space(set,
				set->game->map_height,
				set->game->map_width,
				&temp_coord);
		ft_lstadd_back(&lst, ft_lstnew(enemy));
		c--;
	}
	set->game->enemies = lst;
}
