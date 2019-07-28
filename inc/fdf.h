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

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
}					t_mlx;

typedef struct		s_img
{
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	char			*buf;
}					t_img;

typedef struct		s_fdf
{
	t_mlx			mlx;
	t_img			img;
	int 			cols;
	int 			rows;
	int 			proj;
}					t_fdf;

void				error_message(const char *strs);
int 				validation(char *str, t_fdf *data);
int					fdf(t_fdf *data, t_point *all, char *name);
void				free_2d_arr(char **arr, int size);

#endif