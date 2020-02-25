/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 16:11:56 by bkayleen          #+#    #+#             */
/*   Updated: 2020/02/25 14:30:00 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_sprintf(char *pattern, ...)
{
	va_list		args;
	int			i;
	char		*result;

	va_start(args, pattern);
	result = ft_strnew(0);
	i = 0;
	while (pattern[i])
		if (pattern[i] == '%')
		{
			i++;
			if (pattern[i] == 's')
				ft_cjoin(&result, va_arg(args, char *));
			else if (pattern[i] == 'd')
				ft_cjoin(&result, ft_itoa(va_arg(args, int)));
			else if (pattern[i] == 'c')
				ft_chrcjoin(&result, (char)va_arg(args, int));
			else
				ft_chrcjoin(&result, pattern[--i]);
			i++;
		}
		else
			ft_chrcjoin(&result, pattern[i++]);
	va_end(args);
	return (result);
}
