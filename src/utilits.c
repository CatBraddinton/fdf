#include "../inc/fdf.h"

void			error(char *str)
{
	ft_putendl(str);
	exit(EXIT_FAILURE);
}



void		init_transformation(t_change *params, t_data *fdf)
{
	int temp;
	int temp2;

	temp = W_WINDOW / fdf->width / 2;
	temp2 = H_WINDOW / fdf->height /2;
	params->scale = (temp < temp2)? temp : temp2;
	params->move_up = 0;
	params->move_left = 0;
	params->move_right = 0;
	params->move_down = 0;
	params->z_change = 10;
	params->projection = ISO;
	params->center_x = W_WINDOW / 2;
	params->center_y = H_WINDOW / 2;
	params->x_angle = 0.0;
	params->y_angle = 0.0;
	params->z_angle = 0.0;
}

void			init_data(t_data *fdf, char *name)
{
	fdf->name = ft_strdup(name);
	fdf->mlx = NULL;
	fdf->window = NULL;
	fdf->image = NULL;
	fdf->height = 0;
	fdf->width = 0;
	fdf->bpp = 0;
	fdf->size_line = 0;
	fdf->endian = 0;
}

int		hook_key(int key, t_data *fdf)
{
	if (key == ESC)
		exit(EXIT_SUCCESS);
	if (key == SPACE)
		display_image(fdf, fdf->map);
	if (fdf->image && (key == Z_UP || key == Z_DOWN))
	{
		mlx_destroy_image(fdf->mlx, fdf->image);
		if (key == Z_UP)
			fdf->params.z_change += 1;
		if (key == Z_DOWN)
			fdf->params.z_change -= 1;
		display_image(fdf, fdf->map);
	}
	if (fdf->image && (key == ZOOM_M || key == ZOOM_P))
	{
		mlx_destroy_image(fdf->mlx, fdf->image);
		if (key == ZOOM_M)
			fdf->params.scale++;
		if (key == ZOOM_M)
			fdf->params.scale--;
		display_image(fdf, fdf->map);
	}
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