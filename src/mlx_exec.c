#include "../inc/fdf.h"

void	mlx_exec(t_fdf *data, t_img *img, t_map *map)
{
	(void)img;
	data->camera.projection = ISO;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, data->prog_name);
//	img->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
//	img->buf = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
//								 &(img->size_line), &(img->endian));
//	mlx_put_image_to_window(data->mlx, data->win, img->img, 0, 0);
	render_map(data, map);
	mlx_key_hook(data->win, hook_key, data);
	mlx_loop(data->mlx);
}

