/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crawler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 21:44:53 by bkayleen          #+#    #+#             */
/*   Updated: 2020/02/25 13:57:18 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		available_files_count(char *dirname)
{
	int				i;
	char			*temp;
	DIR				*dir;
	struct dirent	*dp;
	struct stat		entry;

	dir = opendir(dirname);
	i = 0;
	while ((dp = readdir(dir)))
	{
		temp = full(dirname, dp->d_name);
		if (lstat(temp, &entry) != -1)
			i++;
		free(temp);
	}
	closedir(dir);
	return (i);
}

int		set_file(t_file **files, char *pathname, char *name)
{
	t_file	*file;
	char	*tmp;

	file = (t_file *)ft_memalloc(sizeof(t_file));
	file->entry = (struct stat *)ft_memalloc(sizeof(struct stat));
	file->pathname = ft_strdup(pathname);
	file->filename = ft_strdup(name);
	if (lstat(pathname, file->entry) == -1)
	{
		tmp = ft_sprintf("./ft_ls: cannot access '%s'", file->filename);
		perror(tmp);
		free(tmp);
		free_file_without_extra(file);
		return (-1);
	}
	file->extra = init_file_extra_data(file);
	*files = file;
	return (0);
}

int		fill_files(char *dirname, t_file ***files)
{
	int				i;
	int				files_cnt;
	char			*temp;
	DIR				*dir;
	struct dirent	*dp;

	if (!(dir = opendir(dirname)))
	{
		show_error_when_opening_dir(dirname);
		return (-1);
	}
	i = 0;
	files_cnt = available_files_count(dirname);
	*files = (t_file **)ft_memalloc(sizeof(t_file *) * (files_cnt + 1));
	while ((dp = readdir(dir)))
	{
		temp = full(dirname, dp->d_name);
		if (set_file(*files + i, temp, dp->d_name) != -1)
			i++;
		free(temp);
	}
	closedir(dir);
	(*files)[i] = 0;
	set_files_indentations(*files);
	return (0);
}

int		count_input_files(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	fill_different_files(char **inputs, t_file ***unprepared_files)
{
	t_file	**files;
	int		valid_files_count;
	int		i;
	int		j;

	valid_files_count = count_input_files(inputs);
	files = (t_file **)malloc(sizeof(t_file *) * (valid_files_count + 1));
	i = 0;
	j = 0;
	while (j < valid_files_count && inputs[j])
	{
		if (set_file(files + i, inputs[j], inputs[j]) != -1)
			i++;
		j++;
	}
	files[i] = 0;
	set_files_indentations(files);
	*unprepared_files = files;
}
