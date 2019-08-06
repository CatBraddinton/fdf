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

static void	check_color(char *s, int i)
{
	int j;

	j = 0;
	if (s[i] != '\0' && s[i++] != '0')
		error("invalid map, wrong color");
	if (s[i] != '\0' && s[i] != 'x' && s[i] != 'X')
		error("invalid map");
	i++;
	while (s[i] != '\0' && j < 6)
	{
		if (s[i] >= '0' && s[i] <= '9')
			i++;
		else if (s[i] >= 'A' && s[i] <= 'F')
			i++;
		else if (s[i] >= 'a' && s[i] <= 'f')
			i++;
		else
			error("map is invalid");
		j++;
	}
}

static void	check_errors(char *s)
{
	int i;

	i = 0;
	while (s[i] != 0)
	{
		if (ft_isdigit(s[i]))
			i++;
		else if (s[i] == '-')
			i++;
		else if (s[i] == ' ' || s[i] == '\t')
		{
			if (ft_isdigit(s[i + 1]) ||
			s[i + 1] == '-' || (i > 0 && ft_isdigit(s[i - 1])))
				i++;
		}
		else if (s[i] == ',')
		{
			check_color(s, ++i);
			i += 8;
		}
		else
			error("wromg map");
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
		check_errors(line);
		ft_strdel(&line);
		fdf->height++;
	}
	if (fdf->width == 0 && fdf->height == 0)
		error("error, map is empty");
	close(fd);
}
