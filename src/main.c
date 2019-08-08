/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 14:36:58 by kdudko            #+#    #+#             */
/*   Updated: 2019/08/06 14:37:04 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	main(int ac, char *av[])
{
	t_data	*fdf;
	t_point	**map;

	if (ac != 2 && ac != 4)
		error("usage: ./fdf path/to/map/file.fdf [color_1 color_2]");
	if ((fdf = (t_data *)malloc(sizeof(t_data))) == NULL)
		error("malloc failed to allocate memory");
	init_data(fdf, av[1]);
	validate_input(fdf, av, ac);
	allocate_map(&map, fdf->height, fdf->width);
	init_transformation(&(fdf->params), fdf);
	fparser(fdf, map);
	fdf->map = map;
	if ((fdf->mlx = mlx_init()) == NULL)
		error("mlx initialization failed");
	fdf->window = mlx_new_window(fdf->mlx, W_WINDOW, H_WINDOW, fdf->name);
	if (fdf->window == NULL)
		error("mlx failed to create a window");
	draw_info_menu(fdf);
	mlx_hook(fdf->window, 2, 0, key_press, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
