/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 14:50:20 by kdudko            #+#    #+#             */
/*   Updated: 2019/08/06 14:50:22 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "fdf.h"

typedef struct	s_draw
{
	double		grad;
	double		dx;
	double		dy;
	double		inter_y;
	double		inter_x;
	int			x;
	int			y;
	int			color_p0;
	int			color_p1;
	int			x0;
	int			y0;
	int			x1;
	int			y1;

}				t_draw;

void			init_line(t_draw *line, t_point p0, t_point p1);
void			draw_lines(t_point p0, t_point p1, t_data *fdf);
void			draw_straight_line(t_data *fdf, t_draw *line, t_point p0,
				t_point p1);
void			fdf_put_pixel(t_data *fdf, int x, int y, int color);

void			iso(int *x, int *y, int z);
void			x_axis(int *y, int *z, double x_angle);
void			y_axis(int *x, int *z, double y_angle);
void			z_axis(int *x, int *y, double z_angle);

#endif
