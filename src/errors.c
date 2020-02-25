/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:01:28 by bkayleen          #+#    #+#             */
/*   Updated: 2020/02/25 14:01:39 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	show_error_when_opening_dir(char *dirname)
{
	char	*tmp;

	tmp = ft_sprintf("./ft_ls: cannot open directory '%s'", dirname);
	perror(tmp);
	free(tmp);
}
