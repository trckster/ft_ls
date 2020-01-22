/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:36:06 by bkayleen          #+#    #+#             */
/*   Updated: 2020/01/22 16:52:42 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

# define FT_LS_H

# include "../libft/includes/libft.h"
# include <stdio.h>

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
int				check_flags(t_arguments *arguments, char *program_name);
void			process_ls(t_arguments *);
void			spawn_error(char *program_name, char *error);

#endif
