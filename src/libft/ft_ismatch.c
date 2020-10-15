/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ismatch.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/15 20:05:41 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/15 20:17:41 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_ismatch(char c, char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}
