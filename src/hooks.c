#include "../inc/fdf.h"

int		hook_key(int key, t_fdf *data)
{
	if (key == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

