/**
 *
 * Headers
 *
 */

#include "ft_ls.h"

void    set_indentations(t_file *file, t_indentations *base)
{
	t_indentations   *ind;

	ind = (t_indentations *)malloc(sizeof(t_indentations));
	ind->link_size = base->link_size;
	ind->owner_name_size = base->owner_name_size;
	ind->owner_name_size = base->owner_group_size;
	ind->file_size_size = base->file_size_size;

	file->indentations = ind;
}

void    set_link_size(t_indentations *ind, t_file **files)
{
	int i;
	int max_size;
	int curr;

	i = 0;
	max_size = 0;
	while (files[i])
	{
		curr = ft_nbrlen(files[i]->extra->links_count);
		if (curr > max_size)
			max_size = curr;
		i++;
	}
	ind->link_size = max_size;
}

void    set_owner_sizes(t_indentations *ind, t_file **files)
{
	int i;
	int max_size;
	int curr;

	i = 0;
	max_size = 0;
	while (files[i])
	{
		curr = ft_strlen(files[i]->extra->owner_name);
		if (curr > max_size)
			max_size = curr;
		i++;
	}
	ind->owner_name_size = max_size;
	i = 0;
	max_size = 0;
	while (files[i])
	{
		curr = ft_strlen(files[i]->extra->owner_group);
		if (curr > max_size)
			max_size = curr;
		i++;
	}
	ind->owner_group_size = max_size;
}

void    set_file_size_size(t_indentations *ind, t_file **files)
{
	int i;
	int max_size;
	int curr;

	i = 0;
	max_size = 0;
	while (files[i])
	{
		curr = ft_nbrlen(files[i]->extra->file_size);
		if (curr > max_size)
			max_size = curr;
		i++;
	}
	ind->link_size = max_size;
}

void    set_files_indentations(t_file **files)
{
	t_indentations  *indentations;
	int             i;

	indentations = (t_indentations *)malloc(sizeof(t_indentations));
	set_link_size(indentations, files);
	set_owner_sizes(indentations, files);
	set_file_size_size(indentations, files);
	i = 0;
	while (files[i])
		set_indentations(files[i++], indentations);
	free(indentations);
}