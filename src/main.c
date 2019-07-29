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
	t_map	*map;

	if (ac != 2 || av[1] == NULL)
		error_message("usage: ./fdf [path/to/map/file.fdf]");
	if ((data = ft_memalloc(sizeof(t_fdf))) == NULL)
		error_message("malloc failed to allocate data struct");
	data->prog_name = ft_strdup(av[1]);
	if ((map = ft_memalloc(sizeof(t_map))) == NULL)
		error_message("malloc failed to allocate map struct");
	validation(data->prog_name, map);
	parse_map(map, data->prog_name);
	free_all_structs(data, map);
	system("leaks fdf");
	return (0);
}
