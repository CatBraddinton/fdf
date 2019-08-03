#include "../inc/fdf.h"

void			error(char *str)
{
	ft_putendl(str);
	exit(EXIT_FAILURE);
}



static void		init_transformation(t_change *params, t_data *fdf)
{
	(void)fdf;
	params->scale = 10;
	params->move_up = 0;
	params->move_left = 0;
	params->move_right = W_WINDOW / 2 - fdf->width;
	params->move_down = H_WINDOW / 2 - fdf->height;
	params->z_change = 10;
	params->projection = ISO;
}

void			init_data(t_data *fdf, char *name)
{
	fdf->name = ft_strdup(name);
	fdf->height = 0;
	fdf->width = 0;
	fdf->mlx = NULL;
	fdf->window = NULL;
	fdf->image = NULL;
	fdf->bpp = 0;
	fdf->size_line = 0;
	fdf->endian = 0;
	init_transformation(&(fdf->params), fdf);
}

static int		hook_key(int key, t_data *fdf)
{
	if (key == ESC)
		exit(EXIT_SUCCESS);
	if (key == SPACE)
		render_image(fdf);
	return (0);
}

void			init_mlx(t_data *fdf)
{

	if ((fdf->mlx = mlx_init()) == NULL)
		error("mlx initialization failed");
	if ((fdf->window = mlx_new_window(fdf->mlx, W_WINDOW, H_WINDOW,
			fdf->name)) == NULL)
		error("mlx failed to create a window");
	mlx_key_hook(fdf->window, hook_key, fdf);
	mlx_loop(fdf->mlx);
}
