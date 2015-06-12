/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/25 15:51:50 by fschuber          #+#    #+#             */
/*   Updated: 2015/06/13 00:16:07 by fschuber         ###   ########.fr       */
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
	char				*name;
	char				*path;
	char				*str;
	int					extattr;
}						t_node;

t_node					*sort_by_time_modified(t_node *list, t_node *temp);
t_node					*sort_ascii(t_node *list);
t_node					*invert_list(t_node *list);
t_node					*get_list(DIR *directory, char *dirname, int *options);
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
t_node					*is_file(char *str, t_node *list,
								int *options, char **dirs);
long int				*get_sizes(t_node *no, int *options);
char					get_type(t_node *no, char *path);
void					change_nodes(t_node *no1, t_node *no2);
void					print_link(t_node *no, char *path);
void					add_dir(char *str, char **dirs);
void					ls_directory(char *name, int *options,
									int *has_printed);
void					print_lldendl(long long int n);
void					device_or_size(char c, t_node *no);
void					set_pointers(char **path, char **name,
									char **str, DIR **directory);
int						folder_condition(t_node *curr, int *options,
										char *str, char *path);
t_node					*add_to_end(t_node *list, t_node *ptr, t_node *curr);
t_node					*call_add_dir(char *str, char **dirs, t_node *list);
void					set_new(t_node *new, char *name, char *dirname,
								t_node **current);
void					set_size_5(t_node *no, long *size_5);
void					set_options(int *options, char c, int *j, char *str);
#endif
