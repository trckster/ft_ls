/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:38:51 by bkayleen          #+#    #+#             */
/*   Updated: 2019/09/19 14:38:52 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int	dest_len;
	int	src_len;
	int	i;

	i = 0;
	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	while (i < src_len)
	{
		dest[i + dest_len] = src[i];
		i++;
	}
	dest[dest_len + i] = 0;
	return (dest);
}
