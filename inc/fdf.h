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

# define WIN_WIDTH	1000
# define WIN_HEIGHT 1000

typedef struct 	s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*arr;
}				t_mlx;

void	mlx_data_init(t_mlx *data);
void	validation(int ac, char *av[]);

#endif