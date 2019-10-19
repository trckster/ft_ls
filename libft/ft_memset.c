/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 20:50:00 by bkayleen          #+#    #+#             */
/*   Updated: 2019/09/17 21:14:02 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int c, size_t len)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)dst;
	i = 0;
	while (i < len)
	{
		p[i] = c;
		i++;
	}
	return (dst);
}
