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

void	process_ls(t_arguments *arguments)
{
	t_file **files;
	// 1) get all files to array
	fill_different_files(arguments->input_files, &files);
	// 2) sort this god damn shit (t/r/none)
	// 3) display all files
	display_t_files(files, arguments->flags);
//	display_files(items, arguments->flags);
	// 4.1) display all directories
//	display_dirs(items, arguments->flags);
	// 4.2) when displaying dirs, make 1), then, if -R, do 4.2) more
}
