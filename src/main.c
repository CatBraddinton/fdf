#include "../inc/fdf.h"

int main(int ac, char *av[])
{
	errno = 0;
	if (ac != 2 || av[1] == NULL)
		error_message("usage: ./fdf [path/to/map/file.fdf]");
	validation(av[1]);
	return (0);
}