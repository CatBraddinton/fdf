/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 22:32:11 by kdudko            #+#    #+#             */
/*   Updated: 2019/08/06 22:32:13 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_int(const char *s, int base)
{
	int				power;
	unsigned long	res;
	int				i;

	i = strlen(s) - 1;
	power = 1;
	res = 0;
	while ((base == 16 && s[i] != 'x' && s[i] != 'X') || i >= 0)
	{
		if (s[i] >= '0' && s[i] <= '9')
			res = res + ((s[i] - 48) * power);
		else if (s[i] >= 'A' && s[i] <= 'F')
			res = res + ((s[i] - 55) * power);
		else if (s[i] >= 'a' && s[i] <= 'f')
			res = res + ((s[i] - 87) * power);
		i--;
		power *= base;
	}
	return (res);
}

static int	check_for_short(const char *s, int base)
{
	char	mnew[9];
	int 	len;

	len = strlen(s);
	if (len == 5 && s[0] == '0' && ((s[1] == 'x') || (s[1] == 'X')))
	{
		mnew[0] = '0';
		mnew[1] = 'x';
		mnew[2] = s[2];
		mnew[3] = mnew[2];
		mnew[4] = s[3];
		mnew[5] = mnew[4];
		mnew[6] = s[4];
		mnew[7] = mnew[6];
		mnew[8] = '\0';
	}
	else
		return (count_int(s, base));
	return (count_int(mnew, base));
}

int			ft_atoi_base(const char *s, int base)
{
	int res;

	res = 0;
	while (*s && ((*s == '\t') || (*s == '\n') || (*s == '\f') \
		|| (*s == '\r') || (*s == '\v') || (*s == ' ')))
		s++;
	if (base == 16)
		return (check_for_short(s, base));
	return (count_int(s, base));
}