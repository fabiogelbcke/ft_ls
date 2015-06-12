/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/25 15:51:50 by fschuber          #+#    #+#             */
/*   Updated: 2015/06/12 20:09:36 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/Includes/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/xattr.h>
# include <time.h>
# include <stdio.h>
# include <errno.h>

typedef	struct			s_node
{
	struct dirent		*data;
	struct stat			info;
	struct s_node		*next;
	struct stat			linkinfo;
	char			*name;
	char			*path;
	char			*str;
	int			extattr;
}						t_node;

t_node					*sort_by_time_modified(t_node *list, t_node *temp);
t_node					*sort_ascii(t_node *list);
t_node					*invert_list(t_node *list);
t_node					*get_list(DIR *directory, char *dirname);
t_node					*sort_list(t_node *list, int *options);
int						print_list(t_node *list, int *options, char *path);
int						is_error(char *str, int *options);
int						*get_options(int ac, char **av);
void					print_long(t_node *no, long *sizes,
						   int *options, char *path);
void					print_lld(long long int n);
char					**get_dirs(DIR *directory, char *dirname,
							int items, int *options);
char					*ft_llitoa(long long int n);
char					**dirs_table(int ac, int *options, char **av);
void					ls_directory(char *name, int *options,
									int *has_printed);
void					ls_directories(char **dirs, int *options,
									int *has_printed);
void					print_errors(char **errors, int *has_printed);
void					print_files(t_node *list, int *options,
									int *has_printed);
void					print_dirs(int ac, char **dirs, int *options,
									int *has_printed);
void					sort_dirs(char **dirs, int *options);
void					put_spaces(int n);
t_node					*is_file(char *str, t_node *list, int *options, char **dirs);
long int				*get_sizes(t_node *current, int *options);
char					get_type(t_node *no, char *path);
void					change_nodes(t_node *no1, t_node *no2);
void					print_link(t_node *no, char *path);

#endif
