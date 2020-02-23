/**
 *
 * Header
 *
 */

#include "libft.h"

int     ft_nbrlen(int n)
{
	int i;

	i = 1;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}