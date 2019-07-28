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

static void	check_errors(int num, char *str)
{
	int s_len;
	int digits;

	s_len = ft_strlen(str);
	digits = count_digits(num);
	if (num < 0)
		digits += 1;
	if (num == 0 && str[0] == '0' && digits == s_len)
		return ;
	if (num == 0 && s_len != 1)
		error_message("incorrect map, wrong symbol");
	if (s_len != digits)
	{
		if (str[digits] == ',' && (digits + 9) == s_len)
		{
			if (str[digits + 1] == '0' && (str[digits + 2] == 'x' ||
			(str[digits + 2] == 'X')))
				return ;
		}
		error_message("incorrect map, wrong symbol");
	}
}

static void	check_str(const char *line)
{
	char	**map;
	int		num;
	int		points;
	int		i;

	points = ft_count_words(line, ' ');
	if ((map = ft_strsplit(line, ' ')) == NULL)
		error_message("malloc failed to allocate memory");
	i = 0;
	while (i < points)
	{
		ft_putstr(map[i]);
		num = ft_atoi(map[i]);
		check_errors(num, map[i]);
		free(map[i]);
		i++;
	}
	ft_putchar('\n');
	free(map[i]);
	free(map);
}

static void	validate_map(int fd)
{
	char	*line;

	while ((get_next_line(fd, &line)) == 1)
	{
		check_str(line);
		ft_strdel(&line);
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

int			validation(char *str)
{
	int fd;

	validate_path_to_file(str);
	if ((fd = open(str, O_RDONLY)) < 0)
		error_message(strerror(errno));
	validate_map(fd);
	return (1);
}
