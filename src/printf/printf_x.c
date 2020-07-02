/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_x.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/07 13:48:42 by ldideric       #+#    #+#                */
/*   Updated: 2020/03/13 10:27:14 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int	printf_x_str(char *s, t_arg list)
{
	int i;

	i = 0;
	if (list.prec > (int)ft_strlen(s))
	{
		while (i < list.prec - (int)ft_strlen(s))
		{
			ft_putchar('0');
			i++;
		}
		while (s[i - (list.prec - (int)ft_strlen(s))] && i < list.prec)
		{
			ft_putchar(s[i - (list.prec - (int)ft_strlen(s))]);
			i++;
		}
	}
	else
		while (s[i])
		{
			ft_putchar(s[i]);
			i++;
		}
	return (i);
}

static int	printf_x_width(char *s, t_arg list)
{
	char	c;
	int		len;
	int		slen;

	slen = 0;
	len = 0;
	slen = (list.prec && list.prec > (int)ft_strlen(s))
	? list.prec : (int)ft_strlen(s);
	len = (list.width > slen) ? list.width - slen : 0;
	c = (list.zero && !list.prec) ? '0' : ' ';
	while (len > 0)
	{
		ft_putchar(c);
		len--;
	}
	len = (list.width > slen) ? list.width - slen : 0;
	return (len);
}

static int	printf_x_ext(va_list ap, t_arg list)
{
	char	*s;
	int		i;

	i = 0;
	s = ft_itoa_base(va_arg(ap, unsigned int), 16, (list.hex) ? 1 : 0);
	if (s == NULL)
		return (ft_freestr(s));
	s = (ft_strncmp(s, "0", 2) == 0 && list.prec) ? "" : s;
	i = (list.width && list.minus) ? i + printf_x_str(s, list)
	+ printf_x_width(s, list) : i;
	i = (list.width && !list.minus) ? i + printf_x_width(s, list)
	+ printf_x_str(s, list) : i;
	i = ((!list.width && !list.minus) || (!list.width && list.minus))
	? i + printf_x_str(s, list) : i;
	if (s[0] != '\0')
		free(s);
	return (i);
}

int			printf_x(va_list ap, t_arg list)
{
	char	*s;
	int		i;

	i = 0;
	if (list.prec || list.width)
		i = printf_x_ext(ap, list);
	else
	{
		s = ft_itoa_base(va_arg(ap, unsigned int), 16,
		(list.hex) ? 1 : 0);
		if (s == NULL)
			return (ft_freestr(s));
		while (s[i])
		{
			ft_putchar(s[i]);
			i++;
		}
		free(s);
	}
	return (i);
}
