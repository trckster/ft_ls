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

	fill_different_files(arguments->input_files, &files);

	display_t_files(files, arguments->flags, 'f');

	if (recursive(arguments->flags))
		display_all_dirs_recursive(files, arguments->flags);
	else
		display_all_dirs_with_content(files, arguments->flags);
//		display_t_files(files, arguments->flags, 'd');

	free_files(files);
}
