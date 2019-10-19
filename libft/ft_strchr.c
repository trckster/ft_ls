/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:39:25 by bkayleen          #+#    #+#             */
/*   Updated: 2019/09/19 14:58:05 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*t;

	t = (char *)s;
	i = 0;
	while (t[i])
	{
		if ((char)c == t[i])
			return (t + i);
		i++;
	}
	if ((char)c == t[i])
		return (t + i);
	return (0);
}
