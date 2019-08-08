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

void		validate_input(t_data *fdf)
{
	int		fd;
	char	*line;
	int		temp;

	validate_path_to_file(fdf->name);
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
