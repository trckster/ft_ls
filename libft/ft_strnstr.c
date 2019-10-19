/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:22:05 by bkayleen          #+#    #+#             */
/*   Updated: 2019/09/20 20:49:07 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t all)
{
	int		i;
	int		h_len;
	int		n_len;

	h_len = ft_strlen(h);
	n_len = ft_strlen(n);
	if (!n_len)
		return ((char *)h);
	if (all < (size_t)n_len)
		return (0);
	i = 0;
	while (i + n_len <= h_len && i + n_len <= (int)all)
	{
		if (ft_strncmp(n, ((char *)h) + i, n_len))
			i++;
		else
			return ((char *)(i + h));
	}
	return (0);
}
