/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 14:27:23 by ldideric       #+#    #+#                */
/*   Updated: 2020/03/06 11:59:08 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		ft_charcnt(long n)
{
	int i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

char			*ft_itoa(int n)
{
	long	i;
	int		digits;
	char	*str;

	i = (long)n;
	digits = ft_charcnt(i);
	str = malloc(sizeof(char) * digits + 1);
	if (!str)
		return (NULL);
	str[digits] = '\0';
	digits--;
	if (i < 0)
	{
		str[0] = '-';
		i = -i;
	}
	while (i >= 10)
	{
		str[digits] = i % 10 + '0';
		i = i / 10;
		digits--;
	}
	str[digits] = i + '0';
	return (str);
}
