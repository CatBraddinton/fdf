#include "../inc/fdf.h"

void	swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	draw_line(int x0, int y0, int x1, int y1, void *mlx_ptr, void *win_ptr)
{
	int steep;
	int dx;
	int dy;
	int derror;
	int error;
	int y;
	steep = 0;
	if (abs(x0-x1) < abs(y0-y1)) {
		swap(&x0, &y0);
		swap(&x1, &y1);
		steep = 1;
	}
	if (x0>x1) {
		swap(&x0, &x1);
		swap(&y0, &y1);
	}
	dx = x1-x0;
	dy = y1-y0;
	derror = abs(dy) * 2;
	error = 0;
	y = y0;
	for (int x=x0; x<=x1; x++) {
		if (steep) {
			mlx_pixel_put(mlx_ptr, win_ptr, y, x, COLOR);
		} else {
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, COLOR);
		}
		error += derror;
		if (error>dx) {
			y += (y1>y0?1:-1);
			error -= dx * 2;
		}
	}
}
