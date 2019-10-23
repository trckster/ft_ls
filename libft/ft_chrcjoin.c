/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrcjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 23:17:29 by bkayleen          #+#    #+#             */
/*   Updated: 2019/10/23 23:17:34 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_chrcjoin(char **s, char chr)
{
	char	*tmp;
	char	*n;

	n = (char *)malloc(sizeof(n) * 2);
	n[0] = chr;
	n[1] = 0;

	tmp = *s;
	*s = ft_strjoin(*s, n);
	free(tmp);
	free(n);
}
