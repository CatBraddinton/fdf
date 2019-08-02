#include "../inc/draw_lines.h"

void	render_image(t_data *fdf)
{
	int x;
	int y;

	x = 0;
	y = -1;
	if (fdf->image != NULL)
		mlx_destroy_image(fdf->mlx, fdf->image);
	fdf->image = mlx_new_image(fdf->mlx, W_WINDOW, H_WINDOW);
	fdf->ibuff = mlx_get_data_addr(fdf->image, &(fdf->bpp), &(fdf->size_line),
								  &(fdf->endian));
	if (fdf->ibuff == NULL)
		error("failed to get image buffer");
	t_point p1;
	t_point p2;
	p1.x = 10;
	p1.y = 10;
	p1.z = 0;
	p1.color = COLOR;
	p2.x = 200;
	p2.y = 100;
	p2.z = 0;
	p2.color = COLOR;
	draw_lines(p1, p2, fdf);
	while (++y < fdf->height - 1)
		while (x < fdf->width - 1)
		{
//			draw_lines(transform(fdf->map[y][x].x, fdf->map[y][x].y,
//				fdf->map[y][x].z, fdf), transform(fdf->map[y][x + 1].x,
//						fdf->map[y][x].y, fdf->map[y][x].z, fdf), fdf);
//			draw_lines(transform(fdf->map[y][x].x, fdf->map[y][x].y,
//				fdf->map[y][x].z, fdf), transform(fdf->map[y][x + 1].x,
//					fdf->map[y][x].y, fdf->map[y][x].z, fdf), fdf);
			x++;
		}
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->image, 0, 0);
}