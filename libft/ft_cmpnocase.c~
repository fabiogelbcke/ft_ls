#include "libft.h"

int ft_cmpnocase(char *s1, char *s2)
{
	while(*s1 && *s2)
	{
		if (ft_toupper(*s1) != ft_toupper(*s2))
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
