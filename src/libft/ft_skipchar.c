/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_skipchar.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 17:29:16 by ldideric      #+#    #+#                 */
/*   Updated: 2020/11/02 20:58:50 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		str_len_skipchar(char *s, char c)
{
	int len;
	int i;

	i = 0;
	len = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			len++;
		i++;
	}
	return (ft_strlen(s) - len + 1);
}

char			*ft_skipchar(char *s, char c)
{
	char	*new;
	int		j;
	int		i;

	i = 0;
	j = 0;
	new = malloc(sizeof(char) * str_len_skipchar(s, c));
	if (new == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			new[j] = s[i];
			j++;
		}
		i++;
	}
	new[j] = '\0';
	return (new);
}
