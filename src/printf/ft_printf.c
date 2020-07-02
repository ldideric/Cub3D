/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 15:40:13 by ldideric       #+#    #+#                */
/*   Updated: 2020/03/13 10:27:14 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int	ft_makestr(char *format, va_list ap, int len, int i)
{
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			len++;
			ft_putchar(format[i]);
			i++;
		}
		else if (format[i] == '%')
		{
			len = len + ft_flags(format + i, ap);
			i++;
			while (format[i] == '-' || format[i] == '.' ||
			format[i] == '*' || ft_isdigit(format[i]))
				i++;
			i = (ft_isalpha(format[i]) == 1 || format[i] == '%') ? i + 1 : i;
		}
	}
	return (len);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	int			len;

	va_start(ap, format);
	len = ft_makestr((char *)format, ap, 0, 0);
	va_end(ap);
	return (len);
}
