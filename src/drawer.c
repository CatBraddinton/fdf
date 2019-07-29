#include "../inc/fdf.h"

void	draw_line(t_fdf *data, t_point vec0, t_point vec1)
{
	t_line line;

	line.dx = 1;
	line.dy = 1;
	if ((vec1.x - vec0.x) >= 0)
		line.dx = -1;
	if ((vec1.y - vec0.y) >= 0)
		line.dy = -1;
	line.sx = abs(vec1.x - vec0.x);
	line.sy = abs(vec1.y - vec0.y);
	if (line.sx > line.sy)
		line.s = line.sx;
	if (line.sx < line.sy)
		line.s = line.sy;
	if (line.s == 0)
		mlx_pixel_put(data->mlx, data->win, vec1.x, vec1.y, vec1.color);
	if (line.sy <= line.sx)
	{
		line.x = vec1.x;
		line.y = vec1.y;
		line.d = -line.sx;
		line.s++;
		while (line.s--)
		{
			mlx_pixel_put(data->mlx, data->win, line.x, line.y, vec0.color);
			line.x += line.dx;
			line.d += 2 * line.sy;
			if (line.d > 0)
			{
				line.d -= 2 * line.sx;
				line.y += line.dy;
			}
		}
	}
	if (line.sy > line.sx)
	{
		line.x = vec1.x;
		line.y = vec1.y;
		line.d = -line.sx;
		line.s++;
		while (line.s--)
		{
			mlx_pixel_put(data->mlx, data->win, line.x, line.y, vec0.color);
			line.y += line.dy;
			line.d += 2 * line.sx;
			if (line.d > 0)
			{
				line.d -= 2 * line.sx;
				line.x += line.dx;
			}
		}
	}
}

