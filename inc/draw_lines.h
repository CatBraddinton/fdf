#ifndef DRAW_LINE_H
# define DRAW_LINE_H

# include "fdf.h"

typedef struct	s_draw
{
	int 		dx;
	int 		dy;
	float 		grad;
	float 		inter_x;
	float 		inter_y;
	int 		x0;
	int 		y0;
	int 		x1;
	int 		y1;
	int 		x;
	int 		y;
	int 		color_p0;
	int 		color_p1;
}				t_draw;

void	draw_lines(t_point p0, t_point p1, t_data *fdf);
t_point transform(int x, int y, int z, t_data *fdf);
int 	get_color(int color_p0, int color_p1);
void	init_line(t_draw *line, t_point p0, t_point p1);
void	draw_straight_line(t_change *fdf, t_draw *line, t_point p0, t_point p1);
#endif
