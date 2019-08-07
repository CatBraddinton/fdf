/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 14:52:44 by kdudko            #+#    #+#             */
/*   Updated: 2019/08/06 14:52:46 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "mlx.h"
# include "hooks.h"
# include "../inc/info.h"

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# define COLOR 		0x6200A3
# define W_WINDOW 	2600
# define H_WINDOW 	1400
# define ISO		1
# define PARALLEL	2

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_point;

typedef struct	s_change
{
	int			scale;
	int			z_change;
	int			projection;
	int			center_x;
	int			center_y;
	double		x_angle;
	double		y_angle;
	double		z_angle;
}				t_change;

typedef struct	s_data
{
	char		*name;
	int			width;
	int			height;
	void		*mlx;
	void		*window;
	void		*image;
	char		*ibuff;
	int			bpp;
	int			size_line;
	int			endian;
	t_point		**map;
	t_change	params;
}				t_data;

void			error(char *str);
void			validate_input(t_data *fdf);
void			fparser(t_data *fdf, t_point **map);

void			init_data(t_data *fdf, char *name);
void			init_transformation(t_change *params, t_data *fdf);

int				key_press(int keycode, t_data *fdf);
void			display_image(t_data *fdf, t_point **map);
void			allocate_map(t_point ***map, int rows, int cols);
void			draw_info_menu(t_data *fdf);
#endif
