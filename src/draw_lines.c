#include "../inc/draw_lines.h"

static void	init_line(t_draw *line, t_point p0, t_point p1)
{
	line->grad = 0.0;
	line->dx = 0.0;
	line->dy = 0.0;
	line->inter_x = 0.0;
	line->inter_y = 0.0;
	line->x = p0.x;
	line->y = p0.y;
	line->color_p0 = p0.color;
	line->color_p1 = p1.color;
	line->x0 = p0.x;
	line->y0 = p0.y;
	line->x1 = p1.x;
	line->y1 = p1.y;
}

void		fdf_put_pixel(t_data *fdf, int x, int y, int color)
{
	int i;

	if (x < W_WINDOW && y < H_WINDOW && x >= 0 && y >= 0)
	{
		i = (x * fdf->bpp / 8) + (y * fdf->size_line);
		fdf->ibuff[i] = color ;
		fdf->ibuff[++i] = color >> 8;
		fdf->ibuff[++i] = color >> 16;
		fdf->ibuff[++i] = 0;
	}
}

static void	draw_line_y(t_draw *line, t_data *fdf)
{
	fdf_put_pixel(fdf, line->x0, line->y0, line->color_p0);
	line->y = line->y0 + 1;
	while (line->y < line->y1)
	{
		fdf_put_pixel(fdf, ft_int_part(line->inter_x), line->y, line->color_p0);
		fdf_put_pixel(fdf, ft_int_part(line->inter_x) + 1, line->y,	line->color_p0);
		line->inter_x += line->grad;
		line->y++;
	}
	fdf_put_pixel(fdf, line->x1, line->y1, line->color_p1);
}

static void	draw_line_x(t_draw *line, t_data *fdf)
{
	line->inter_y = line->y0 + line->grad;
	fdf_put_pixel(fdf, line->x0, line->y0, line->color_p0);
	line->x = line->x0 + 1;
	while (line->x < line->x1)
	{
		fdf_put_pixel(fdf, line->x, ft_int_part(line->inter_y),	line->color_p0);
		fdf_put_pixel(fdf, line->x, ft_int_part(line->inter_y) + 1,
				line->color_p0);
		line->inter_y += line->grad;
		line->x++;
	}
	fdf_put_pixel(fdf, line->x1, line->y1, line->color_p1);
}

void		draw_lines(t_point p0, t_point p1, t_data *fdf)
{
	t_draw line;

	init_line(&line, p0, p1);
	line.dx = abs(line.x0 - line.x1);
	line.dy = abs(line.y0 - line.y1);
	if ((line.dy == 0) || (line.dx == 0))
		draw_straight_line(fdf, &line, p0, p1);
	else if (line.dy < line.dx)
	{
		if (line.x1 < line.x0)
		{
			ft_swap(&(line.x0), &(line.x1));
			ft_swap(&(line.y0), &(line.y1));
		}
		line.grad = (double)line.dy / line.dx;
		if (line.y1 < line.y0)
			line.grad *= -1;
		draw_line_x(&line, fdf);
	}
	else
	{
		if (line.y1 < line.y0)
		{
			ft_swap(&(line.x0), &(line.x1));
			ft_swap(&(line.y0), &(line.y1));
		}
		line.grad = (double)line.dx / line.dy;
		line.inter_x = line.x0 + line.grad;
		if (line.x1 < line.x0)
			line.grad *= -1;
		draw_line_y(&line, fdf);
	}
}
