#include "../inc/fdf.h"
//
//static void count_projection(int *x, int *y, int z)
//{
//	int previous_x;
//	int previous_y;
//
//	previous_x = *x;
//	previous_y = *y;
//	*x = (previous_x - previous_y) * cos(0.523599);
//	*y = -z + (previous_x + previous_y) * sin(0.523599);
//}
//
//static void	move_it(int *x, int *y, t_data *fdf)
//{
//	if (fdf->params.move_right != 0)
//	{
//		*x += fdf->params.move_right;
//		*y += fdf->params.move_right;
//	}
//	if (fdf->params.move_left != 0)
//	{
//		*x += fdf->params.move_left;
//		*y += fdf->params.move_left;
//	}
//	if (fdf->params.move_up != 0)
//	{
//		*x += fdf->params.move_up;
//		*y += fdf->params.move_up;
//	}
//	if (fdf->params.move_down != 0)
//	{
//		*x += fdf->params.move_down;
//		*y += fdf->params.move_down;
//	}
//}
//

//t_point transform(t_point p, t_data *fdf)
//{
//	t_point new;
//
//	new.color = fdf->map[p.x][p.y].color;
//
//	if (fdf->params.scale != 0)
//	{
//		new.x = p.x * fdf->params.scale;
//		new.y = p.y * fdf->params.scale;
//		new.z = p.z * fdf->params.scale;
//	}
//	move_it(&x, &y, fdf);
//	if (fdf->params.projection == ISO)
//		count_projection(&x, &y, z);
//	return (new);
//}