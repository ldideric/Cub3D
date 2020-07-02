/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_p.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/07 13:45:17 by ldideric       #+#    #+#                */
/*   Updated: 2020/03/13 10:27:14 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int	printf_p_width(t_arg list, char *s)
{
	int	len;
	int i;

	i = 0;
	len = (list.width > (int)ft_strlen(s) + 2) ?
	list.width - ((int)ft_strlen(s) + 2) : 0;
	while (len > 0)
	{
		ft_putchar(' ');
		i++;
		len--;
	}
	return (i);
}

static int	printf_p_str(char *s, t_arg list)
{
	int	i;
	int	len;

	i = 0;
	len = (list.prec > (int)ft_strlen(s)) ? list.prec - (int)ft_strlen(s) : 0;
	while (i < len)
	{
		ft_putchar('0');
		i++;
	}
	while (s[i - len])
	{
		ft_putchar(s[i - len]);
		i++;
	}
	return (i);
}

int			printf_p(va_list ap, t_arg list)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = 0;
	str = ft_ultoa_base(va_arg(ap, unsigned long), 16, 0);
	if (str == NULL)
		return (ft_freestr(str));
	if (ft_strncmp(str, "0", 3) == 0 && list.prec < 0)
	{
		free(str);
		str = "\0";
	}
	if (list.width && !list.minus)
		len = len + printf_p_width(list, str);
	ft_putstr("0x");
	len = len + 2;
	len = len + printf_p_str(str, list);
	if (list.width && list.minus)
		len = len + printf_p_width(list, str);
	if (str[0] != '\0')
		free(str);
	return (i + len);
}
