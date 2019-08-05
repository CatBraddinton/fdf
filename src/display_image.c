#include "../inc/draw_lines.h"

static void iso(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
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
			(*new_map)[y][x].x = map[y][x].x * params.scale;
			(*new_map)[y][x].y = map[y][x].y * params.scale;
			(*new_map)[y][x].z =  map[y][x].z;
			(*new_map)[y][x].color = map[y][x].color;
			if (params.projection == ISO)
				iso(&((*new_map)[y][x].x), &((*new_map)[y][x].y),
						(*new_map)[y][x].z);
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
	while (y < fdf->height - 1)
	{
		x = 0;
		while (x < fdf->width - 1)
		{
			if (x + 1 < fdf->width - 1)
				draw_lines(new_map[y][x], new_map[y][x + 1], fdf);
			if (y + 1 < fdf->height - 1)
				draw_lines(new_map[y][x], new_map[y + 1][x], fdf);

			x++;
		}
		y++;
	}
}