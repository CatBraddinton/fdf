/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 20:24:18 by kdudko            #+#    #+#             */
/*   Updated: 2019/07/30 20:24:20 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	render_map(t_point **points, t_fdf *data, int rows, int cols)
{
	int x;
	int y;

	y = 0;

	while (y < rows)
	{
		x = 0;
		while (x < cols)
		{
			if (x < cols - 1)
				draw_line(data, points[y][x], points[y][x + 1]);
			if (y < rows - 1)
				draw_line(data, points[y][x], points[y + 1][x]);
			x++;
		}
		y++;
	}
}
