/**
 *
 * Headers
 *
 */

#include "ft_ls.h"

void    mswap(t_file **file, t_file **file2)
{
	t_file  *tmp;

	tmp = *file;
	*file = *file2;
	*file2 = tmp;
}

void    sort_files(t_file ***given_files, char *flags)
{
	t_file  **files;
	int     i;

	files = *given_files;
	i = 0;
	if (!files[i])
		return ;
	while (files[i + 1])
	{
		mswap(files + i, files +i + 1);
		i++;
	}
	flags++;
}