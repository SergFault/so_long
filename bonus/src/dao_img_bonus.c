/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dao_img_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergey <sergey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:24:06 by sergey            #+#    #+#             */
/*   Updated: 2021/09/29 17:24:06 by sergey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

t_img	*get_hero_image(t_rend *rend, int time)
{
	if (time < 1 * TICK)
		return (&rend->hero0);
	else if (time < 2 * TICK)
		return (&rend->hero1);
	if (time < 3 * TICK)
		return (&rend->hero2);
	if (time < 4 * TICK)
		return (&rend->hero3);
	if (time < 5 * TICK)
		return (&rend->hero4);
	else
		return (&rend->hero5);
}

t_img	*get_enemy_image(t_rend *rend, int time)
{
	if (time < 1 * TICK)
		return (&rend->enemy0);
	else if (time < 2 * TICK)
		return (&rend->enemy1);
	if (time < 3 * TICK)
		return (&rend->enemy2);
	if (time < 4 * TICK)
		return (&rend->enemy3);
	if (time < 5 * TICK)
		return (&rend->enemy4);
	else
		return (&rend->enemy5);
}
