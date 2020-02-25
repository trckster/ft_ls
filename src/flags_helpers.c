/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 17:09:55 by bkayleen          #+#    #+#             */
/*   Updated: 2020/02/25 14:04:10 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	with_hidden(char *flags)
{
	return (ft_in('a', flags));
}

int	with_meta(char *flags)
{
	return (ft_in('l', flags));
}

int	recursive(char *flags)
{
	return (ft_in('R', flags));
}

int	sort_by_modification(char *flags)
{
	return (ft_in('t', flags));
}

int	reverse_sort(char *flags)
{
	return (ft_in('r', flags));
}
