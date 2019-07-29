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

# define WIDTH		1500
# define HEIGHT		1000
# define COLOR 		0x91FFEB
# define ISO		1
# define PARALLEL 	2

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

typedef struct		s_img
{
	void			*img;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	char			*buf;
	float			**z_buf;
}					t_img;

typedef struct		s_fdf
{
	char			*prog_name;
	void			*mlx;
	void			*win;
	t_img			*img;
	int				proj;
}					t_fdf;

typedef struct 		s_line
{
	t_point			first;
	t_point			last;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				err1;
	int				err2;
}					t_line;

int					validation(char *prog_name, t_map *map);
void				parse_map(t_map *map, char *prog_name);
void				error_message(const char *strs);
void				free_all_structs(t_fdf *data, t_map *map);

#endif
