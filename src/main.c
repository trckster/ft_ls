/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:37:12 by bkayleen          #+#    #+#             */
/*   Updated: 2019/10/23 23:27:38 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	t_arguments *arguments;

	arguments = parse_arguments(argc, argv);
	if (!arguments)
	{
		show_usage(argv[0], "somth went wrong =(");
		return (0);
	}
	ft_putstr(arguments->flags);
	return (0);
}
