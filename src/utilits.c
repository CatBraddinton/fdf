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

void		error(char *str)
{
	ft_putendl(str);
	exit(EXIT_FAILURE);
}

void		allocate_map(t_point ***map, int rows, int cols)
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

void		free_arr(t_data *fdf, t_point **new_map)
{
	int y;

	y = 0;
	while (y < fdf->height)
	{
		ft_memdel((void **)new_map + y);
		y++;
	}
	free(new_map);
}

static void	put_lines(t_point p0, t_point p1, t_data *fdf)
{
	int x;
	int y;

	x = (p1.x > p0.x) ? p0.x : p1.x;
	y = (p1.y > p0.y) ? p0.y : p1.y;
	while (x < p1.x)
	{
		mlx_pixel_put(fdf->mlx, fdf->window, x, y, BORDER_COLOR);
		x++;
	}
	while (y < p1.y)
	{
		mlx_pixel_put(fdf->mlx, fdf->window, x, y, BORDER_COLOR);
		y++;
	}
}

void		draw_box(t_data *fdf)
{
	t_point box[4];

	box[0].x = POINT1;
	box[0].y = POINT4;
	box[0].z = 0;
	box[0].color = BORDER_COLOR;
	box[1].x = POINT2;
	box[1].y = POINT4;
	box[1].z = 0;
	box[1].color = BORDER_COLOR;
	box[2].x = POINT1;
	box[2].y = POINT3;
	box[2].z = 0;
	box[2].color = BORDER_COLOR;
	box[3].x = POINT2;
	box[3].y = POINT3;
	box[3].z = 0;
	box[3].color = BORDER_COLOR;
	put_lines(box[0], box[1], fdf);
	put_lines(box[0], box[2], fdf);
	put_lines(box[1], box[3], fdf);
	put_lines(box[2], box[3], fdf);
}
