/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 05:27:09 by kdudko            #+#    #+#             */
/*   Updated: 2019/07/28 05:27:12 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	error_message(const char *str)
{
	ft_putendl(str);
	exit(EXIT_FAILURE);
}

void	free_all_structs(t_fdf *data, t_map *map)
{
	int i;

	i = -1;
	while (++i < map->rows)
		free(map->points[i]);
	free(map->points);
	free(map);
	free(data->prog_name);
	free(data);
}

void	init_transformation_params(t_param *transf)
{
	transf->scale = 0;
	transf->rotate_x = 0;
	transf->rotate_y = 0;
	transf->rotate_z = 0;
	transf->move_x = 0;
	transf->move_y = 0;
	transf->move_z = 0;
}
