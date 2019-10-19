/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 19:14:41 by bkayleen          #+#    #+#             */
/*   Updated: 2019/09/19 19:55:24 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_reverse(char *s)
{
	int		i;
	int		len;
	char	tmp;
	int		minus;

	minus = 0;
	len = ft_strlen(s);
	if (s[0] == '-')
		minus = 1;
	i = 0;
	while (i + minus < len - i - 1)
	{
		tmp = s[i + minus];
		s[minus + i] = s[len - i - 1];
		s[len - i - 1] = tmp;
		i++;
	}
}

char		*ft_itoa(int n)
{
	char	*s;
	int		i;

	if (!(s = (char *)malloc(12)))
		return (0);
	i = 0;
	if (n < 0)
		s[i++] = '-';
	if (!n)
		s[i++] = '0';
	while (n)
	{
		s[i] = (n % 10 >= 0 ? n % 10 : -(n % 10)) + '0';
		i++;
		n /= 10;
	}
	s[i] = 0;
	ft_reverse(s);
	return (s);
}
