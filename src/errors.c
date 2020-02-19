/**
 *
 * Header
 *
 */

#include "ft_ls.h"

void    show_error_when_opening_dir(char *dirname)
{
	char *tmp;

	tmp = ft_sprintf("./ft_ls: cannot open directory '%s'", dirname);
	perror(tmp);
	free(tmp);
}