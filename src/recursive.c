/**
 *
 * Header
 *
 */

#include "ft_ls.h"

void    display_t_files(t_file **files, char *flags)
{
	int i;

	i = 0;
	while (files[i])
	{
		display_t_file(files[i], flags);
		i++;
	}
}

void    display_directory_recursive(char *dir, char *flags)
{
	t_file **files;

	ft_printf("%s:\n", dir);
	fill_files(dir, &files);
//	sort_ur_ass(); // TODO: not implemented
	display_t_files(files, flags);
	// NEXTODO: start iterating recursively v konce koncov
	free(files); // TODO: free all files, not only link to the files c:
}