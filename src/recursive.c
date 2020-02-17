/**
 *
 * Header
 *
 */

#include "ft_ls.h"

void    display_t_files(t_file **files, char *flags, char type)
{
	int i;
	int displayed_count;

	i = 0;
	displayed_count = 0;
	while (files[i])
	{
		displayed_count += 1;
		if (type == 'a')
			display_t_file(files[i], flags);
		else if (type == 'd' && isdir(files[i]))
			display_t_file(files[i], flags);
		else if (type == 'f' && !isdir(files[i]))
			display_t_file(files[i], flags);
		else
			displayed_count -= 1;
		i++;
	}
	if (displayed_count && !with_meta(flags))
		ft_putchar('\n');
}

void    display_directory_recursive(t_file *file, char *flags)
{
	t_file  **files;
	int     i;

	ft_putchar('\n');
	ft_printf("%s:\n", file->pathname);
	fill_files(file->pathname, &files);
//	sort_ur_ass(); // TODO: not implemented
	display_t_files(files, flags, 'a');
	i = 0;
	while (files[i])
	{
		if (!ft_strcmp(files[i]->filename, "..") || !ft_strcmp(files[i]->filename, "."))
		{
			i++;
			continue;
		}
		if (isdir(files[i]))
			if (with_hidden(flags) || !file_is_hidden(files[i]->filename))
				display_directory_recursive(files[i], flags);
		i++;
	}
	free_files(files);
}

void    display_all_dirs_recursive(t_file **files, char *flags)
{
	int i;

	i = 0;
	while (files[i])
	{
		if (isdir(files[i]))
			display_directory_recursive(files[i], flags);
		i++;
	}
}