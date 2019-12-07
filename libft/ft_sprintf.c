/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 16:11:56 by bkayleen          #+#    #+#             */
/*   Updated: 2019/12/07 16:16:36 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sprintf(char *pattern, ...)
{
	va_list		args;
	int 		i;

	va_start(args, pattern);
	i = 0;
	while (pattern[i])
	{
		if (pattern[i] == '%')
		{
			i++;
			if (pattern[i] == 's')
				ft_putstr(va_arg(args, char *));
			else if (pattern[i] == 'd')
				ft_putnbr(va_arg(args, int));
			else if (pattern[i] == 'c')
				ft_putchar((char)va_arg(args, int));
			else
				ft_putchar(pattern[--i]);
		}
		else
			ft_putchar(pattern[i]);
		i++;
	}

	va_end(args);
}
