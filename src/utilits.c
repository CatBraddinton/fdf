#include "../inc/fdf.h"

void			error(char *str)
{
	ft_putendl(str);
	exit(EXIT_FAILURE);
}



void		init_transformation(t_change *params, t_data *fdf)
{
	(void)fdf;
	params->scale = 55;
	params->move_up = 0;
	params->move_left = 0;
	params->move_right = 0;
	params->move_down = 0;
	params->z_change = 10;
	params->projection = ISO;
	params->center_x = W_WINDOW / 2;
	params->center_y = H_WINDOW / 2;
}

void			init_data(t_data *fdf, char *name)
{
	fdf->name = ft_strdup(name);
	fdf->height = 0;
	fdf->width = 0;
	fdf->bpp = 0;
	fdf->size_line = 0;
	fdf->endian = 0;
}

int		hook_key(int key, t_data *fdf)
{
	(void)fdf;
	if (key == ESC)
		exit(EXIT_SUCCESS);
	return (0);
}

void	allocate_map(t_point ***map, int rows, int cols)
{
	int i;

	(*map) = (t_point **)malloc(rows * sizeof(t_point *));
	if ((*map) == NULL)
		error("failed to allocate map");
	i = 0;
	while (i < rows)
	{
		(*map)[i] = (t_point *)malloc(cols * sizeof(t_point));
		if ((*map)[i] == NULL)
			error("failed to allocate map");
		i++;
	}
}