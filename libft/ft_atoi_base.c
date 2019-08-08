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

int	ft_atoi_base(const char *s, int base)
{
	int				power;
	unsigned long	res;
	int				i;

	i = strlen(s) - 1;
	power = 1;
	res = 0;
	while (s[i] != 'x' && s[i] != 'X' && i >= 0)
	{
		if (s[i] >= '0' && s[i] <= '9')
			res = res + ((s[i] - 48) * power);
		else if (s[i] >= 'A' && s[i] <= 'F')
			res = res + ((s[i] - 55) * power);
		else if (s[i] >= 'a' && s[i] <= 'f')
			res = res + ((s[i] - 87) * power);
		else
			return (0);
		i--;
		power *= base;
	}
	return (res);
}