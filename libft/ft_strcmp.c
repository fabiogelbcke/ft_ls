/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 04:17:28 by fschuber          #+#    #+#             */
/*   Updated: 2014/11/28 19:41:33 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int					ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char*)s1;
	ptr2 = (unsigned char*)s2;
	while (*ptr1 && *ptr2)
	{
		if (*ptr1 != *ptr2)
			return (*ptr1 - *ptr2);
		ptr1++;
		ptr2++;
	}
	return (*ptr1 - *ptr2);
}
