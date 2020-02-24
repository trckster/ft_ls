/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:37:12 by bkayleen          #+#    #+#             */
/*   Updated: 2020/01/22 23:31:41 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	t_arguments *arguments;

	arguments = parse_arguments(argc, argv);
	if (!arguments)
		return (0);
	if (check_flags(arguments))
		process_ls(arguments);
	free_arguments(arguments);
	return (0);
}
