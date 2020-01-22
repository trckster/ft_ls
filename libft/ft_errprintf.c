/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:39:37 by bkayleen          #+#    #+#             */
/*   Updated: 2020/01/22 16:40:28 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_errprintf(char *pattern, ...)
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
				ft_putstr_fd(va_arg(args, char *), 2);
			else if (pattern[i] == 'd')
				ft_putnbr_fd(va_arg(args, int), 2);
			else if (pattern[i] == 'c')
				ft_putchar_fd((char)va_arg(args, int), 2);
			else
				ft_putchar_fd(pattern[--i], 2);
		}
		else
			ft_putchar_fd(pattern[i], 2);
		i++;
	}

	va_end(args);
}
