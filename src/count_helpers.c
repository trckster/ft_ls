/**
 *
 * Header
 *
 */

#include "ft_ls.h"

int     count_displaying_dirs_in_t_files(t_file **files)
{
	int     i;
	int     result;

	i = 0;
	result = 0;
	while (files[i])
	{
		if (isdir(files[i]))
			result++;
		i++;
	}
	return result;
}