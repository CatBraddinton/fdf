/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 15:29:23 by kdudko            #+#    #+#             */
/*   Updated: 2019/07/29 15:29:26 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static	void	parse_str(t_point *point, char *line, int size, int y)
{
	char	**arr;
	int		i;

	arr = ft_strsplit(line, ' ');
	i = 0;
	while (i < size)
	{
		point[i].x = i;
		point[i].y = y;
		point[i].z = ft_atoi(arr[i]);
		if ((ft_strchr(arr[i], ',')) == NULL)
			point[i].color = COLOR;
		else
			point[i].color = ft_hex_to_ul(ft_strchr(arr[i], ','));
		i++;
	}
	i = 0;
	while (i < size)
	{
		ft_strdel(&arr[i]);
		i++;
	}
	free(arr);
}

void			parse_map(t_map *map, char *prog_name)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	if ((fd = open(prog_name, O_RDONLY)) < 0)
		error_message("failed to open the file");
	if ((map->points = ft_memalloc(map->rows * sizeof(t_point *))) == NULL)
		error_message("failed to allocate memory for array of points structs");
	while ((get_next_line(fd, &line)) == 1)
	{
		if ((map->points[i] = ft_memalloc(map->cols * sizeof(t_point))) == NULL)
			error_message("malloc allocation failed");
		parse_str(map->points[i], line, map->cols, i);
		i++;
		ft_strdel(&line);
	}
}
