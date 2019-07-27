#include "libft.h"

void free_map_arr(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	map = NULL;
}

