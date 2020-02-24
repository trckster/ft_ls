/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_usage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 21:28:23 by bkayleen          #+#    #+#             */
/*   Updated: 2020/01/22 23:36:31 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


void	spawn_error(char *error_msg)
{
	ft_errprintf("ft_ls: %s\n", error_msg);
}

void	show_usage()
{
	ft_errprintf("usage: ./ft_ls [-%s] [file ...]\n", AVAILABLE_FLAGS);
}
