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

typedef struct  s_file_extra_data
{
	char    *privileges;
	int     links_count;
	char    *owner_name;
	char    *owner_group;
	int     file_size;
	char    *last_modification;
}               t_file_extra_data;

t_arguments	    	*parse_arguments(int argc, char **argv);
int				    determine_flags_arguments_count(int argc, char **argv);
char    		    *parse_flags(char **argv, int flags_count);
char	    		**parse_files(int argc, char **argv, int already_parsed);
int			    	check_flags(t_arguments *arguments);
void			    process_ls(t_arguments *);
void    			spawn_error(char *error);
void	    		show_usage(void);
char                *get_file_owner(char *filename);
void                display_directory_recursive(t_file *file, char *f);
int                 fill_files(char *dirname, t_file ***stats);
void                display_t_file(t_file *file, char *flags);
int                 set_file(t_file **files, char *pathname, char *name);
void                fill_different_files(char **files, t_file ***f);
void                display_t_files(t_file **files, char *f, char type);
void                display_all_dirs_recursive(t_file **files, char *flags);
void                display_all_dirs_with_content(t_file **files, char *flags);
int                 files_count(t_file **files);
void                sort_files(t_file ***files, char *flags);
t_file_extra_data   *init_file_extra_data(t_file *file);

/** Files helpers */
void                swap_files(t_file **file, t_file **file2);
int                 file_is_hidden(char *filename);
char                *full(char *a, char *b);
int                 isdir(t_file *file);
void                reverse_files(t_file ***files);

/** Flags helpers */
int                 with_hidden(char *flags);
int                 with_meta(char *flags);
int                 recursive(char *flags);
int                 sort_by_modification(char *flags);
int                 reverse_sort(char *flags);

/** Free */
void                free_files(t_file **files);
void                free_file(t_file *file);
void                free_file_extra_data(t_file_extra_data *data);

/** Errors showing */
void                show_error_when_opening_dir(char *dirname);

#endif
