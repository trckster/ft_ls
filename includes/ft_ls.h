/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:36:06 by bkayleen          #+#    #+#             */
/*   Updated: 2020/01/22 23:37:18 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

# define FT_LS_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>

# define AVAILABLE_FLAGS "alrtR"

typedef struct	s_arguments
{
	char **input_files;
	char *flags;
}				t_arguments;

typedef struct  s_file
{
	char        *filename;
	char        *pathname;
	struct stat *entry;
}               t_file;

t_arguments		*parse_arguments(int argc, char **argv);
int				determine_flags_arguments_count(int argc, char **argv);
char			*parse_flags(char **argv, int flags_count);
char			**parse_files(int argc, char **argv, int already_parsed);
int				check_flags(t_arguments *arguments);
void			process_ls(t_arguments *);
void			spawn_error(char *error);
void			show_usage(void);
void			display_file(char *filename, char *flags);
void			display_file_with_meta(char *filename);
void			get_needed_files_entries(char **input, char ***files);
void            display_files(char **items, char *flags);
void            display_dirs(char **items, char *flags);
int             with_hidden(char *flags);
int             with_meta(char *flags);
int             recursive(char *flags);
int             file_is_hidden(char *filename);
char            *get_file_owner(char *filename);
void            display_directory_recursive(char *dir, char *f);
char            *full(char *a, char *b);
void            fill_files(char *dirname, t_file ***stats);
void            display_t_file(t_file *file, char *flags);

#endif
