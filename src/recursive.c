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
//	sort_ur_ass(); // TODO: not implemented
	free(stats);
}