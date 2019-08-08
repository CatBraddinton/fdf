/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_presses.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 18:21:50 by kdudko            #+#    #+#             */
/*   Updated: 2019/08/08 18:21:52 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	choose_color2(int keycode, t_data *fdf)
{
	if ((keycode == SIX) || (keycode == NUM_SIX))
	{
		fdf->params.s_color = SET6;
		fdf->params.f_color = SET66;
	}
	if ((keycode == SEVEN) || (keycode == NUM_SEVEN))
	{
		fdf->params.s_color = SET7;
		fdf->params.f_color = SET77;
	}
	if ((keycode == EIGHT) || (keycode == NUM_EIGHT))
	{
		fdf->params.s_color = SET8;
		fdf->params.f_color = SET88;
	}
	if ((keycode == NINE) || (keycode == NUM_NINE))
	{
		fdf->params.s_color = SET9;
		fdf->params.f_color = SET99;
	}
	if ((keycode == ZERO) || (keycode == NUM_ZERO))
	{
		fdf->params.s_color = SET0;
		fdf->params.f_color = SET00;
	}
}

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
	if ((keycode == FOUR) || (keycode == NUM_FOUR))
	{
		fdf->params.s_color = SET4;
		fdf->params.f_color = SET44;
	}
	if ((keycode == FIVE) || (keycode == NUM_FIVE))
	{
		fdf->params.s_color = SET5;
		fdf->params.f_color = SET55;
	}
}

static void	mover(int keycode, t_data *fdf)
{
	if (keycode == UP)
		fdf->params.center_y -= 15;
	if (keycode == DOWN)
		fdf->params.center_y += 15;
	if (keycode == LEFT)
		fdf->params.center_x -= 15;
	if (keycode == RIGHT)
		fdf->params.center_x += 15;
}

static void	key_press2(int keycode, t_data *fdf)
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
	if (keycode == I)
		fdf->params.projection = ISO;
	if (keycode == P)
		fdf->params.projection = PARALLEL;
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
		choose_color(keycode, fdf);
		choose_color2(keycode, fdf);
		key_press2(keycode, fdf);
		mover(keycode, fdf);
		display_image(fdf, fdf->map);
	}
	return (1);
}
