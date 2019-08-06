/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 16:42:45 by kdudko            #+#    #+#             */
/*   Updated: 2019/08/06 16:42:47 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	error(char *str)
{
	ft_putendl(str);
	exit(EXIT_FAILURE);
}

void	allocate_map(t_point ***map, int rows, int cols)
{
	int i;

	(*map) = (t_point **)malloc(rows * sizeof(t_point *));
	if ((*map) == NULL)
		error("failed to allocate map rows");
	i = 0;
	while (i < rows)
	{
		(*map)[i] = (t_point *)malloc(cols * sizeof(t_point));
		if ((*map)[i] == NULL)
			error("failed to allocate map cols");
		i++;
	}
}
