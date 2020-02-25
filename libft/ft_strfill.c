/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:27:53 by bkayleen          #+#    #+#             */
/*   Updated: 2020/02/25 14:28:03 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfill(int n, char c)
{
	char	*res;
	int		i;

	res = (char *)(malloc(sizeof(char) * (n + 1)));
	i = 0;
	while (i < n)
	{
		res[i] = c;
		i++;
	}
	res[i] = 0;
	return (res);
}
