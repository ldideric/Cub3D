/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 17:33:26 by ldideric       #+#    #+#                */
/*   Updated: 2020/03/06 11:59:08 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strrchr(const char *s, int c)
{
	int i;

	if (s == NULL)
		return ((char *)ft_strlen(0));
	i = (int)ft_strlen(s);
	if (c == '\0' && (unsigned char)s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	while (i >= 0)
	{
		if (c == '\0' && (unsigned char)s[i + 1] == (unsigned char)c)
			return ((char *)&s[i + 1]);
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
