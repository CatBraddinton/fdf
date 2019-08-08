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
#include "../inc/colorize_it.h"

static void	parse_str(t_data *fdf, t_point **map, char *line, int y)
{
	char	**arr;
	int		i;

	arr = ft_strsplit(line, ' ');
	i = 0;
	while (i < fdf->width)
	{
		map[y][i].x = i;
		map[y][i].y = y;
		map[y][i].z = ft_atoi(arr[i]);
		if ((ft_strchr(arr[i], ',')) == NULL)
			map[y][i].color = DEFAULT;
		else
			map[y][i].color = ft_atoi_base((ft_strchr(arr[i], ',')) + 1, 16);
		i++;
	}
	i = 0;
	while (i < fdf->width)
	{
		free(arr[i]);
		i++;
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
		parse_str(fdf, map, line, i);
		i++;
		free(line);
	}
	close(fd);
}
