/**
 *
 * Header
 *
 */

#include "ft_ls.h"

int     files_count(t_file **files)
{
	int     i;

	i = 0;
	while (files[i])
		i++;
	return i;
}