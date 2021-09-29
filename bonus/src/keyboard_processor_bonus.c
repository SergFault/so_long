/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_processor_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergey <sergey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:24:37 by sergey            #+#    #+#             */
/*   Updated: 2021/09/29 17:24:37 by sergey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

int	process_key(int key, t_dataset *set)
{
	(void) set;
	if (key == ESC)
		leave_game(set, LEAVE);
	if (key == UP)
		move(UP, &set->game->hero_pos, set);
	if (key == DOWN)
		move(DOWN, &set->game->hero_pos, set);
	if (key == LEFT)
		move(LEFT, &set->game->hero_pos, set);
	if (key == RIGHT)
		move(RIGHT, &set->game->hero_pos, set);
	return (0);
}
