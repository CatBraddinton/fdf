/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_straight_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:09:46 by kdudko            #+#    #+#             */
/*   Updated: 2019/08/06 15:09:47 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/render.h"

void	draw_straight_line(t_data *fdf, t_draw *line, t_point p0, t_point p1)
{
	line->x0 = p0.x;
	line->y0 = p0.y;
	line->x1 = p1.x;
	line->y1 = p1.y;
	line->x = (line->x1 > line->x0) ? line->x0 : line->x1;
	line->y = (line->y1 > line->y0) ? line->y0 : line->y1;
	while (line->x < line->x1)
	{
		fdf_put_pixel(fdf, line->x, line->y, line->color_p0);
		line->x++;
	}
//	while (line->y < line->y1)
//	{
//		fdf_put_pixel(fdf, line->x, line->y, line->color_p0);
//		line->y++;
//	}
}
