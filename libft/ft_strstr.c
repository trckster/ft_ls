/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kek.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:59:57 by bkayleen          #+#    #+#             */
/*   Updated: 2019/09/19 16:09:16 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *h, const char *n)
{
	int		i;
	int		h_len;
	int		n_len;

	h_len = ft_strlen(h);
	n_len = ft_strlen(n);
	if (!n_len)
		return ((char *)h);
	i = 0;
	while (i + n_len <= h_len)
	{
		if (ft_strncmp(n, ((char *)h) + i, n_len))
			i++;
		else
			return ((char *)(i + h));
	}
	return (0);
}
