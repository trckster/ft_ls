/**
 *
 * Header
 *
 */

#include "libft.h"

char    *ft_strfill(int n, char c)
{
	char    *res;
	int     i;

	res = (char *)(malloc(sizeof(char) * (n + 1)));
	i = 0;
	while (i < n)
	{
		res[i] = c;
		i++;
	}
	res[i] = 0;
	return (res);
}