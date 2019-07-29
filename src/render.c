#include "../inc/fdf.h"

void	render_map(t_fdf *data, t_map *map)
{
	int x;
	int y;

	y = 0;

	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			if (x < map->cols - 1)
				draw_line(data, map->points[y][x], map->points[y][x + 1]);
			if (y < map->rows - 1)
				draw_line(data, map->points[y][x], map->points[y + 1][x]);
			x++;
		}
		y++;
	}
}
