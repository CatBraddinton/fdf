/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 14:41:09 by kdudko            #+#    #+#             */
/*   Updated: 2019/08/06 14:41:11 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	parse_user_colors(t_data *fdf, char *val1, char *val2)
{
	int temp1;
	int temp2;

	if (val1[0] == '0' && (val1[1] == 'x' || val1[1] == 'X'))
		temp1 = ft_atoi_base(val1, 16);
	else
		temp1 = ft_atoi(val1);
	if (val2[0] == '0' && (val2[1] == 'x' || val2[1] == 'X'))
		temp2 = ft_atoi_base(val2, 16);
	else
		temp2 = ft_atoi(val2);
	if ((temp1 > 0 && temp1 <= 0xFFFFFF) && (temp2 > 0 && temp2 <= 0xFFFFFF))
	{
		fdf->user_colors = 1;
		fdf->params.s_color = temp1;
		fdf->params.f_color = temp2;
	}
	else
		error("color are invalid");
}

static void	check_errors(char *s, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (!(s[i] >= '0' && s[i] <= '9') && !(s[i] >= 'A' && s[i] <= 'F')
		&& !(s[i] >= 'a' && s[i] <= 'f') && s[i] != 'x' && s[i] != 'X'
		&& s[i] != ',' && s[i] != ' ' && s[i] != '-')
			error("invalid char on map");
		i++;
	}
}

static void	validate_path_to_file(char *str)
{
	int len;
	int i;

	len = ft_strlen(str);
	i = len - 4;
	if ((ft_strcmp(str + i, ".fdf")) != 0)
		error("incorrect file name");
}

void		validate_input(t_data *fdf, char **av, int ac)
{
	int		fd;
	char	*line;
	int		temp;

	validate_path_to_file(fdf->name);
	if (ac == 4)
		parse_user_colors(fdf, av[2], av[3]);
	if ((fd = open(fdf->name, O_RDONLY)) < 0)
		error("failed to open the file");
	line = NULL;
	while ((get_next_line(fd, &line)) == 1)
	{
		temp = ft_count_words(line, ' ');
		if (fdf->width == 0)
			fdf->width = temp;
		if (temp != fdf->width)
			error("invalid map");
		check_errors(line, temp);
		ft_strdel(&line);
		fdf->height++;
	}
	if (fdf->width == 0 && fdf->height == 0)
		error("error, map is empty");
	if (fdf->width == 1 && fdf->height == 1)
		error("map has 1 point, give me bigger map");
	close(fd);
}
