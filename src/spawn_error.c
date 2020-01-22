/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:36:14 by bkayleen          #+#    #+#             */
/*   Updated: 2020/01/22 16:49:11 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	spawn_error(char *program_name, char *error)
{
	ft_putstr_fd(program_name, 2);
	ft_putstr_fd(error, 2);
}
