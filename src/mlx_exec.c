/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 20:23:49 by kdudko            #+#    #+#             */
/*   Updated: 2019/07/31 20:00:32 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	mlx_exec(t_fdf *data, t_map *map)
{
	t_point	**new;

	(void)map;
	new = NULL;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, data->prog_name);
	ft_putendl("here1");
	init_new_object(new, map);
	ft_putendl("here2");
//	render_map(new, data, map->rows, map->cols);
//	ft_putendl("here3");
	draw_line(data, new[8][8], new[8][9]);

	mlx_loop(data->mlx);
}
