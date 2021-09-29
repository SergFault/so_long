/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_cons_only_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergey <sergey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:25:48 by sergey            #+#    #+#             */
/*   Updated: 2021/09/29 17:25:48 by sergey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

int	ft_str_cons_only(char *str, char ch)
{
	while (*str)
	{
		if (*str != ch)
			return (0);
		str++;
	}
	return (1);
}
