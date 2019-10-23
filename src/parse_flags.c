/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 21:33:28 by bkayleen          #+#    #+#             */
/*   Updated: 2019/10/23 22:17:09 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			determine_flags_arguments_count(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (!ft_starts_with("-", argv[i]) || ft_strlen(argv[i]) < 2)
			break ;
		if (argv[i][1] == '-')
			break ;
		i++;
	}
	return (i);
}
