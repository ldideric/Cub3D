/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_di.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 17:05:39 by ldideric       #+#    #+#                */
/*   Updated: 2020/03/13 10:27:14 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int	printf_di_str(char *s, t_arg list)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (list.prec > (int)ft_strlen(s))
	{
		ft_putchar('0');
		len++;
		list.prec--;
	}
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (len + i);
}

static int	printf_di_width(char *s, t_arg list)
{
	char	c;
	int		slen;
	int		len;
	int		i;

	i = 0;
	c = (list.zero && !list.prec) ? '0' : ' ';
	slen = (list.prec > (int)ft_strlen(s)) ? list.prec : ft_strlen(s);
	slen = (s[0] == '-' && list.prec >= (int)ft_strlen(s)) ? slen + 1 : slen;
	len = (list.width > slen) ? list.width - slen : 0;
	while (i < len)
	{
		ft_putchar(c);
		i++;
	}
	return (i);
}

static int	printf_di_ext(char *s, t_arg list, int i)
{
	if (list.minus)
	{
		ft_putchar('-');
		i++;
		i = i + printf_di_str(s + 1, list);
		i = i + printf_di_width(s, list);
	}
	else
	{
		if (list.zero && !list.prec)
		{
			ft_putchar('-');
			i++;
			i = i + printf_di_width(s, list);
			i = i + printf_di_str(s + 1, list);
		}
		else
		{
			i = i + printf_di_width(s, list);
			ft_putchar('-');
			i++;
			i = i + printf_di_str(s + 1, list);
		}
	}
	return (i);
}

int			printf_di(va_list ap, t_arg list)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_itoa_base(va_arg(ap, int), 10, 0);
	if (str == NULL)
		return (ft_freestr(str));
	str[0] = (str[0] == '0' && list.prec) ? '\0' : str[0];
	list.zero = (list.zero && list.minus) ? 0 : list.zero;
	if (str[0] != '-' && !list.minus)
	{
		i = i + printf_di_width(str, list);
		i = i + printf_di_str(str, list);
	}
	else if (str[0] != '-' && list.minus)
	{
		i = i + printf_di_str(str, list);
		i = i + printf_di_width(str, list);
	}
	else
		i = printf_di_ext(str, list, 0);
	if (str[0] != '\0')
		free(str);
	return (i);
}
