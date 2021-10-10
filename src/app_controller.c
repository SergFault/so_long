/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_controller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergey <sergey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:27:05 by sergey            #+#    #+#             */
/*   Updated: 2021/09/29 17:27:05 by sergey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	leave_game(t_dataset *set)
{
	ft_lstclear(&(set->game->collectibles), free_env_obj);
	ft_lstclear(&(set->game->exits), free_env_obj);
	free_data(set);
	free_map(set->game->map, set->game->map_height);
	exit(0);
}
