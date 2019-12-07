/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:37:12 by bkayleen          #+#    #+#             */
/*   Updated: 2019/12/07 16:10:01 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		check_flags(t_arguments *arguments, char *program_name)
{
	char bad_char;

	bad_char = bad_flags(arguments->flags);
	if (bad_char)
	{
		free(arguments->flags);
		free(arguments->input_files);
		free(arguments);
		spawn_error(program_name, ft_sprintf("%s"));
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_arguments *arguments;

	arguments = parse_arguments(argc, argv);
	if (!arguments || !check_flags(arguments, argv[0]))
		return (0);
	ft_printf("Available flags: %s\n", arguments->flags);
	return (0);
}
