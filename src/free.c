/**
 *
 * Header
 *
 */

#include "ft_ls.h"

void    free_file(t_file *file)
{
	free_file_extra_data(file->extra);
	free(file->entry);
	free(file->filename);
	free(file->pathname);
	free(file->indentations);
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
	free(data->privileges);
	free(data->owner_name);
	free(data->owner_group);
	free(data->last_modification);
	free(data);
}

void    free_file_without_extra(t_file *file)
{
	free(file->entry);
	free(file->filename);
	free(file->pathname);
	free(file->indentations);
	free(file);
}

void    free_arguments(t_arguments *a)
{
	int i;

	i = 0;
	free(a->flags);
	while (a->input_files[i])
		free(a->input_files[i++]);
	free(a->input_files);
	free(a);
}