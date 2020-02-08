/**
 *
 * Header
 *
 */

#include "ft_ls.h"

void    display_directory_recursive(char *dir)
{
	struct stat **stats;
	ft_printf("%s:\n", dir);
	set_stat_refs(dir, &stats);
//	sort_ur_ass(); // TODO: not implemented
	ft_printf("Trying to read dir %s\n", dir);
	free(stats);
}