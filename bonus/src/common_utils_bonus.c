/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergey <sergey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:24:02 by sergey            #+#    #+#             */
/*   Updated: 2021/09/29 17:24:02 by sergey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

t_coordinates	*coordinates_init(t_coordinates *pos_p, int x, int y)
{
	pos_p->x = x;
	pos_p->y = y;
	return (pos_p);
}
