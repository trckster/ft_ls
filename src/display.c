/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 20:40:51 by bkayleen          #+#    #+#             */
/*   Updated: 2020/01/22 20:42:33 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display_t_file_with_meta(t_file *file)
{
	char    *links_count_prepared;
	char    *owner_name_prepared;
	char    *owner_group_prepared;
	char    *file_size_prepared;

	links_count_prepared = prepare_links_count(file);
	owner_name_prepared = prepare_name(file);
	owner_group_prepared = prepare_group(file);
	file_size_prepared = prepare_size(file);
	ft_printf(
			"%s %s %s %s %s %s %s\n",
			file->extra->privileges,
			links_count_prepared,
			owner_name_prepared,
			owner_group_prepared,
			file_size_prepared,
			file->extra->last_modification,
			file->filename
			);
	free(links_count_prepared);
	free(owner_name_prepared);
	free(owner_group_prepared);
	free(file_size_prepared);
}

void    display_t_file(t_file *file, char *flags)
{
	if (!with_hidden(flags) && file_is_hidden(file->filename))
		return ;
	if (with_meta(flags))
	{
		display_t_file_with_meta(file);
	}
	else
	{
		ft_putstr(file->filename);
		ft_putchar(' ');
	}
}

void    display_dir_content(t_file *file, char *flags)
{
	t_file  **files;

	fill_files(file->pathname, &files);
	sort_files(&files, flags);

	display_t_files(files, flags, 'a');
	free_files(files);
}

void    display_all_dirs_with_content(t_file **files, char *flags)
{
	int     i;
	int     show_preview;

	show_preview = files_count(files) > 1;
	i = 0;
	while (files[i])
	{
		if (isdir(files[i]))
		{
			if (show_preview)
				ft_printf("%s:\n", files[i]->filename);
			display_dir_content(files[i], flags);
		}
		i++;
	}
}
