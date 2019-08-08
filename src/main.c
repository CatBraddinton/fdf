/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 18:22:05 by kdudko            #+#    #+#             */
/*   Updated: 2019/08/08 18:22:06 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	main(int ac, char *av[])
{
	t_data	*fdf;
	t_point	**map;

	if (ac != 2)
		error("usage: ./fdf path/to/map/file.fdf");
	if ((fdf = (t_data *)malloc(sizeof(t_data))) == NULL)
		error("malloc failed to allocate memory");
	init_data(fdf, av[1]);
	validate_input(fdf);
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
