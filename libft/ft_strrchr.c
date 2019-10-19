/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:39:34 by bkayleen          #+#    #+#             */
/*   Updated: 2019/09/20 20:40:12 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*t;

	t = (char *)s;
	len = ft_strlen(s);
	while (len >= 0)
	{
		if (t[len] == (char)c)
			return (t + len);
		len--;
	}
	return (0);
}
