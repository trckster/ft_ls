/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 18:56:35 by bkayleen          #+#    #+#             */
/*   Updated: 2019/09/20 22:55:39 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_strings(char const *s, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	if (s[i++] != c)
		cnt++;
	while (s[i])
	{
		if (s[i - 1] == c && s[i] != c)
			cnt++;
		i++;
	}
	return (cnt);
}

static char	*ft_find_next(char const *s, int *i, char c)
{
	char	*res;
	int		finish;

	finish = *i;
	while (s[finish] && s[finish] != c)
		finish++;
	if (!(res = ft_strsub(s, *i, finish - *i)))
		return (0);
	*i = finish;
	return (res);
}

static char	**ft_clean_all(char **s)
{
	int i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
	return (0);
}

char		**ft_strsplit(char const *s, char c)
{
	int		cnt;
	char	**res;
	int		i;
	int		res_i;

	if (!s)
		return (0);
	i = 0;
	res_i = 0;
	cnt = ft_count_strings(s, c);
	if (!(res = (char **)(malloc((cnt + 1) * sizeof(char **)))))
		return (0);
	while (s[i])
	{
		if (s[i] != c)
			if (!(res[res_i++] = ft_find_next(s, &i, c)))
				return (ft_clean_all(res));
		if (!s[i])
			break ;
		if (s[i] == c)
			i++;
	}
	res[res_i] = 0;
	return (res);
}
