/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indentations_builder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:07:17 by bkayleen          #+#    #+#             */
/*   Updated: 2020/02/25 14:07:19 by bkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*prepare_links_count(t_file *f)
{
	char	*links_count;
	char	*res;

	links_count = ft_itoa(f->extra->links_count);
	res = ft_rjust(links_count, f->indentations->link_size, ' ');
	free(links_count);
	return (res);
}

char	*prepare_name(t_file *f)
{
	char	*res;
	char	*base;

	base = f->extra->owner_name;
	res = ft_ljust(base, f->indentations->owner_name_size, ' ');
	return (res);
}

char	*prepare_group(t_file *f)
{
	char	*res;
	char	*base;

	base = f->extra->owner_group;
	res = ft_ljust(base, f->indentations->owner_group_size, ' ');
	return (res);
}

char	*prepare_size(t_file *f)
{
	char	*size;
	char	*res;

	size = ft_itoa(f->extra->file_size);
	res = ft_rjust(size, f->indentations->file_size_size, ' ');
	free(size);
	return (res);
}
