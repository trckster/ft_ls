/**
 *
 * Header
 *
 */

#include "ft_ls.h"

void    display_directory_recursive(char *dir)
{
	t_file **files;
	ft_printf("Trying to read dir %s\n", dir);
	fill_files(dir, &files);
	int i = 0;
	while (files[i]) {
		ft_printf("> %s - %s\n", files[i]->filename, files[i]->pathname);
		i++;
	}
//	sort_ur_ass(); // TODO: not implemented
	free(files); // TODO: free all files, not only link to the files c:
}