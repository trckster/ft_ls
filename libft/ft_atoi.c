/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:35:52 by bkayleen          #+#    #+#             */
/*   Updated: 2019/09/20 21:26:40 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\r')
		return (1);
	if (c == '\f' || c == '\n')
		return (1);
	if (c == '\t' || c == '\v')
		return (1);
	return (0);
}

static int	ft_isdigit(char c)
{
	return (c <= '9' && c >= '0');
}

int			ft_atoi(const char *s)
{
	int		minus;
	int		res;
	int		i;

	i = 0;
	res = 0;
	minus = 0;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '-')
	{
		minus = 1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (ft_isdigit(s[i]))
		res = res * 10 + s[i++] - '0';
	res = minus ? -res : res;
	return (res);
}
