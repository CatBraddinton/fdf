#include "../inc/fdf.h"

int main(int ac, char *av[])
{
	t_mlx data;

	mlx_data_init(&data);
	validation(ac, av);
	
	mlx_loop(data.mlx);
	return (0);
}