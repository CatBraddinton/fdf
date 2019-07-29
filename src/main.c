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


int	main(int ac, char *av[])
{
	t_fdf	*data;

	if (ac != 2 || av[1] == NULL)
		error_message("usage: ./fdf [path/to/map/file.fdf]");
	if ((data = ft_memalloc(sizeof(t_fdf))) == NULL)
		error_message("malloc allocation failed");
	if ((data->map = ft_memalloc(sizeof(t_map))) == NULL)
		error_message("malloc allocation failed");
	if ((data->map->points = ft_memalloc(data->map->cols *
			data->map->rows * sizeof(t_point))) == NULL)
		error_message("malloc allocation failed");
	data->prog_name = ft_strdup(av[1]);
	validation(data);
	get_model_data(data);
	free_all_structs(data);
	system("leaks fdf");
	return (0);
}
