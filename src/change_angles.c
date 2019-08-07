/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:14:00 by kdudko            #+#    #+#             */
/*   Updated: 2019/08/06 15:14:02 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/render.h"

void	x_axis(int *y, int *z, double x_angle)
{
	int prev_y;
	int prev_z;

	prev_y = *y;
	prev_z = *z;
	*y = prev_y * cos(x_angle) - prev_z * sin(x_angle);
	*z = prev_y * sin(x_angle) + prev_z * cos(x_angle);
}

void	y_axis(int *x, int *z, double y_angle)
{
	int prev_x;
	int prev_z;

	prev_x = *x;
	prev_z = *z;
	*x = prev_x * cos(y_angle) + prev_z * sin(y_angle);
	*z = -prev_x * sin(y_angle) + prev_z * cos(y_angle);
}

void	z_axis(int *x, int *y, double z_angle)
{
	int prev_x;
	int prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(z_angle) - prev_y * sin(z_angle);
	*y = prev_x * sin(z_angle) + prev_y * cos(z_angle);
}

void	iso(int *x, int *y, int z)
{
	int prev_x;
	int prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.523599);
	*y = -z + (prev_x + prev_y) * sin(0.523599);
}
