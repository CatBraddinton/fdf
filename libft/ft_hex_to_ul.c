/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_to_ul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 13:09:36 by kdudko            #+#    #+#             */
/*   Updated: 2019/07/28 13:09:46 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_hex_to_ul(char *s)
{
	int				base;
	unsigned long	res;
	int				i;

	i = ft_strlen(s) - 1;
	base = 1;
	res = 0;
	while (s[i] != 'x' && s[i] != 'X')
	{
		if (s[i] >= '0' && s[i] <= '9')
			res = res + ((s[i] - 48) * base);
		else if (s[i] >= 'A' && s[i] <= 'F')
			res = res + ((s[i] - 55) * base);
		else if (s[i] >= 'a' && s[i] <= 'f')
			res = res + ((s[i] - 87) * base);
		i--;
		base *= 16;
	}
	return (res);
}
