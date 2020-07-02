/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 17:48:20 by ldideric       #+#    #+#                */
/*   Updated: 2020/03/06 11:59:08 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (s == NULL)
		return ((char *)ft_strlen(0));
	if ((unsigned char)c == '\0' && (unsigned char)s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		if (c == '\0' && (unsigned char)s[i + 1] == (unsigned char)c)
			return ((char *)&s[i + 1]);
		i++;
	}
	return (NULL);
}
