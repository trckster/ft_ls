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

char        *get_file_owner(char *filename)
{
	struct stat     entry;
	struct passwd   *pw;

	stat(filename, &entry);
	pw = getpwuid(entry.st_uid);
	return pw->pw_name;
}

