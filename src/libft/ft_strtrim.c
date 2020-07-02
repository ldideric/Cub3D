/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 16:31:48 by ldideric       #+#    #+#                */
/*   Updated: 2020/03/06 11:59:08 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		ft_isset(char c, const char *set)
{
	int i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char		*ft__strcpy(const char *src, char *dst, int j)
{
	int i;

	i = 0;
	while (src[i] != '\0' && j - 1 > i)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	if (!s1 || !set)
		return (ft_strdup(""));
	j = ft_strlen((char *)s1) - 1;
	while (s1[i] != '\0' && ft_isset(s1[i], set))
		i++;
	while (j > i && ft_isset(s1[j], set))
		j--;
	if (j - i > 0)
		str = malloc(sizeof(char) * (j - i + 2));
	else
		return (ft_strdup(""));
	if (!str)
		return (NULL);
	str = ft__strcpy(s1 + i, str, j - i + 2);
	str[j - i + 1] = '\0';
	return (str);
}
