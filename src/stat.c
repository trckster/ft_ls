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

char                *get_file_owner(char *filename)
{
	struct stat     entry;
	struct passwd   *pw;

	stat(filename, &entry);
	pw = getpwuid(entry.st_uid);
	return pw->pw_name;
}

t_file_extra_data   *init_file_extra_data(t_file *file)
{
	t_file_extra_data   *data;

	data = (t_file_extra_data *)malloc(sizeof(t_file_extra_data));
	/** TODO End it all */
	data->privileges = ft_strdup("-rw-rw-r--@?");
	data->links_count = 3;
	data->owner_name = ft_strdup("trickster");
	data->owner_group = ft_strdup("root---group");
	data->file_size = ft_strlen(file->filename);
	data->last_modification = ft_strdup("Jan 22 21:34");

	return (data);
}