/**
 *
 * Headers
 *
 */

#include "ft_ls.h"

void    sort_files_by_modification(t_file ***given_files)
{
	t_file **files;

	files = *given_files;
	// do sort
	*given_files = files;
}

void    sort_files_alphabetically(t_file ***given_files)
{
	t_file  **files;
	int     i;
	int     j;

	files = *given_files;
	i = 0;
	while (files[i])
	{
		j = i;
		while (files[j])
		{
			if (ft_strcmp(files[i]->filename, files[j]->filename) > 0)
				swap_files(files + i, files + j);
			j++;
		}
		i++;
	}
	*given_files = files;
}

void    sort_files(t_file ***given_files, char *flags)
{
	if (!**given_files)
		return ;
	if (sort_by_modification(flags))
		sort_files_by_modification(given_files);
	else
		sort_files_alphabetically(given_files);
	if (reverse_sort(flags))
		reverse_files(given_files);
}