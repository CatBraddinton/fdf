#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

typedef	struct 	s_point
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_point;

typedef struct	s_triangle
{
	t_point		points[3];

}				t_triangle;

typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
	void		*img;
	int			bits_per_pixel;
	int			size_line;
	int 		cols;
	int 		rows;
	int			endian;
}				t_fdf;

void	error_message(const char *strs);
int 	validation(char *str, t_fdf *data);

#endif