#include "../inc/fdf.h"

static void	find_coordinates(t_fdf *data, char *line, t_point *all, int y0)
{
	char	**map;
	int		i;
	int 	x0;
	int 	len;

	map = ft_strsplit(line, ' ');
	i = y0 * data->cols;
	x0 = 0;
	while (x0 < data->cols)
	{
		len = ft_strlen(map[x0]);
		all[i].x = x0;
		all[i].y = y0;
		all[i].z = ft_atoi(map[x0]);
		if (len >= 10)
			all[i].color = ft_hex_to_ul(ft_strchr(map[x0], ',') + 1);
		else
			all[i].color = COLOR;
		x0++;
	}
	free_2d_arr(map, data->cols);
}

int			fdf(t_fdf *data, t_point *all, char *name)
{
	int		fd;
	char	*line;
	int 	y;

	fd = open(name, O_RDONLY);
	line = NULL;
	y = 0;
	while ((get_next_line(fd, &line)) == 1)
	{
		find_coordinates(data, line, all, y);
		y++;
		free(line);
	}
	close (fd);
	return (1);
}
