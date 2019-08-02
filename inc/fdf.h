/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 13:32:57 by kdudko            #+#    #+#             */
/*   Updated: 2019/07/29 13:33:00 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# include "../libft/libft.h"
# include "mlx.h"

# define KEY_ESC 53

# define WIDTH		1500
# define HEIGHT		1000
# define COLOR 		0x91FFEB
# define ISO		1
# define PARALLEL 	2

typedef struct		s_camera
{
	int				projection;
	int 			x;
	int				y;
	int				z;
}					t_camera;

typedef	struct		s_point
{
	int				x;
	int				y;
	int				z;
	unsigned long	color;
}					t_point;

typedef struct		s_map
{
	int				cols;
	int				rows;
	int				min_depth;
	int				max_depth;
	t_point			**points;
}					t_map;
typedef struct		s_param
{
	int 			scale;
	int 			rotate_x;
	int 			rotate_y;
	int 			rotate_z;
	int 			move_x;
	int 			move_y;
	int 			move_z;
}					t_param;

typedef struct		s_fdf
{
	char			*prog_name;
	void			*mlx;
	void			*win;
	t_camera		camera;
	float			**z_buf;
	t_param			transf;

}					t_fdf;

typedef struct 		s_line
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int 			s;
	int				d;
	int 			x;
	int 			y;
}					t_line;

int					validation(char *prog_name, t_map *map);
void				parse_map(t_map *map, char *prog_name);
void				error_message(const char *strs);
void				free_all_structs(t_fdf *data, t_map *map);
void				line(t_fdf *data, t_point p1, t_point p2);
void				mlx_exec(t_fdf *data, t_map *map);
void				draw_line(t_fdf *data, t_point vec0, t_point vec1);
int					hook_key(int key, t_fdf *data);
void				render_map(t_point **points, t_fdf *data, int rows,
					int cols);
void				count_projection(t_point points, t_fdf data);
void				init_transformation_params(t_param *transf);
void				transform(t_map *map, t_fdf *data, t_point **new);
void				init_new_object(t_point **new, t_map *map);

#endif
