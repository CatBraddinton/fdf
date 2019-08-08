/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorize_it.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 00:38:31 by kdudko            #+#    #+#             */
/*   Updated: 2019/08/08 18:18:33 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/render.h"

static int	get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int			count_gradient(t_draw *line)
{
	if (line->color_cur == line->color_p1)
		return (line->color_cur);
	if (line->color.delta == 0)
	{
		line->color.place = line->x - line->x0;
		line->color.dist = line->x1 - line->x0;
		line->color.percent = (line->color.dist == 0) ? 1.0 :
				(line->color.place / line->color.dist);
	}
	else if (line->color.delta == 1)
	{
		line->color.place = line->y - line->y0;
		line->color.dist = line->y1 - line->y0;
		line->color.percent = (line->color.dist == 0) ? 1.0 :
				(line->color.place / line->color.dist);
	}
	line->color.r = get_light((line->color_cur >> 16) & 0xFF,
			(line->color_p1 >> 16) & 0xFF, line->color.percent);
	line->color.g = get_light((line->color_cur >> 8) & 0xFF,
			(line->color_p1 >> 8) & 0xFF, line->color.percent);
	line->color.b = get_light(line->color_cur & 0xFF,
			line->color_p1 & 0xFF, line->color.percent);
	return ((line->color.r << 16) | (line->color.g << 8) | line->color.b);
}
