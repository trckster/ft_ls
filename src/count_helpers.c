/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:53:08 by bkayleen          #+#    #+#             */
/*   Updated: 2020/02/25 14:14:08 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	files_count(t_file **files)
{
	int	i;

	i = 0;
	while (files[i])
		i++;
	return (i);
}

int	is_default_dir(char *filename)
{
	return (!ft_strcmp(filename, "..") || !ft_strcmp(filename, "."));
}
