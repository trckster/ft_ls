/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 17:09:55 by bkayleen          #+#    #+#             */
/*   Updated: 2020/02/01 17:09:55 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int     file_is_hidden(char *filename)
{
	return ft_starts_with(".", filename);
}

char    *full(char *dirname, char *filename)
{
	char    *with_slash;

	with_slash = ft_strjoin(dirname, "/");
	return ft_strjoin(with_slash, filename);
}

int     isdir(t_file *file)
{
	return ((file->entry->st_mode & S_IFMT) == S_IFDIR);
}