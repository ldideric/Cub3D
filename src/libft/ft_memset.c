/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/06 16:24:03 by ldideric      #+#    #+#                 */
/*   Updated: 2020/04/06 16:24:06 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*new;

	i = 0;
	if (len == 0)
		return (b);
	new = b;
	while (i < len)
	{
		new[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
