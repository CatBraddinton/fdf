/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_infomenu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 18:52:12 by kdudko            #+#    #+#             */
/*   Updated: 2019/08/07 18:52:14 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/render.h"

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

static void	draw_box(t_data *fdf)
{
	t_point box[4];

	box[0].x = POINT1;
	box[0].y = POINT4;
	box[0].z = 0;
	box[0].color = COLOR;
	box[1].x = POINT2;
	box[1].y = POINT4;
	box[1].z = 0;
	box[1].color = COLOR;
	box[2].x = POINT1;
	box[2].y = POINT3;
	box[2].z = 0;
	box[2].color = COLOR;
	box[3].x = POINT2;
	box[3].y = POINT3;
	box[3].z = 0;
	box[3].color = COLOR;
	put_lines(box[0], box[1], fdf);
	put_lines(box[0], box[2], fdf);
	put_lines(box[1], box[3], fdf);
	put_lines(box[2], box[3], fdf);
}

void		draw_info_menu(t_data *fdf)
{
	mlx_string_put(fdf->mlx, fdf->window, 2120, 60, TEXT_COLOR,
			"FDF CONTROLS:");
	mlx_string_put(fdf->mlx, fdf->window, 2120, 90, TEXT_COLOR,
			"MOVE:            arrows");
	mlx_string_put(fdf->mlx, fdf->window, 2120, 110, TEXT_COLOR,
			"PARALLEL:        P");
	mlx_string_put(fdf->mlx, fdf->window, 2120, 130, TEXT_COLOR,
			"ISO:             I");
	mlx_string_put(fdf->mlx, fdf->window, 2120, 150, TEXT_COLOR,
			"ZOOM:            +  <->  -");
	mlx_string_put(fdf->mlx, fdf->window, 2120, 190, TEXT_COLOR,
			"ROTATE X:        Q  <->  E");
	mlx_string_put(fdf->mlx, fdf->window, 2120, 210, TEXT_COLOR,
			"ROTATE Y:        A  <->  D");
	mlx_string_put(fdf->mlx, fdf->window, 2120, 230, TEXT_COLOR,
			"ROTATE Z:        Z  <->  C");
	mlx_string_put(fdf->mlx, fdf->window, 2120, 250, TEXT_COLOR,
			"CHANGE HEIGHT:   PAGE UP  <->  PAGE DOWN");
	mlx_string_put(fdf->mlx, fdf->window, 2240, 1270, TEXT_COLOR,
			"by Kateryna Dudko");
	mlx_string_put(fdf->mlx, fdf->window, 2260, 1300, TEXT_COLOR,
			"UNIT Factory");
	mlx_string_put(fdf->mlx, fdf->window, 2300, 1330, TEXT_COLOR, "2019");
	draw_box(fdf);
}
