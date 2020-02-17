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
	// TODO: end it!
	ft_printf(">>> File owner: %s -------- ----------- :: %s\n",
	          get_file_owner(file->pathname),
	          file->pathname);
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
	// sort_ur_ass TODO
	display_t_files(files, flags, 'a');
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
