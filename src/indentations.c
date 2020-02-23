/**
 *
 * Headers
 *
 */

#include "ft_ls.h"
typedef struct  s_indentations
{
	int link_size;
	int owner_name_size;
	int owner_group_size;
	int file_size_size;
}               t_indentations;

void    set_indentations(t_file *file, t_indentations *base)
{
	t_indentations   *ind;

	ind = (t_indentation *)malloc(sizeof(t_indentation));
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
		curr = files[i]->//NEXTODO
		i++;
	}
}

void    set_files_indentations(t_file **files)
{
	t_indentations  *indentations;

	indentations = (t_indentations *)malloc(sizeof(t_indentations));
	set_link_size(indentations, files);
	set_owner_sizes(indentations, files);
	set_file_size_size(indentations, files);
	i = 0;
	while (files[i])
		set_indentations(files[i++], indentations);
	free(indentations);
}