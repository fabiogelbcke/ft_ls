/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_management2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/25 17:31:43 by fschuber          #+#    #+#             */
/*   Updated: 2015/06/12 20:53:10 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char				**get_dirs(DIR *directory
						, char *dirname, int items, int *options)
{
	char			**list;
	int				i;
	struct dirent	*entry;

	i = 0;
	list = malloc(sizeof(char*) * (items + 1));
	while ((entry = readdir(directory)))
	{
		if (entry->d_type == DT_DIR
			&& ((entry->d_name)[0] != '.' || options[2] == 1)
			&& ft_strcmp(entry->d_name, ".")
			&& ft_strcmp(entry->d_name, ".."))
			list[i++] = ft_strjoin(dirname, ft_strdup(entry->d_name));
	}
	list[i] = NULL;
	return (list);
}

t_node				*sort_list(t_node *list, int *options)
{
	t_node			*current;

	current = list;
	list = sort_ascii(list);
	if (options[4] == 1)
	{
		list = sort_by_time_modified(list, NULL);
	}
	else if (options[3] == 1)
	{
		list = invert_list(list);
	}
	return (list);
}

long int			*get_sizes(t_node *no, int *options)
{
	long int		*sizes;

	sizes = malloc(sizeof(long int) * 6);
	ft_memset(sizes, 0, sizeof(long int) * 6);
	while (no)
	{
		if ((no->name)[0] != '.' || options[2] == 1)
		{
			if (ft_strlen(ft_itoa(no->info.st_nlink)) > sizes[0])
				sizes[0] = ft_strlen(ft_itoa(no->info.st_nlink));
			if (ft_strlen(ft_itoa(no->info.st_size)) > sizes[1])
				sizes[1] = ft_strlen(ft_itoa(no->info.st_size));
			sizes[2] += no->info.st_blocks;
			if (getgrgid(no->info.st_gid)
				&& sizes[3] < ft_strlen(getgrgid(no->info.st_gid)->gr_name))
				sizes[3] = ft_strlen(getgrgid(no->info.st_gid)->gr_name);
			else if (sizes[3] < ft_strlen(ft_itoa(no->info.st_gid)))
				sizes[3] = ft_strlen(ft_itoa(no->info.st_gid));
			if (getpwuid(no->info.st_uid)
				&& sizes[5] < ft_strlen(getpwuid(no->info.st_uid)->pw_name))
				sizes[5] = ft_strlen(getpwuid(no->info.st_uid)->pw_name);
			else if (sizes[5] < ft_strlen(ft_llitoa(no->info.st_uid)))
				sizes[5] = ft_strlen(ft_llitoa(no->info.st_uid));
		}
		no = no->next;
	}
	return (sizes);
}

void				change_pointers(void **ptr1, void **ptr2)
{
	void			*tmp;

	tmp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = tmp;
}

void				change_nodes(t_node *no1, t_node *no2)
{
	char *tmp;

	change_pointers((void**)&(no1->data), (void**)&(no2->data));
	change_pointers((void**)&(no1->info), (void**)&(no2->info));
	change_pointers((void**)&(no1->linkinfo), (void**)&(no2->linkinfo));
	change_pointers((void**)&(no1->str), (void**)&(no2->str));
	tmp = ft_strdup(no1->name);
	no1->name = ft_strdup(no2->name);
	no2->name = tmp;
	change_pointers((void**)&(no1->path), (void**)&(no2->path));
}
