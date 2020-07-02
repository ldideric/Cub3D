/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/06 10:41:54 by ldideric       #+#    #+#                */
/*   Updated: 2020/03/13 10:27:14 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static char	*itoa_base(char *str, long long a, int base)
{
	int i;

	i = ft_intchars(a, base) - 1;
	if (a == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (a < 0)
	{
		str[0] = '-';
		a = a * -1;
	}
	while (a >= base)
	{
		str[i] = (a % base >= 10) ? a % base + '7' : a % base + '0';
		a = a / base;
		i--;
	}
	if (a > 0)
		str[i] = (a >= 10) ? a + '7' : a + '0';
	return (str);
}

char		*ft_itoa_base(long long a, int base, int big)
{
	char	*str;
	int		i;

	i = ft_intchars(a, base) - 1;
	str = malloc(sizeof(char) * (i + 2));
	if (str == NULL)
		return (0);
	str[i + 1] = '\0';
	str = itoa_base(str, a, base);
	while (i >= 0 && big == 0)
	{
		str[i] = ft_tolower(str[i]);
		i--;
	}
	return (str);
}
