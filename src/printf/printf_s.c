/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_s.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 02:51:47 by ldideric       #+#    #+#                */
/*   Updated: 2020/03/13 10:27:14 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int	printf_s_str(char *s, t_arg list)
{
	int i;

	i = 0;
	if (list.prec)
		while (s[i] && i < list.prec)
		{
			ft_putchar(s[i]);
			i++;
		}
	else
	{
		while (s[i])
		{
			ft_putchar(s[i]);
			i++;
		}
	}
	return (i);
}

static int	printf_s_width(char *s, t_arg list, char c)
{
	int len;
	int slen;

	slen = ft_strlen(s);
	if (list.prec)
		list.intprec = (list.prec < slen) ? list.prec :
		slen;
	len = (list.intprec < slen && list.prec) ? list.width
	- list.intprec : list.width - slen;
	len = (list.prec == -1) ? list.width : len;
	while (len > 0)
	{
		ft_putchar(c);
		len--;
	}
	len = (list.intprec < slen && list.prec) ?
	list.width - list.intprec : list.width - slen;
	len = (list.prec == -1) ? list.width : len;
	len = (len > 0) ? len : 0;
	return (len);
}

int			printf_s(va_list ap, t_arg list)
{
	char	*s;
	int		i;
	char	c;

	i = 0;
	c = (list.zero) ? '0' : ' ';
	list.intprec = 0;
	s = va_arg(ap, char *);
	s = (s == NULL) ? "(null)" : s;
	i = (list.width && list.minus) ? i + printf_s_str(s, list)
	+ printf_s_width(s, list, c) : i;
	i = (list.width && !list.minus) ? i + printf_s_width(s, list, c)
	+ printf_s_str(s, list) : i;
	i = ((!list.width && !list.minus) || (!list.width && list.minus))
	? i + printf_s_str(s, list) : i;
	return (i);
}
