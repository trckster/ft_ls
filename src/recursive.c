/**
 *
 * Header
 *
 */

#include "ft_ls.h"

int     need_total_display(t_file **files, char type)
{
	int i;
	int displayed_count;

	i = 0;
	displayed_count = 0;
	while (files[i])
	{
		displayed_count += 1;
		if (type == 'a')
			;
		else if (type == 'd' && isdir(files[i]))
			;
		else if (type == 'f' && !isdir(files[i]))
			;
		else
			displayed_count -= 1;
		i++;
	}
	return (displayed_count);
}

int     display_t_files(t_file **files, char *flags, char type)
{
	int i;
	int displayed_count;

	i = 0;
	displayed_count = 0;
	if (with_meta(flags) && need_total_display(files, type))
		display_total(files, flags);
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
	return (displayed_count);
}

void    display_directory_recursive(t_file *file, char *flags, int break_space)
{
	t_file  **files;
	int     i;

	if (break_space)
		ft_putchar('\n');
	ft_printf("%s:\n", file->pathname);
	fill_files(file->pathname, &files);
	sort_files(&files, flags);
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
				display_directory_recursive(files[i], flags, 1);
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
			display_directory_recursive(files[i], flags, i);
		i++;
	}
}