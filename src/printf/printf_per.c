/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_per.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 14:42:02 by ldideric       #+#    #+#                */
/*   Updated: 2020/03/13 10:27:14 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int			printf_per(va_list ap, t_arg list)
{
	int		len;
	char	c;

	if (ap->fp_offset)
		len = 0;
	c = (list.zero && !list.minus) ? '0' : ' ';
	len = 0;
	if (list.minus)
		ft_putchar('%');
	if (list.width)
		while (len < list.width - 1)
		{
			ft_putchar(c);
			len++;
		}
	if (!list.minus)
		ft_putchar('%');
	return (len + 1);
}
