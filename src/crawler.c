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

int     input_files_count(char **input)
{
	int i;

	i = 0;
	while (input[i])
		i++;
	return (i);
}

void	get_needed_files_entries(char **input, char ***files)
{
	int         i;
	int         files_cnt;
	struct stat entry;

	*files = (char **)malloc(sizeof(char *) * (input_files_count(input) + 1));
	i = 0;
	files_cnt = 0;
	while (input[i])
	{
		if (stat(input[i], &entry) == -1)
		{
			// actually here can be other error so it must be determined inside spawner
			spawn_error(ft_sprintf("%s: No such file or directory", input[i]));
			i++;
			continue;
		}
		(*files)[files_cnt++] = ft_strdup(input[i]);
		i++;
	}
	(*files)[files_cnt] = 0;
}
