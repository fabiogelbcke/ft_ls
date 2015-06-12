/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/25 16:15:58 by fschuber          #+#    #+#             */
/*   Updated: 2015/06/09 21:18:51 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_node				*get_list(DIR *directory, char *dirname)
{
	t_node			*head;
	t_node			*new;
	struct dirent	*entry;
	t_node			*current;
	char			buf[1024];

	current = NULL;
	while (directory && (entry = readdir(directory)))
	{
		new = malloc(sizeof(t_node));
		if (current)
			current->next = new;
		else
			head = new;
		new->next = NULL;
		new->name = entry->d_name;
		new->path = NULL;
		new->str = NULL;
		new->data = entry;
		current = new;
		new->extattr = (listxattr(ft_strjoin(dirname, entry->d_name), buf, 1024, XATTR_NOFOLLOW) > 0) ? 1 : 0;
		if (lstat((ft_strjoin(dirname, entry->d_name)), &(current->info)) < 0)
		{
			perror("");
			exit(1);
		}
		stat(ft_strjoin(dirname, entry->d_name), &(current->linkinfo));
	}
	if (directory)
		head = sort_ascii(head);
	return (directory) ? (head) : NULL;
}

t_node				*sort_by_time_modified(t_node *list, t_node *temp)
{
	t_node			*current;
	t_node			*prev;

	current = list;
	prev = NULL;
	while (current && current->next != NULL)
		if (current->info.st_mtimespec.tv_sec
			< current->next->info.st_mtimespec.tv_sec)
		{
			if (prev)
				prev->next = current->next;
			else
				list = current->next;
			temp = current->next;
			current->next = current->next->next;
			temp->next = current;
			current = list;
			prev = NULL;
		}
		else
		{
			current = current->next;
			prev = (prev) ? prev->next : list;
		}
	return (list);
}

t_node				*sort_ascii(t_node *list)
{
	t_node			*current;
	t_node			*prev;
	t_node			*temp;

	current = list;
	prev = NULL;
	while (current->next != NULL)
		if (ft_strcmp(current->name,
				current->next->name) > 0)
		{
			if (prev)
				prev->next = current->next;
			else
				list = current->next;
			temp = current->next;
			current->next = current->next->next;
			temp->next = current;
			current = list;
			prev = NULL;
		}
		else
		{
			current = current->next;
			prev = (prev) ? prev->next : list;
		}
	return (list);
}

t_node				*invert_list(t_node *list)
{
	t_node			*current;
	t_node			*prev;
	t_node			*next;

	prev = NULL;
	current = list;
	next = list->next;
	while (current)
	{
		current->next = prev;
		prev = current;
		current = next;
		if (next)
			next = next->next;
	}
	list = prev;
	return (list);
}

int					print_list(t_node *list, int *options, char *path)
{
	t_node			*current;
	long int		size_links;
	long int		size_size;
	quad_t			total_blocks;
	int				no;
	long int		*sizes;

	size_links = 0;
	size_size = 0;
	current = list;
	total_blocks = 0;
	no = 0;
	sizes = get_sizes(current, options);
	if (options[0] && (current->next->next || options[2] == 1))
	{
		ft_putstr("total ");
		print_lld(sizes[2]);
		ft_putstr("\n");
	}
	while (current)
	{
		if ((current->name)[0] != '.' || options[2] == 1)
		{
//			if (options[5] == 1)
			if (!options[0])
			{
				ft_putstr(current->name);
				ft_putstr("\n");
			}

			else
				print_long(current, sizes, options, path);
		}
		current = current->next;
		no++;
	}
	return (no);
}
