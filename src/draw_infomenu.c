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

static void	display_specials(t_data *fdf)
{
	mlx_string_put(fdf->mlx, fdf->window, 1000, 1200, SPECIALS,
				   "Press SPACE to start");
	mlx_string_put(fdf->mlx, fdf->window, OFFSET_L, 50, SPECIALS,
				   "EXIT FDF:          ESC");
	mlx_string_put(fdf->mlx, fdf->window, OFFSET_L, 70, SPECIALS,
				   "UNDO ALL CHANGES:  DELETE");
	mlx_string_put(fdf->mlx, fdf->window, OFFSET_L, 100, SPECIALS,
				   "CHANGE COLOR:      0 ... 9");
	mlx_string_put(fdf->mlx, fdf->window, OFFSET_L, KEYS, SPECIALS,
				   "FDF CONTROLS:");
	mlx_string_put(fdf->mlx, fdf->window, OFFSET_L + 140, 1270, SPECIALS,
				   "by Kateryna Dudko");
	mlx_string_put(fdf->mlx, fdf->window, OFFSET_L + 160, 1300, SPECIALS,
				   "UNIT Factory");
	mlx_string_put(fdf->mlx, fdf->window, OFFSET_L + 200, 1330, SPECIALS,
			"2019");
}

static void	transformations(t_data *fdf)
{
	mlx_string_put(fdf->mlx, fdf->window, OFFSET_L, KEYS + 20, TEXT_COLOR,
				   "MOVE:              arrows");
	mlx_string_put(fdf->mlx, fdf->window, OFFSET_L, KEYS + 40, TEXT_COLOR,
				   "PARALLEL:          P");
	mlx_string_put(fdf->mlx, fdf->window, OFFSET_L, KEYS + 60, TEXT_COLOR,
				   "ISO:               I");
	mlx_string_put(fdf->mlx, fdf->window, OFFSET_L, KEYS + 80, TEXT_COLOR,
				   "ZOOM:              +  <->  -");
	mlx_string_put(fdf->mlx, fdf->window, OFFSET_L, KEYS + 100, TEXT_COLOR,
				   "ROTATE X:          Q  <->  E");
	mlx_string_put(fdf->mlx, fdf->window, OFFSET_L, KEYS + 120, TEXT_COLOR,
				   "ROTATE Y:          A  <->  D");
	mlx_string_put(fdf->mlx, fdf->window, OFFSET_L, KEYS + 140, TEXT_COLOR,
				   "ROTATE Z:          Z  <->  C");
	mlx_string_put(fdf->mlx, fdf->window, OFFSET_L, KEYS + 160, TEXT_COLOR,
				   "CHANGE Z_HEIGHT:   PAGE UP  <->  PAGE DOWN");
}

static void	colors(t_data *fdf)
{
	(void)fdf;
}

void		draw_info_menu(t_data *fdf)
{


	draw_box(fdf);
	display_specials(fdf);
	transformations(fdf);
	colors(fdf);
}
