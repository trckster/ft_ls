/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 17:09:55 by bkayleen          #+#    #+#             */
/*   Updated: 2020/02/01 17:09:55 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    swap_files(t_file **file, t_file **file2)
{
	t_file  *tmp;

	tmp = *file;
	*file = *file2;
	*file2 = tmp;
}

int     file_is_hidden(char *filename)
{
	int starts_with_dot;
	int starts_with_dir_dot;
	int starts_with_dir_2dot;

	starts_with_dot = ft_starts_with(".", filename);
	starts_with_dir_dot = ft_starts_with("./", filename);
	starts_with_dir_2dot = ft_starts_with("../", filename);
	return (starts_with_dot && !(starts_with_dir_2dot || starts_with_dir_dot));
}

char    *full(char *dirname, char *filename)
{
	char    *with_slash;

	with_slash = ft_strjoin(dirname, "/");
	return ft_strjoin(with_slash, filename);
}

int     isdir(t_file *file)
{
	return ((file->entry->st_mode & S_IFMT) == S_IFDIR);
}

void    reverse_files(t_file ***given_files)
{
	t_file  **files;
	int     i;
	int     count;

	files = *given_files;
	count = files_count(files);
	i = 0;
	while (i + i < count)
	{
		swap_files(files + i, files + count - i - 1);
		i++;
	}
}