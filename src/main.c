/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 05:27:16 by kdudko            #+#    #+#             */
/*   Updated: 2019/07/28 05:27:18 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
void	print_structs(t_point **p, int cols, int rows)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			printf("[%d][%d]: x: %d y: %d z: %d, color: %lu\n",
					i, j, p[i][j].x, p[i][j].y, p[i][j].z, p[i][j].color);
}

int	main(int ac, char *av[])
{
	t_fdf	*data;
	t_map	*map;
	t_img	*img;

	if (ac != 2 || av[1] == NULL)
		error_message("usage: ./fdf [path/to/map/file.fdf]");
	if ((data = ft_memalloc(sizeof(t_fdf))) == NULL)
		error_message("malloc failed to allocate data struct");
	data->prog_name = ft_strdup(av[1]);
	if ((map = ft_memalloc(sizeof(t_map))) == NULL)
		error_message("malloc failed to allocate map struct");
	if ((img = ft_memalloc(sizeof(t_img))) == NULL)
		error_message("malloc failed to allocate map struct");
	validation(data->prog_name, map);
	parse_map(map, data->prog_name);
	mlx_exec(data, img, map);
	free_all_structs(data, map);
	return (0);
}
