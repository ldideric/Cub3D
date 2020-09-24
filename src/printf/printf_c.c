/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_c.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 19:12:02 by ldideric      #+#    #+#                 */
/*   Updated: 2020/07/02 19:49:52 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printf_c(va_list ap, t_arg list)
{
	char	c;
	int		i;

	i = 0;
	c = (list.zero) ? '0' : ' ';
	list.width = (list.width - 1 > 0) ? list.width - 1 : 0;
	while (list.width > i && !list.minus)
	{
		ft_putchar(c);
		i++;
	}
	ft_putchar(va_arg(ap, int));
	while (list.width > i && list.minus)
	{
		ft_putchar(' ');
		i++;
	}
	return (i + 1);
}
