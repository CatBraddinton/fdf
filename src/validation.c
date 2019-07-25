#include "../inc/fdf.h"

void		error_message(char const *str)
{
	ft_putendl(str);
	exit(EXIT_FAILURE);
}

static void	check_for_correct_filepath(char const *path_to_file)
{
	int s_len;
	int i;

	s_len = ft_strlen(path_to_file);
	i = s_len - 4;
	if ((ft_strcmp((path_to_file + i), ".fdf")) != 0)
		error_message("usage: ./fdf [path/to/map/file.fdf]");
}

void		validation(int ac, char *av[])
{
	int fd;

	errno = 0;
	if (ac != 2)
		error_message("usage: ./fdf [path/to/map/file.fdf]");
	check_for_correct_filepath(av[1]);
	if ((fd = open(av[1], O_RDONLY)) <= 0)
		error_message(strerror(errno));

}