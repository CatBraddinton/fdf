/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fparser.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 14:42:34 by kdudko            #+#    #+#             */
/*   Updated: 2019/08/06 14:42:36 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	parse_str(t_point **map, char *line, int size, int y)
{
	char	**arr;
	int		i;

	arr = ft_strsplit(line, ' ');
	i = 0;
	while (i < size)
	{
		map[y][i].x = i;
		map[y][i].y = y;
		map[y][i].z = ft_atoi(arr[i]);
		if ((ft_strchr(arr[i], ',')) == NULL)
			map[y][i].color = COLOR;
		else
			map[y][i].color = ft_hex_to_ul((ft_strchr(arr[i], ',')) + 1);
		i++;
	}
	while (--i > 0)
	{
		ft_strdel(&arr[i]);
	}
	free(arr);
}

void		fparser(t_data *fdf, t_point **map)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	if ((fd = open(fdf->name, O_RDONLY)) < 0)
		error("failed to open the file");
	while (i < fdf->height)
	{
		get_next_line(fd, &line);
		parse_str(map, line, fdf->width, i);
		i++;
		free(line);
	}
	close(fd);
}
