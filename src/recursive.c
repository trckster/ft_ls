/**
 *
 * Header
 *
 */

#include "ft_ls.h"

void    display_t_files(t_file **files, char *flags, char type)
{
	int i;

	i = 0;
	while (files[i])
	{
		if (type == 'a')
			display_t_file(files[i], flags);
		else if (type == 'd' && isdir(files[i]))
			display_t_file(files[i], flags);
		else if (type == 'f' && !isdir(files[i]))
			display_t_file(files[i], flags);
		i++;
	}
}

void    display_directory_recursive(t_file *file, char *flags)
{
	t_file  **files;
	int     i;

	ft_printf("%s:\n", file->pathname);
	fill_files(file->pathname, &files);
//	sort_ur_ass(); // TODO: not implemented
	display_t_files(files, flags, 'a');
	ft_putstr("\n\n");
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
	free(files); // TODO: free all files, not only link to the files c:
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

void    prepare_recursive(char *dir, char *flags)
{
	t_file *file;

	set_file(&file, dir, dir);

	display_directory_recursive(file, flags);
}