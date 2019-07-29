#include "../inc/fdf.h"

void		get_model_data(t_fdf *data)
{
	char	*line;
	char 	**map;
	int 	fd;
	int		y;
	int 	x;

	line = NULL;
	if ((fd = open(data->prog_name, O_RDONLY)) < 0)
		error_message("fdf failed to open the file");
	y = 0;
	while ((get_next_line(fd, &line)) == 1)
	{
		x = 0;
		ft_putendl(line);
		if ((map = ft_strsplit(line, ' ')) == NULL)
		error_message("ft_strsplit error");
		while (x < data->map->cols)
		{
			data->map->points[y * data->map->cols + x]->x = x;
			data->map->points[y * data->map->cols + x]->y = y;
			data->map->points[y * data->map->cols + x]->z = ft_atoi(map[x]);
			data->map->points[y * data->map->cols + x]->color = COLOR;
			ft_strdel(&map[x]);
			x++;
		}
		y++;
		ft_strdel(&line);
	}
}