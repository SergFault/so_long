/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map_content.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergey <sergey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:27:11 by sergey            #+#    #+#             */
/*   Updated: 2021/09/29 17:27:11 by sergey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	cnt_map_content(t_list *map, t_objs_number *objs)
{
	char	*line;

	while (map)
	{
		line = (char *)map->content;
		while (*line)
		{
			if (*line == COLL_CH)
				objs->collectable++;
			else if (*line == EXIT_CH)
				objs->exit++;
			else if (*line == HERO_CH)
				objs->player++;
			line++;
		}
		map = map->next;
	}
	return (1);
}

int	check_map_content(t_list *map)
{
	t_objs_number	objs;

	objs.player = 0;
	objs.collectable = 0;
	objs.exit = 0;
	cnt_map_content(map, &objs);
	if ((objs.exit < 1) || (objs.collectable < 1) || (objs.player < 1))
		return (0);
	return (1);
}
