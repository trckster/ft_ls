/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 21:49:13 by bkayleen          #+#    #+#             */
/*   Updated: 2019/09/20 22:42:23 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_istotrim(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	int		i;
	char	*res;

	if (!s)
		return (0);
	start = 0;
	end = ft_strlen(s) - 1;
	while (s[start] && ft_istotrim(s[start]))
		start++;
	while (end >= 0 && ft_istotrim(s[end]))
		end--;
	end += 1;
	if (start > end)
		start = end;
	if (!(res = (char *)malloc(end - start + 1)))
		return (0);
	i = -1;
	while (start + ++i < end)
		res[i] = s[start + i];
	res[i] = 0;
	return (res);
}
