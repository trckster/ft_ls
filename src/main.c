/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:37:12 by bkayleen          #+#    #+#             */
/*   Updated: 2019/12/05 13:59:09 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	t_arguments *arguments;

	arguments = parse_arguments(argc, argv);
	if (!arguments || !arguments->flags)
	{
		show_usage(argv[0], "Unhandled exception!");
		return (0);
	}
	ft_printf("Available flags: %s\n", arguments->flags);
	return (0);
}
