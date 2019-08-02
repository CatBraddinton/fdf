#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "mlx.h"
# include "hooks.h"

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# define COLOR 		0x76FFFF
# define W_WINDOW 	1920
# define H_WINDOW 	1080
# define ISO		1

typedef struct	s_point
{
	int 		x;
	int 		y;
	int 		z;
	int 		color;
}				t_point;

typedef struct 	s_change
{
	int 		scale;
	int 		move_up;
	int 		move_left;
	int 		move_right;
	int 		move_down;
	int 		z_change;
	int 		projection;
}				t_change;

typedef struct	s_data
{
	char 		*name;
	t_point		**map;
	int 		width;
	int 		height;
	void		*mlx;
	void		*window;
	void		*image;
	char 		*ibuff;
	int 		bpp;
	int 		size_line;
	int 		endian;
	t_change	params;
}				t_data;

void	error(char *str);
void	validate_input(t_data *fdf);
void	init_data(t_data *fdf, char *name);
void	fparser(t_data *fdf);
void	init_mlx(t_data *dfd);
void	render_image(t_data *fdf);
#endif
