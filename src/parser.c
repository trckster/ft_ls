/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 19:57:54 by bkayleen          #+#    #+#             */
/*   Updated: 2019/10/23 22:01:45 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		process_parsing(t_arguments *res, int argc, char **argv)
{
	int		i;
	int		flags_arguments;

	flags_arguments = determine_flags_arguments_count(argc, argv);
	i = 0;
	res->flags = (char *)malloc(2);
	res->flags[0] = 'r';
	// changes here
}

void		set_default_dir(t_arguments *res)
{
	char	*dir;

	dir = (char *)ft_memalloc(sizeof(dir) * 2);
	dir[0] = '.';
	res->input_files = (char **)ft_memalloc(2);
	res->input_files[0] = dir;
}

t_arguments	*parse_arguments(int argc, char **argv)
{
	t_arguments	*res;

	res = (t_arguments *)ft_memalloc(sizeof(res));
	if (argc)
		process_parsing(res, argc, argv);
	if (!res->input_files)
		set_default_dir(res);
	return (res);
}
