/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 05:27:16 by kdudko            #+#    #+#             */
/*   Updated: 2019/07/28 05:27:18 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	main(int ac, char *av[])
{
	t_fdf	data;

	errno = 0;
	if (ac != 2 || av[1] == NULL)
		error_message("usage: ./fdf [path/to/map/file.fdf]");
	validation(av[1], &data);
	system("leaks fdf");
	return (0);
}
