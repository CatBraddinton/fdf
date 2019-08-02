#include "../inc/fdf.h"


int main(int ac, char *av[])
{
	t_data *fdf;

	if (ac != 2)
		error("usage: ./fdf path/to/map/file.fdf");
	if ((fdf = (t_data *)malloc(sizeof(t_data))) == NULL)
		error("malloc failed to allocate memory");
	init_data(fdf, av[1]);
	validate_input(fdf);
	fparser(fdf);
	init_mlx(fdf);
	return 0;
}