/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 12:03:55 by ldideric       #+#    #+#                */
/*   Updated: 2020/03/06 11:59:08 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(size * count);
	if (!str)
		return (NULL);
	while ((unsigned long)i < (size * count))
	{
		str[i] = '\0';
		i++;
	}
	return (&str[0]);
}
