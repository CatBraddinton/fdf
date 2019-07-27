#include "libft.h"

int	count_digits(int num)
{
	int i;

	i = 0;
	while ((num / 10) != 0)
		i++;
	return (i);
}