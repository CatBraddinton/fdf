/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 20:24:07 by kdudko            #+#    #+#             */
/*   Updated: 2019/07/30 20:24:09 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	count_iso(int *x, int *y, int z)
{
	int init_x;
	int init_y;

	init_x = *x;
	init_y = *y;
	*x = (init_x - init_y) * cos(0.523599);
	*y = -z + (init_x - init_y) * sin(0.523599);
}

void		count_projection(t_point points, t_fdf data)
{
	if (data.camera.projection == ISO)
		count_iso(&(points.x), &(points.y), z);
}
