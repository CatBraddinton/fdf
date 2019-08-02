#include "../inc/fdf.h"

void	init_new_object(t_point **new, t_map *map)
{
	int i;

	i = 0;
	if ((new = ft_memalloc(map->rows *sizeof(t_point *))) == NULL)
		error_message("failed to allocate new object");
	while (i < map->rows)
	{
		if ((new[i] = ft_memalloc(map->cols * sizeof(t_point))) == NULL)
			error_message("failed to allocate new object");
		new[i]->x = 20 * map->points[i]->x;
		new[i]->y = 20 * map->points[i]->y;
		new[i]->z = 20 * map->points[i]->z;
		new[i]->color = map->points[i]-> color;
		i++;
	}
}

//void	transform(t_map *map, t_fdf *data, t_point **new)
//{
//
//}

