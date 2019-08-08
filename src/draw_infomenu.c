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
#include "../inc/info.h"

static void	display_specials(t_data *fdf)
{
	mlx_string_put(fdf->mlx, fdf->window, OFFSET_L, 50, SPECIALS,
				   "EXIT FDF:          ESC");
	mlx_string_put(fdf->mlx, fdf->window, OFFSET_L, 70, SPECIALS,
				   "UNDO ALL CHANGES:  DELETE");
	mlx_string_put(fdf->mlx, fdf->window, OFFSET_L, 100, SPECIALS,
				   "FDF CONTROLS:");
	mlx_string_put(fdf->mlx, fdf->window, 2240, 1270, SPECIALS,
				   "by Kateryna Dudko");
	mlx_string_put(fdf->mlx, fdf->window, 2260, 1300, SPECIALS,
				   "UNIT Factory");
	mlx_string_put(fdf->mlx, fdf->window, 2300, 1330, SPECIALS, "2019");
}

static void	transformations(t_data *fdf)
{
	mlx_string_put(fdf->mlx, fdf->window, OFFSET_L, 130, TEXT_COLOR,
				   "MOVE:              arrows");
	mlx_string_put(fdf->mlx, fdf->window, OFFSET_L, 150, TEXT_COLOR,
				   "PARALLEL:          P");
	mlx_string_put(fdf->mlx, fdf->window, OFFSET_L, 170, TEXT_COLOR,
				   "ISO:               I");
	mlx_string_put(fdf->mlx, fdf->window, OFFSET_L, 190, TEXT_COLOR,
				   "ZOOM:              +  <->  -");
	mlx_string_put(fdf->mlx, fdf->window, OFFSET_L, 210, TEXT_COLOR,
				   "ROTATE X:          Q  <->  E");
	mlx_string_put(fdf->mlx, fdf->window, OFFSET_L, 230, TEXT_COLOR,
				   "ROTATE Y:          A  <->  D");
	mlx_string_put(fdf->mlx, fdf->window, OFFSET_L, 250, TEXT_COLOR,
				   "ROTATE Z:          Z  <->  C");
	mlx_string_put(fdf->mlx, fdf->window, OFFSET_L, 270, TEXT_COLOR,
				   "CHANGE Z_HEIGHT:   PAGE UP  <->  PAGE DOWN");
}

void		draw_info_menu(t_data *fdf)
{
	display_specials(fdf);
	transformations(fdf);
	draw_box(fdf);
}
