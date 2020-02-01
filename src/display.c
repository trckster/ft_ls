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

void	display_file(char *filename, char *flags)
{
	if (!with_hidden(flags) && file_is_hidden(filename))
		return ;
	ft_putstr(filename);
	ft_putchar(' ');
}

void	display_file_with_meta(char *filename)
{
	ft_printf("--------- -------- ----------- :: %s", filename);
}

void    display_files(char **items, char *flags)
{
	struct stat entry;
	int         i;

	i = 0;
	while (items[i])
	{
		stat(items[i], &entry);
		if ((entry.st_mode & S_IFMT) != S_IFREG)
		{
			i++;
			continue ;
		}
		display_file(items[i], flags);
		if (items[i + 1])
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

void    display_dir_with_content(char *dirname, int introduce_dir, char *flags)
{
	struct dirent *entry;
	DIR *dird;

	if (introduce_dir)
		ft_printf("%s:\n", dirname);
	if (!(dird = opendir(dirname)))
		return ;
	while((entry = readdir(dird)) != 0)
	{
		display_file(entry->d_name, flags);
	}
	closedir(dird);
	ft_putchar('\n');
}

void    display_dirs(char **items, char *flags)
{
	struct stat entry;
	int         i;

	i = 0;
	while (items[i])
	{
		stat(items[i], &entry);
		if ((entry.st_mode & S_IFMT) == S_IFREG)
		{
			i++;
			continue ;
		}
		display_dir_with_content(items[i], items[1] != 0, flags);
		i++;
	}
}
