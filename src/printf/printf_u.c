/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_u.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/07 13:47:07 by ldideric       #+#    #+#                */
/*   Updated: 2020/03/13 10:27:14 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int	printf_u_str(char *s, t_arg list)
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

static int	printf_u_width(char *s, t_arg list)
{
	char	c;
	int		slen;
	int		len;
	int		i;

	i = 0;
	c = (list.zero && !list.prec) ? '0' : ' ';
	slen = (list.prec > (int)ft_strlen(s)) ? list.prec : ft_strlen(s);
	slen = (s[0] == '-' && list.prec > (int)ft_strlen(s)) ? slen + 1 : slen;
	len = (list.width > slen) ? list.width - slen : 0;
	while (i < len)
	{
		ft_putchar(c);
		i++;
	}
	return (i);
}

static int	printf_u_ext(char *s, t_arg list, int i)
{
	if (list.minus)
	{
		i = i + printf_u_str(s, list);
		i = i + printf_u_width(s, list);
	}
	else
	{
		i = i + printf_u_width(s, list);
		i = i + printf_u_str(s, list);
	}
	return (i);
}

int			printf_u(va_list ap, t_arg list)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_itoa_base(va_arg(ap, unsigned int), 10, 0);
	if (str == NULL)
		return (ft_freestr(str));
	str[0] = (str[0] == '0' && list.prec) ? '\0' : str[0];
	i = printf_u_ext(str, list, 0);
	free(str);
	return (i);
}
