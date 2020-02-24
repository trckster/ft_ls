/**
 *
 * Header
 *
 */

#include "libft.h"

char    *ft_rjust(char *s, int n, char c)
{
	char    *res;
	int     base_len;
	char    *first_part;
	char    *second_part;

	base_len = ft_strlen(s);
	second_part = ft_strdup(s);
	if (base_len >= n)
		return (second_part);
	first_part = ft_strfill(n - base_len, c);
	res = ft_strjoin(first_part, second_part);
	free(first_part);
	free(second_part);
	return (res);
}