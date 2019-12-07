/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_usage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 21:28:23 by bkayleen          #+#    #+#             */
/*   Updated: 2019/12/07 16:04:08 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	spawn_error(char *name, char *error_msg)
{
	ft_printf("%s: %s\n", name, error_msg);
	ft_printf("usage: ./ft_ls [-%s] [file ...]\n", AVAILABLE_FLAGS);
}
