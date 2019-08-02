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

void			fparser(t_data *fdf)
{
	int fd;
	char *line;
	int i;

	i = 0;
	line = NULL;
	if ((fd = open(fdf->name, O_RDONLY)) < 0)
		error("failed to open the file");
	if ((fdf->map = ft_memalloc(fdf->height * sizeof(t_point *))) == NULL)
		error("failed to allocate memory for map");
	while ((get_next_line(fd, &line)) == 1) {
		if ((fdf->map[i] = ft_memalloc(fdf->width * sizeof(t_point))) == NULL)
			error("malloc allocation failed");
		parse_str(fdf->map[i], line, fdf->width, i);
		i++;
		ft_strdel(&line);
	}
}

