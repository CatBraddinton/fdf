#include "../inc/fdf.h"

static void	validate_map(int fd)
{
	int 	i;
	char	*line;
	char 	**map;
	int		temp;

	while ((get_next_line(fd, &line)) > 0)
	{
		map = ft_strsplit(line, ' ');
		i = 0;
		while(map[i])
		{
			temp = ft_atoi(map[i]);
			printf("map[%d] = %s, temp = %d\n", i, map[i], temp);
			if (temp == 0 && map[i][0] != '0')
				error_message("incorrect map");
			i++;
		}
		free_map_arr(map);
	}
}

static void	validate_path_to_file(char *str)
{
	int len;
	int i;

	len = ft_strlen(str);
	i = len - 4;
	if ((ft_strcmp(str + i, ".fdf")) != 0)
		error_message("incorrect file name");

}

int 		validation(char *str)
{
	int fd;

	validate_path_to_file(str);
	if ((fd = open(str, O_RDONLY)) < 0)
		error_message(strerror(errno));
	validate_map(fd);
	return (1);
}