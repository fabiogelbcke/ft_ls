/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/25 16:15:58 by fschuber          #+#    #+#             */
/*   Updated: 2015/06/12 21:57:56 by fschuber         ###   ########.fr       */
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
		new = (t_node*)malloc(sizeof(t_node));
		if (current)
			current->next = new;
		else
			head = new;
		new->next = NULL;
		new->name = ft_strdup(entry->d_name);
		new->path = NULL;
		new->str = NULL;
		new->data = entry;
		current = new;
		new->extattr = (listxattr(ft_strjoin(dirname, entry->d_name)
					, buf, 1024, XATTR_NOFOLLOW) > 0) ? 1 : 0;
		if (lstat((ft_strjoin(dirname, entry->d_name)), &(current->info)) < 0)
		{
			perror("");
			exit(1);
		}
		stat(ft_strjoin(dirname, entry->d_name), &(current->linkinfo));
	}
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
	t_node			*curr;
	t_node			*prev;
	t_node			*temp;

	curr = list;
	prev = NULL;
	while (curr->next != NULL)
		if (ft_strcmp(curr->name, curr->next->name) > 0)
		{
			if (prev)
				prev->next = curr->next;
			else
				list = curr->next;
			temp = curr->next;
			curr->next = curr->next->next;
			temp->next = curr;
			curr = list;
			prev = NULL;
		}
		else
		{
			prev = curr;
			curr = curr->next;
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
	int				no;
	long int		*sizes;

	no = 0;
	sizes = get_sizes(list, options);
	if ((options[0] && (list->next->next || options[2])) || options[5])
	{
		ft_putstr("total ");
		print_lldendl(sizes[2]);
	}
	while (list)
	{
		if ((list->name)[0] != '.' || (options[2] == 1))
		{
			if (options[5])
				ft_putstr(ft_strjoin(ft_itoa(list->info.st_blocks), " "));
			if (!options[0])
				ft_putendl(list->name);
			else
				print_long(list, sizes, options, path);
		}
		list = list->next;
		no++;
	}
	return (no);
}
