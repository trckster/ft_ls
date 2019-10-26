/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 19:57:54 by bkayleen          #+#    #+#             */
/*   Updated: 2019/10/23 23:28:39 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		process_parsing(t_arguments *res, int argc, char **argv)
{
	int		flags_arguments;

	flags_arguments = determine_flags_arguments_count(argc - 1, argv + 1);
	res->flags = parse_flags(argv + 1, flags_arguments);
	// res->input_files = parse_files(argc, argv, flags_arguments);
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
	if (argc - 1)
		process_parsing(res, argc, argv);
	else
		res->flags = ft_strnew(0);
	if (!res->input_files)
		set_default_dir(res);
	return (res);
}
