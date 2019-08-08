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
#include "../inc/colorize_it.h"
static void	choose_color(int keycode, t_data *fdf)
{
	if ((keycode == ONE) || (keycode == NUM_ONE))
	{
		fdf->params.s_color = SET1;
		fdf->params.f_color = SET11;
	}
	if ((keycode == TWO) || (keycode == NUM_TWO))
	{
		fdf->params.s_color = SET2;
		fdf->params.f_color = SET22;
	}
	if ((keycode == THREE) || (keycode == NUM_THREE))
	{
		fdf->params.s_color = SET3;
		fdf->params.f_color = SET33;
	}
}

static void	mover(int keycode, t_data *fdf)
{
	if (keycode == UP)
		fdf->params.center_y -= 10;
	if (keycode == DOWN)
		fdf->params.center_y += 10;
	if (keycode == LEFT)
		fdf->params.center_x -= 10;
	if (keycode == RIGHT)
		fdf->params.center_x += 10;
}

static void key_press2(int keycode, t_data *fdf)
{
	if (keycode == DEL)
		init_transformation(&(fdf->params), fdf);
	if (keycode == ROT_XP)
		if (fdf->params.x_angle < 360)
			fdf->params.x_angle += 0.05;
	if (keycode == ROT_XM)
		fdf->params.x_angle -= 0.05;
	if (keycode == ROT_YP)
		if (fdf->params.y_angle < 360)
			fdf->params.y_angle += 0.05;
	if (keycode == ROT_YM)
		fdf->params.y_angle -= 0.05;
	if (keycode == ROT_ZP)
		if (fdf->params.z_angle < 360)
			fdf->params.z_angle += 0.05;
	if (keycode == ROT_ZM)
		fdf->params.z_angle -= 0.05;
}

int			key_press(int keycode, t_data *fdf)
{
	if (keycode == ESC)
		exit(EXIT_SUCCESS);
	if (fdf->image == NULL && keycode == SPACE)
		display_image(fdf, fdf->map);
	if (fdf->image)
	{
		mlx_destroy_image(fdf->mlx, fdf->image);
		if (keycode == Z_UP)
			if (fdf->params.z_change < 100)
				fdf->params.z_change += 5;
		if (keycode == Z_DOWN)
			if (fdf->params.z_change > -100)
				fdf->params.z_change -= 5;
		if (keycode == ZOOM_P || keycode == PLUS)
			fdf->params.scale++;
		if (keycode == ZOOM_M || keycode == MINUS)
			fdf->params.scale--;
		if (keycode == I)
			fdf->params.projection = ISO;
		if (keycode == P)
			fdf->params.projection = PARALLEL;
		choose_color(keycode, fdf);
		key_press2(keycode, fdf);
		mover(keycode, fdf);
		display_image(fdf, fdf->map);
	}
	return (1);
}

