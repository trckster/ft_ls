/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 21:33:28 by bkayleen          #+#    #+#             */
/*   Updated: 2019/10/23 23:31:19 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			determine_flags_arguments_count(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (!ft_starts_with("-", argv[i]) || ft_strlen(argv[i]) < 2)
			break ;
		if (argv[i][1] == '-')
			break ;
		i++;
	}
	return (i);
}

char		*find_next_group(char *s)
{
	char	*flags_group;
	int		i;

	flags_group = ft_strnew(0);
	i = 1;
	while (s[i])
	{
		if (ft_not_in(s[i], flags_group))
			ft_chrcjoin(&flags_group, s[i]);
		i++;
	}
	return (flags_group);
}

char		bad_flags(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (ft_not_in(s[i], AVAILABLE_FLAGS))
			return (s[i]);
		i++;
	}
	return (0);
}

char		*parse_flags(char **argv, int flags_count)
{
	int		i;
	char	*all_input_flags;
	char	*tmp_flags;
	char	bad_one;

	all_input_flags = ft_strnew(0);
	i = 1;
	while (i < flags_count)
	{
		tmp_flags = find_next_group(argv[i]);
		ft_cjoin(&all_input_flags, tmp_flags);
		free(tmp_flags);
		i++;
	}
	bad_one = bad_flags(all_input_flags);
	if (bad_one)
	{
		show_usage(argv[0], "bad found");
		free(all_input_flags);
		return (0);
	}
	return (all_input_flags);
}
