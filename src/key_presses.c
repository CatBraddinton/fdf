/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_presses.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:52:19 by kdudko            #+#    #+#             */
/*   Updated: 2019/08/06 19:52:21 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "hooks.h"

int	key_press2(int keycode, t_data *fdf)
{
	if (keycode == UP)
		fdf->params.center_y -= 20;
	if (keycode == DOWN)
		fdf->params.center_y += 20;
	if (keycode == LEFT)
		fdf->params.center_x -= 20;
	if (keycode == RIGHT)
		fdf->params.center_x += 20;
	if (keycode == ROT_XP)
		fdf->params.x_angle += 0.05;
	if (keycode == ROT_XM)
		fdf->params.x_angle -= 0.05;
	if (keycode == ROT_YP)
		fdf->params.y_angle += 0.05;
	if (keycode == ROT_YM)
		fdf->params.y_angle -= 0.05;
	if (keycode == ROT_ZP)
		fdf->params.z_angle += 0.05;
	if (keycode == ROT_ZM)
		fdf->params.z_angle -= 0.05;
	return (1);
}

int	key_press(int keycode, t_data *fdf)
{
	if (keycode == ESC)
		exit(EXIT_SUCCESS);
	if (fdf->image == NULL && keycode == SPACE)
		display_image(fdf, fdf->map);
	if (fdf->image)
	{
		mlx_destroy_image(fdf->mlx, fdf->image);
		if (keycode == Z_UP)
			fdf->params.z_change += 5;
		if (keycode == Z_DOWN)
			fdf->params.z_change -= 5;
		if (keycode == ZOOM_P)
			fdf->params.scale++;
		if (keycode == ZOOM_M)
			fdf->params.scale--;
		if (keycode == I)
			fdf->params.projection = ISO;
		if (keycode == P)
			fdf->params.projection = PARALLEL;
		key_press2(keycode, fdf);
		display_image(fdf, fdf->map);
	}
	return (1);
}
