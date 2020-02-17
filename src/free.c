/**
 *
 * Header
 *
 */

#include "ft_ls.h"

void    free_files(t_file **files)
{
	int     i;

	i = 0;
	while (files[i])
	{
		free(files[i]->entry);
		free(files[i]->filename);
		free(files[i]->pathname);
		free(files[i]);
		i++;
	}
	free(files);
}