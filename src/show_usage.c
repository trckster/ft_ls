/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_usage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 21:28:23 by bkayleen          #+#    #+#             */
/*   Updated: 2019/10/23 21:31:04 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	show_usage(char *name, char *error_msg)
{
	ft_putstr(name);
	ft_putstr(": ");
	ft_putstr(error_msg);
	ft_putstr("\n");
	ft_putstr("usage, write printf first");
	ft_putstr("\n");
}
