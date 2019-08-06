#include "../inc/draw_lines.h"

void		transform_x_axis(int *y, int *z, double alpha)
{
	int prev_y;

	prev_y = *y;
	*y = prev_y * cos(alpha) + *z * sin(alpha);
	*z = -prev_y * sin(alpha) + *z * cos(alpha);
}

void		transform_y_axis(int *x, int *z, double beta)
{
	int prev;

	prev = *x;
	*x = prev * cos(beta) + *z * sin(beta);
	*z = -prev * sin(beta) + *z * cos(beta);
}

void		transform_z_axis(int *x, int *y, double gamma)
{
	int prev_x;
	int prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(gamma) - prev_y * sin(gamma);
	*y = prev_x * sin(gamma) + prev_y * cos(gamma);
}

void	iso(int *x, int *y, int z)
{
	int prev_x;
	int prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.523599);
	*y = -z + (prev_x + prev_y) * sin(0.523599);
}

void	change(t_point ***new_map, t_point **map, t_change params, t_data *fdf)
{
	int y;
	int x;

	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{

			(*new_map)[y][x].x = map[y][x].x * params.scale -
					(fdf->width * params.scale) / 2;
			(*new_map)[y][x].y = map[y][x].y * params.scale -
								 (fdf->height * params.scale) / 2;
			(*new_map)[y][x].z = map[y][x].z * params.scale * params.z_change
					/ 100;
			if (map[y][x].z != 0)
				(*new_map)[y][x].color = 0xEBCFFF;
			else
				(*new_map)[y][x].color = map[y][x].color;
//			transform_x_axis(&((*new_map)[y][x].y), &((*new_map)[y][x].z),
//					params.x_angle);
//			transform_y_axis(&((*new_map)[y][x].x), &((*new_map)[y][x].z),
//					params.y_angle);
//			transform_z_axis(&((*new_map)[y][x].x), &((*new_map)[y][x].y),
//					params.z_angle);
			if (params.projection == ISO)
				iso(&((*new_map)[y][x].x), &((*new_map)[y][x].y),
					(*new_map)[y][x].z);
			(*new_map)[y][x].x += params.center_x;
			(*new_map)[y][x].y += params.center_y;
			x++;
		}
		y++;
	}
}

void		display_image(t_data *fdf, t_point **map)
{
	int		y;
	int		x;
	t_point	**new_map;

	y = 0;
	allocate_map(&new_map, fdf->height, fdf->width);
	change(&new_map, map, fdf->params, fdf);
	fdf->image = mlx_new_image(fdf->mlx, W_WINDOW, H_WINDOW);
	fdf->ibuff = mlx_get_data_addr(fdf->image, &(fdf->bpp),
								   &(fdf->size_line), &(fdf->endian));
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			if (x + 1 <= fdf->width - 1)
				draw_lines(new_map[y][x], new_map[y][x + 1], fdf);
			if (y + 1 <= fdf->height - 1)
				draw_lines(new_map[y][x], new_map[y + 1][x], fdf);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->image, 0, 0);
}