/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 22:48:53 by fschuber          #+#    #+#             */
/*   Updated: 2015/06/12 23:50:24 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	set_pointers(char **path, char **name, char **str, DIR **directory)
{
	(*path) = ft_strdup((*str));
	(*name) = ft_strdup((*str));
	if (strrchr((*path), '/'))
	{
		(*name) = strrchr((*path), '/');
		*((*name)++) = '\0';
		(*path) = ft_strjoin((*path), "/");
	}
	else
		(*path) = ft_strdup(".");
	(*directory) = opendir((*path));
}

int		folder_condition(t_node *curr, int *options, char *str, char *path)
{
	curr->path = path;
	curr->str = ft_strdup(str);
	if (options[0] == 0 && (curr->linkinfo.st_mode & S_IFDIR))
		return (1);
	if (opendir(str) && curr->data->d_type == DT_DIR)
		return (1);
	return (0);
}

t_node	*add_to_end(t_node *list, t_node *ptr, t_node *curr)
{
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = curr;
		curr->next = NULL;
		return (ptr);
	}
	else
	{
		list = curr;
		list->next = NULL;
		return (list);
	}
}

t_node	*call_add_dir(char *str, char **dirs, t_node *list)
{
	add_dir(str, dirs);
	return (list);
}

void	set_new(t_node *new, char *name, char *dirname, t_node **current)
{
	char buf[1024];

	new->next = NULL;
	new->name = ft_strdup(name);
	new->path = NULL;
	new->str = NULL;
	new->extattr = (listxattr(ft_strjoin(dirname, name)
							, buf, 1024, XATTR_NOFOLLOW) > 0) ? 1 : 0;
	*current = new;
}
