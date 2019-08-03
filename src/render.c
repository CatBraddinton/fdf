#include "../inc/draw_lines.h"

void	render_image(t_data *fdf)
{

	if (fdf->image != NULL)
		mlx_destroy_image(fdf->mlx, fdf->image);
	fdf->image = mlx_new_image(fdf->mlx, W_WINDOW, H_WINDOW);
	fdf->ibuff = mlx_get_data_addr(fdf->image, &(fdf->bpp), &(fdf->size_line),
								  &(fdf->endian));
	display_image(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->image, 0, 0);
}