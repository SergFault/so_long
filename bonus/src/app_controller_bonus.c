/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_controller_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergey <sergey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:23:42 by sergey            #+#    #+#             */
/*   Updated: 2021/09/29 17:23:42 by sergey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

static void	destroy_images(t_rend *rend)
{
	mlx_destroy_image(rend->mlx, rend->main_img.img);
	mlx_destroy_image(rend->mlx, rend->floor.img);
	mlx_destroy_image(rend->mlx, rend->wall.img);
	mlx_destroy_image(rend->mlx, rend->collectible.img);
	mlx_destroy_image(rend->mlx, rend->exit.img);
	mlx_destroy_image(rend->mlx, rend->hero0.img);
	mlx_destroy_image(rend->mlx, rend->hero1.img);
	mlx_destroy_image(rend->mlx, rend->hero2.img);
	mlx_destroy_image(rend->mlx, rend->hero3.img);
	mlx_destroy_image(rend->mlx, rend->hero4.img);
	mlx_destroy_image(rend->mlx, rend->hero5.img);
	mlx_destroy_image(rend->mlx, rend->enemy0.img);
	mlx_destroy_image(rend->mlx, rend->enemy1.img);
	mlx_destroy_image(rend->mlx, rend->enemy2.img);
	mlx_destroy_image(rend->mlx, rend->enemy3.img);
	mlx_destroy_image(rend->mlx, rend->enemy4.img);
	mlx_destroy_image(rend->mlx, rend->enemy5.img);
}

int	leave_game(t_dataset *set, int status)
{
	if (status == WIN)
		print_end(set, DARK_GREEN, WIN_MSG);
	else if (status == LOOSE)
		print_end(set, DARK_RED, LOOSE_MSG);
	else if (status == LEAVE)
		print_end(set, DARK_RED, LEAVE_MSG);
	destroy_images(set->rend);
	mlx_destroy_window(set->rend->mlx, set->rend->win);
	mlx_destroy_display(set->rend->mlx);
	mlx_loop_end(set->rend->mlx);
	free(set->rend->mlx);
	ft_lstclear(&(set->game->collectibles), free_env_obj);
	ft_lstclear(&(set->game->exits), free_env_obj);
	ft_lstclear(&(set->game->enemies), free_env_obj);
	free_data(set);
	free_map(set->game->map, set->game->map_height);
	exit(0);
}
