#include "../inc/draw_lines.h"

void	allocate_new_buff(t_data *fdf)
{
	int i;
	int j;

	i = 0;
	fdf->transformed = (t_point **)malloc(fdf->height * sizeof(t_point *));
	if (fdf->transformed == NULL)
		error("Failed to allocate memory");
	while (i < fdf->height)
	{
		j = 0;
		fdf->transformed[i] = (t_point *)malloc(fdf->width * sizeof(t_point));
		if (fdf->transformed[i] == NULL)
			error("failed to allocate element of the struct");
		while (j < fdf->width)
		{
			fdf->transformed[i][j].x = fdf->map[i][j].x * fdf->params.scale;
			fdf->transformed[i][j].y = fdf->map[i][j].y * fdf->params.scale;
			fdf->transformed[i][j].z += fdf->params.z_change;
			fdf->transformed[i][j].color = fdf->map[i][j].color;
			i++;
		}
		i++;
	}
}

void	display_image(t_data *fdf)
{
	int i;
	int j;

	i = 0;
	allocate_new_buff(fdf);
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			draw_lines(fdf->transformed[i][j], fdf->transformed[i + 1][j], fdf);
			draw_lines(fdf->transformed[i][j], fdf->transformed[i][j + 1], fdf);
			i++;
		}
		i++;
	}
}