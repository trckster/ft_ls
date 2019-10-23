/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:36:06 by bkayleen          #+#    #+#             */
/*   Updated: 2019/10/23 22:29:09 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

# define FT_LS_H

# include "../libft/includes/libft.h"

# define AVAILABLE_FLAGS "alrtR"

typedef struct	s_arguments
{
	char **input_files;
	char *flags;
}				t_arguments;

t_arguments		*parse_arguments(int argc, char **argv);
int				determine_flags_arguments_count(int argc, char **argv);
void			show_usage(char *a, char *b);
char			*parse_flags(char **argv, int flags_count);

#endif
