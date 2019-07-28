/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2d_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 02:48:27 by kdudko            #+#    #+#             */
/*   Updated: 2019/07/28 02:49:36 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_map_arr(char **map, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_strdel(&map[i]);
		i++;
	}
	ft_strdel(&map[i]);
	free(map);
}
