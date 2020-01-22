/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:57:45 by bkayleen          #+#    #+#             */
/*   Updated: 2020/01/22 21:59:32 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	process_file(char *filename)
{
	ft_printf("%s\n", filename);
}

void	ft_ls(char *dir, char *flags)
{
	struct dirent *entry;
	DIR *dird;

	dird = opendir(dir);
	if (!dird || ft_in('Z', flags))
		return ;
	while((entry = readdir(dird)) != 0)
		process_file(entry->d_name);
	closedir(dird);
}

void	process_ls(t_arguments *arguments)
{
	// 1) get all files to array
	get_needed_files_entries(arguments->input_files);
	// 2) sort this god damn shit (t/r/none)
	// 3) display all files
	// 4.1) display all directories  
	// 4.2) when displaying dirs, make 1), then, if -R, do 4.2) more
	//while (files[i])
	//{
//		process_file(entry->d_name);
//		i++;
//	}
}
