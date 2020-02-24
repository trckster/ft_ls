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

void                display_total(t_file **files, char *flags)
{
	int total;
	int i;

	total = 0;
	i = 0;
	while (files[i])
	{
		if (with_hidden(flags) || !file_is_hidden(files[i]->filename))
			total += files[i]->entry->st_blocks;
		i++;
	}
	ft_printf("total %d\n", total);
}

void                set_owner_info(t_file *file, t_file_extra_data *data)
{
	struct passwd   *pw;
	struct group    *gr;

	stat(file->pathname, file->entry);
	pw = getpwuid(file->entry->st_uid);
	gr = getgrgid(file->entry->st_gid);
	data->owner_name = ft_strdup(pw->pw_name);
	data->owner_group = ft_strdup(gr->gr_name);
}

t_file_extra_data   *init_file_extra_data(t_file *file)
{
	t_file_extra_data   *data;

	data = (t_file_extra_data *)malloc(sizeof(t_file_extra_data));
	/** TODO End it all */
	data->privileges = ft_strdup("-rw-rw-r--");
	data->links_count = ft_strlen(file->filename) * 10;
	set_owner_info(file, data);
	data->file_size = ft_strlen(file->filename);
	data->last_modification = ft_strdup("Jan 22 21:34");

	return (data);
}