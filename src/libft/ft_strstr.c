/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/22 21:26:48 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/22 21:28:41 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (haystack == NULL || needle == NULL)
		return ((char *)ft_strlen(0));
	if (!needle || needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		while (haystack[i] == needle[j] && haystack[i] != '\0')
		{
			if (needle[j + 1] == '\0' && haystack[i] != '\0')
				return ((char *)&haystack[i - ft_strlen(needle) + 1]);
			j++;
			i++;
		}
		i = i - j + 1;
		j = 0;
	}
	return (NULL);
}
