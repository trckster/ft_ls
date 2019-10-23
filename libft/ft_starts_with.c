/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_starts_with.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 21:05:21 by bkayleen          #+#    #+#             */
/*   Updated: 2019/10/23 21:07:41 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_starts_with(char *needle, char *haystack)
{
	int	i;

	i = 0;
	while (needle[i])
	{
		if (needle[i] != haystack[i])
			return (0);
		i++;
	}
	return (1);
}
