/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:37:12 by bkayleen          #+#    #+#             */
/*   Updated: 2019/10/23 21:32:07 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	t_arguments *arguments;

	arguments = parse_arguments(argc - 1, argv + 1);
	ft_putstr(arguments->flags);
	return (0);
}