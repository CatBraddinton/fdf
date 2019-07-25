#include "../inc/fdf.h"

void	mlx_data_init(t_mlx *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
}