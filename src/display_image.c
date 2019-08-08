/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:04:21 by kdudko            #+#    #+#             */
/*   Updated: 2019/08/06 15:04:22 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/render.h"
static void	move(t_point ***nmap, t_change params, int y, int x)
{
	x_axis(&((*nmap)[y][x].y), &((*nmap)[y][x].z), params.x_angle);
	y_axis(&((*nmap)[y][x].x), &((*nmap)[y][x].z), params.y_angle);
	z_axis(&((*nmap)[y][x].x), &((*nmap)[y][x].y), params.z_angle);
	if (params.projection == ISO)
		iso(&((*nmap)[y][x].x), &((*nmap)[y][x].y), (*nmap)[y][x].z);
	(*nmap)[y][x].x += params.center_x;
	(*nmap)[y][x].y += params.center_y;
}
<<<<<<< HEAD
static void	put_color_on_map(t_point ***nmap, t_data *fdf, int y, int x)
{
	printf("%d\n", fdf->change_colors);
	if ((*nmap)[y][x].z != 0 && fdf->map[y][x].color == DEFAULT
		&& fdf->change_colors == 1)
		(*nmap)[y][x].color = fdf->params.f_color;
	else if ((*nmap)[y][x].z == 0 && fdf->map[y][x].color == DEFAULT
			 && fdf->change_colors == 1)
		(*nmap)[y][x].color = fdf->params.s_color;
	else if ((*nmap)[y][x].z != 0 && fdf->user_colors == 1 &&
			 fdf->map[y][x].color == fdf->params.s_color)
		(*nmap)[y][x].color = fdf->params.f_color;
	else if ((*nmap)[y][x].z == 0 && fdf->user_colors == 1 &&
			 fdf->map[y][x].color == fdf->params.s_color)
		(*nmap)[y][x].color = fdf->params.s_color;
	else
		(*nmap)[y][x].color = fdf->map[y][x].color;
}
=======
>>>>>>> b5cd53806c39b4179fc0829b54968486c9a36408

static void	change(t_point ***nmap, t_point **map, t_change params, t_data *fdf)
{
	int y;
	int x;

	y = -1;
	while (++y < fdf->height)
	{
		x = -1;
		while (++x < fdf->width)
		{
			(*nmap)[y][x].x = map[y][x].x * params.scale -
							  (fdf->width * params.scale) / 2;
			(*nmap)[y][x].y = map[y][x].y * params.scale - (fdf->height *
															params.scale) / 2;
			(*nmap)[y][x].z = map[y][x].z * params.scale * params.z_change
							  / 100;
			if (map[y][x].z != 0  && map[y][x].color == DEFAULT)
				(*nmap)[y][x].color = params.f_color;
			else if (map[y][x].z == 0 &&  map[y][x].color == DEFAULT)
				(*nmap)[y][x].color = params.s_color;
			move(nmap, params, y, x);
		}
	}
}

void		display_image(t_data *fdf, t_point **map)
{
	int		y;
	int		x;
	t_point	**new_map;

	allocate_map(&new_map, fdf->height, fdf->width);
	change(&new_map, map, fdf->params, fdf);
	fdf->image = mlx_new_image(fdf->mlx, W_IMAGE, H_IMAGE);
	fdf->ibuff = mlx_get_data_addr(fdf->image, &(fdf->bpp), &(fdf->size_line),
								   &(fdf->endian));
	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			if (x + 1 <= fdf->width - 1)
				draw_lines(new_map[y][x], new_map[y][x + 1], fdf);
			if (y + 1 <= fdf->height - 1)
				draw_lines(new_map[y][x], new_map[y + 1][x], fdf);
			x++;
		}
		y++;
	}
	free_arr(fdf, new_map);
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->image, 0, 0);
}
