/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 05:27:27 by kdudko            #+#    #+#             */
/*   Updated: 2019/07/28 05:27:29 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	check_color(char *s, int i)
{
	int j;

	j = 0;
	if (s[i] != '\0' && s[i++] != '0')
		error_message("invalid map");
	if (s[i] != '\0' && s[i] != 'x' &&  s[i] != 'X')
		error_message("invalid map");
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
			error_message("map is invalid");
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
		else if (s[i] == ' ')
		{
			if (ft_isdigit(s[i + 1]) || s[i + 1] == '-' || (i > 0 &&
			ft_isdigit(s[i - 1])))
				i++;
		}
		else if (s[i] == ',')
		{
			check_color(s, ++i);
			i += 8;
		}
	}
}

static void	validate_map(int fd, t_fdf *data)
{
	char	*line;
	int		temp;

	line = NULL;
	while ((get_next_line(fd, &line)) == 1)
	{
		temp = ft_count_words(line, ' ');
		if (data->cols == 0)
			data->cols = temp;
		if (temp != data->cols)
			error_message("invalid map");
		check_errors(line);
		ft_strdel(&line);
		data->rows++;
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

int			validation(char *str, t_fdf *data)
{
	int fd;

	validate_path_to_file(str);
	if ((fd = open(str, O_RDONLY)) < 0)
		error_message(strerror(errno));
	data->cols = 0;
	data->rows = 0;
	validate_map(fd, data);
	close(fd);
	return (1);
}
