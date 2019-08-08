/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 18:21:32 by kdudko            #+#    #+#             */
/*   Updated: 2019/08/08 18:21:34 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/render.h"

void	init_transformation(t_change *params, t_data *fdf)
{
	int temp;
	int temp2;

	temp = W_IMAGE / fdf->width / 3;
	temp2 = H_IMAGE / fdf->height / 2;
	params->scale = (temp < temp2) ? temp : temp2;
	params->z_change = 5;
	params->projection = ISO;
	params->center_x = W_IMAGE / 2;
	params->center_y = H_IMAGE / 2;
	params->x_angle = 0.0;
	params->y_angle = 0.0;
	params->z_angle = 0.0;
	params->s_color = SET8;
	params->f_color = SET88;
}

void	init_data(t_data *fdf, char *name)
{
	fdf->name = ft_strdup(name);
	fdf->mlx = NULL;
	fdf->window = NULL;
	fdf->image = NULL;
	fdf->height = 0;
	fdf->width = 0;
	fdf->bpp = 0;
	fdf->size_line = 0;
	fdf->endian = 0;
}

void	init_line(t_draw *line, t_point p0, t_point p1)
{
	line->grad = 0.0;
	line->dx = 0.0;
	line->dy = 0.0;
	line->inter_x = 0.0;
	line->inter_y = 0.0;
	line->x = p0.x;
	line->y = p0.y;
	line->color_p0 = p0.color;
	line->color_p1 = p1.color;
	line->x0 = p0.x;
	line->y0 = p0.y;
	line->x1 = p1.x;
	line->y1 = p1.y;
	line->color.dist = 0.0;
	line->color.place = 0.0;
	line->color.percent = 0.0;
	line->color.delta = 0.0;
	line->color.r = 0;
	line->color.g = 0;
	line->color.b = 0;
}
