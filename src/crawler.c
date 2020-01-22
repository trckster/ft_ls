/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crawler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 21:44:53 by bkayleen          #+#    #+#             */
/*   Updated: 2020/01/22 22:34:53 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_needed_files_entries(char **files)
{
	int	i;
	struct stat path_stat;

	i = 0;
	while (files[i])
	{
		stat(files[i], &path_stat);
		if ((path_stat.st_mode & S_IFMT) == S_IFREG)
			ft_printf("File\n");
		else
			ft_printf("Dir\n");
		i++;
		//ft_printf("%s\n", path_stat.st_mode);
	}
}
