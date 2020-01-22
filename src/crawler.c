/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crawler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 21:44:53 by bkayleen          #+#    #+#             */
/*   Updated: 2020/01/22 23:37:30 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_needed_files_entries(char **files)
{
	int	i;
	struct stat entry;

	i = 0;
	while (files[i])
	{
		if (stat(files[i], &entry) == -1)
		{
			// actually here can be other error so it must be determined inside spawner
			spawn_error(ft_sprintf("%s: No such file or directory", files[i]));
			i++;
			continue;
		}
		ft_printf("%d\n", entry.st_mode);
		if ((entry.st_mode & S_IFMT) == S_IFREG)
			ft_printf("File\n");
		else
			ft_printf("Dir\n");
		i++;
		//ft_printf("%s\n", path_stat.st_mode);
	}
}
