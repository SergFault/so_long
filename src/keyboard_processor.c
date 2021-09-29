/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_processor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergey <sergey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:27:31 by sergey            #+#    #+#             */
/*   Updated: 2021/09/29 17:27:31 by sergey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	process_key(int key, t_dataset *set)
{
	(void) set;
	if (key == ESC)
		leave_game(set);
	if (key == UP)
		move(UP, &set->game->hero_pos, set->game);
	if (key == DOWN)
		move(DOWN, &set->game->hero_pos, set->game);
	if (key == LEFT)
		move(LEFT, &set->game->hero_pos, set->game);
	if (key == RIGHT)
		move(RIGHT, &set->game->hero_pos, set->game);
	return (0);
}
