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

	pw = getpwuid(file->entry->st_uid);
	gr = getgrgid(file->entry->st_gid);
	if (pw)
		data->owner_name = ft_strdup(pw->pw_name);
	else
		data->owner_name = ft_itoa(file->entry->st_uid);
	if (gr)
		data->owner_group = ft_strdup(gr->gr_name);
	else
		data->owner_group = ft_itoa(file->entry->st_gid);
}

char                *get_last_modification_time(t_file *file)
{
	char    *full;
	char    *res;

	full = ft_strdup(ctime(&(file->entry->st_mtime)));
	res = ft_strsub(full, 4, 12);
	free(full);
	return (res);
}

t_file_extra_data   *init_file_extra_data(t_file *file)
{
	t_file_extra_data   *data;

	data = (t_file_extra_data *)malloc(sizeof(t_file_extra_data));
	data->privileges = get_privileges(file);
	data->links_count = file->entry->st_nlink;
	set_owner_info(file, data);
	data->file_size = file->entry->st_size;
	data->last_modification = get_last_modification_time(file);
	return (data);
}