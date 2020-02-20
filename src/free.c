/**
 *
 * Header
 *
 */

#include "ft_ls.h"

void    free_file(t_file *file)
{
	free(file->entry);
	free(file->filename);
	free(file->pathname);
	free(file);
}

void    free_files(t_file **files)
{
	int i;

	i = 0;
	while (files[i])
		free_file(files[i++]);
	free(files);
}

void    free_file_extra_data(t_file_extra_data *data)
{
	/** TODO end it */
	free(data);
}