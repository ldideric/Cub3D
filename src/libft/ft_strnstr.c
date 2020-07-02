/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 13:26:34 by ldideric       #+#    #+#                */
/*   Updated: 2020/03/06 11:59:08 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (haystack == NULL || needle == NULL)
		return ((char *)ft_strlen(0));
	if (!needle || needle[0] == '\0')
		return ((char *)haystack);
	if (haystack == needle && ft_strlen(needle) < len)
		return ((char *)&haystack[0]);
	while (i < len && haystack[i] != '\0')
	{
		while (haystack[i] == needle[j] && haystack[i] != '\0')
		{
			if (needle[j + 1] == '\0' && i < len && haystack[i] != '\0')
				return ((char *)&haystack[i - ft_strlen(needle) + 1]);
			j++;
			i++;
		}
		i = i - j + 1;
		j = 0;
	}
	return (NULL);
}
