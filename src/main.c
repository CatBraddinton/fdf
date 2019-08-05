#include "../inc/fdf.h"


int main(int ac, char *av[])
{
	t_data	*fdf;
	t_point	**map;

	if (ac != 2)
		error("usage: ./fdf path/to/map/file.fdf");
	if ((fdf = (t_data *)malloc(sizeof(t_data))) == NULL)
		error("malloc failed to allocate memory");
	init_data(fdf, av[1]);
	validate_input(fdf);
	allocate_map(&map, fdf->height, fdf->width);
	fparser(fdf, map);
	init_transformation(&(fdf->params), fdf);
	if ((fdf->mlx = mlx_init()) == NULL)
		error("mlx initialization failed");
	if ((fdf->window = mlx_new_window(fdf->mlx, W_WINDOW, H_WINDOW,
									  fdf->name)) == NULL)
		error("mlx failed to create a window");
	fdf->image = mlx_new_image(fdf->mlx, W_WINDOW, H_WINDOW);
	fdf->ibuff = mlx_get_data_addr(fdf->image, &(fdf->bpp), &(fdf->size_line),
								   &(fdf->endian));
	display_image(fdf, map);
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->image, 0, 0);
	mlx_key_hook(fdf->window, hook_key, fdf);
	mlx_loop(fdf->mlx);
	return 0;
}