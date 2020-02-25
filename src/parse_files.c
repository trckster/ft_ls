/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 22:43:13 by bkayleen          #+#    #+#             */
/*   Updated: 2020/02/25 14:09:07 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**parse_files(int argc, char **argv, int already_parsed)
{
	int		i;
	char	**parsed;
	int		files_count;
	int		cnt;

	files_count = argc - already_parsed;
	i = 0;
	argv += already_parsed;
	if (argv[i] && argv[i][0] == '-' && argv[i][1] == '-' && !argv[i][2])
		i += 1;
	parsed = (char **)malloc(sizeof(char *) * (files_count + 1 - i));
	cnt = 0;
	while (i < files_count)
		parsed[cnt++] = ft_strdup(argv[i++]);
	parsed[cnt] = 0;
	return (parsed);
}
