/**
 *
 * Header
 *
 */

#include "libft.h"

char    *ft_ljust(char *s, int n, char c)
{
	char    *res;
	int     base_len;
	char    *first_part;
	char    *second_part;

	base_len = ft_strlen(s);
	first_part = ft_strdup(s);
	if (base_len >= n)
		return (first_part);
	second_part = ft_strfill(n - base_len, c);
	res = ft_strjoin(first_part, second_part);
	free(second_part);
	free(first_part);
	return (res);
}