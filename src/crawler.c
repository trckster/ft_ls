/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crawler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 21:44:53 by bkayleen          #+#    #+#             */
/*   Updated: 2020/01/22 23:37:30 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int     input_files_count(char **input)
{
	int i;

	i = 0;
	while (input[i])
		i++;
	return (i);
}

/**
 * TODO: Actually we need no this func,
 * write set_stat_refs func, see how it can help.
 * @param input
 * @param files
 */
void	get_needed_files_entries(char **input, char ***files)
{
	int         i;
	int         files_cnt;
	struct stat entry;

	*files = (char **)malloc(sizeof(char *) * (input_files_count(input) + 1));
	i = 0;
	files_cnt = 0;
	while (input[i])
	{
		if (stat(input[i], &entry) == -1)
		{
			// TODO: actually here can be other error so it must be determined inside spawner
			spawn_error(ft_sprintf("%s: No such file or directory", input[i]));
			i++;
			continue;
		}
		(*files)[files_cnt++] = ft_strdup(input[i]);
		i++;
	}
	(*files)[files_cnt] = 0;
}

int    available_files_count(char *dirname)
{
	dirname++;
	return 200; // TODO: Hardcoded now, must be WRITTEN OF COURSE
}

int     set_file(t_file **files, char *pathname, char *name)
{
	t_file  *file;

	file = (t_file *)malloc(sizeof(t_file));
	file->entry = (struct stat *)malloc(sizeof(struct stat));
	if (stat(pathname, file->entry) == -1) {
		perror("fuck dat"); // TODO: perror normal display
		free(file->entry);
		free(file);
		return (-1);
	}
	file->filename = ft_strdup(name);
	file->pathname = ft_strdup(pathname);
	*files = file;
	return (0);
}

void    fill_files(char *dirname, t_file ***files)
{
	int             i;
	int             files_cnt;
	char            *temp;
	DIR             *dir;
	struct dirent   *dp;

	if (!(dir = opendir(dirname)))
	{
		perror("Error opening dir");// TODO: Normalize perror
		return ; // TODO: change void to int and return -1 if crashes
	}
	i = 0;
	files_cnt = available_files_count(dirname);
	*files = (t_file **)ft_memalloc(sizeof(t_file *) * (files_cnt + 1));
	while ((dp = readdir(dir))) {
		temp = full(dirname, dp->d_name);
		if (set_file(*files + i, temp, dp->d_name) != -1)
			i++;
		free(temp);
	}
	closedir(dir);
	(*files)[i] = 0;
}