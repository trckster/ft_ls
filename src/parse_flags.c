/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 21:33:28 by bkayleen          #+#    #+#             */
/*   Updated: 2020/02/25 14:20:36 by bkayleen         ###   ########.fr       */
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
		if (argv[i][1] == '-' && !argv[i][2])
			break ;
		i++;
	}
	return (i);
}

char		*find_next_group(char *s, char *already_found)
{
	char	*flags_group;
	int		i;

	flags_group = ft_strnew(0);
	i = 1;
	while (s[i])
	{
		if (ft_not_in(s[i], flags_group) && ft_not_in(s[i], already_found))
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

int			check_flags(t_arguments *arguments)
{
	char bad_char;
	char *tmp;

	bad_char = bad_flags(arguments->flags);
	if (bad_char)
	{
		tmp = ft_sprintf("illegal option -- %c", bad_char);
		spawn_error(tmp);
		free(tmp);
		show_usage();
		return (0);
	}
	return (1);
}

char		*parse_flags(char **argv, int flags_count)
{
	int		i;
	char	*all_input_flags;
	char	*tmp_flags;

	all_input_flags = ft_strnew(0);
	i = 0;
	while (i < flags_count)
	{
		tmp_flags = find_next_group(argv[i], all_input_flags);
		ft_cjoin(&all_input_flags, tmp_flags);
		free(tmp_flags);
		i++;
	}
	return (all_input_flags);
}
