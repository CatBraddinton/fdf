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

# define WIDTH		1300
# define HEIGHT		950
# define COLOR 		0x91ffeb
# define ISO		1
# define PARALLEL 	2

typedef	struct 		s_point
{
	int				x;
	int				y;
	int				z;
	unsigned long	color;
}					t_point;

typedef struct 		s_map
{
	int 			cols;
	int 			rows;
	int 			min_depth;
	int 			max_depth;
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
	t_map			*map;
	t_point			first;
	t_point			last;
	int 			dx;
	int 			dy;
	int 			sx;
	int 			sy;
	int 			err1;
	int 			err2;
	int 			proj;
}					t_fdf;

void				error_message(const char *strs);
int 				validation(t_fdf *data);
void				free_all_structs(t_fdf *data);
void				get_model_data(t_fdf *data);
#endif