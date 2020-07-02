/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_flags.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 01:38:37 by ldideric       #+#    #+#                */
/*   Updated: 2020/03/13 10:27:14 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static t_spec	ft_specifier(char c)
{
	static const t_spec spec[128] = {
		['c'] = &printf_c,
		['s'] = &printf_s,
		['p'] = &printf_p,
		['d'] = &printf_di,
		['i'] = &printf_di,
		['u'] = &printf_u,
		['x'] = &printf_x,
		['X'] = &printf_x,
		['%'] = &printf_per,
	};

	return (spec[(int)c]);
}

static int		ft_flagwp(char *str, t_arg *list, int a)
{
	int i;

	i = 0;
	if (a == 0)
	{
		list[0].intprec = (str[i] == '*') ? 1 : list[0].intprec;
		list[0].prec = (ft_atoi(str + i) > 0 && ft_isdigit(str[i]) == 1)
		? ft_atoi(str + i) : -1;
		i = (ft_isdigit(str[i]) == 1) ? ft_numlen(str + i) - 1 : i;
		list[0].prec = (str[i] != '*' && ft_isdigit(str[i]) == 0)
		? -1 : list[0].prec;
		i = (str[i] != '*' && ft_isdigit(str[i]) == 0) ? i - 1 : i;
		return (i + 2);
	}
	list[0].intwidth = (str[i] == '*') ? 1 : list[0].intwidth;
	list[0].width = (ft_atoi(str + i) > 0 && ft_isdigit(str[i]) == 1)
	? ft_atoi(str + i) : -1;
	i = (ft_isdigit(str[i]) == 1) ? ft_numlen(str + i) - 1 : i;
	list[0].width = (str[i] != '*' && ft_isdigit(str[i]) == 0)
	? -1 : list[0].width;
	i = (str[i] != '*' && ft_isdigit(str[i]) == 0) ? i - 1 : i;
	return (i + 1);
}

static t_arg	ft_flagcheck(char *str, t_arg list)
{
	int i;

	i = 0;
	if (str[i] == '0')
	{
		list.zero = 1;
		i++;
	}
	if (str[i] == '-')
	{
		list.minus = 1;
		i++;
	}
	if (ft_isdigit(str[i]) || str[i] == '*')
		i = i + ft_flagwp(str + i, &list, 1);
	if (str[i] == '.')
		i = i + ft_flagwp(str + i + 1, &list, 0);
	return (list);
}

static t_arg	ft_prewid(t_arg list, va_list ap)
{
	if (list.intwidth)
	{
		list.width = va_arg(ap, int);
		if (list.width < 0)
		{
			list.width = -list.width;
			list.minus = 1;
		}
		else if (list.width == 0)
			list.width = -1;
	}
	if (list.intprec)
	{
		list.prec = va_arg(ap, int);
		if (list.prec == 0)
			list.prec = -1;
		else if (list.prec < 0)
			list.prec = 0;
	}
	return (list);
}

int				ft_flags(char *str, va_list ap)
{
	int		i;
	t_arg	*list;
	t_spec	spec;

	i = 1;
	list = ft_argnew();
	if (ft_isalpha(str[i]) == 0)
		*list = ft_flagcheck(str + i, *list);
	while (str[i] == '-' || str[i] == '.' ||
	str[i] == '*' || ft_isdigit(str[i]))
		i++;
	list[0].hex = (str[i] == 'X') ? 1 : list[0].hex;
	*list = ft_prewid(*list, ap);
	if (ft_isalpha(str[i]) || str[i] == '%')
	{
		spec = ft_specifier(str[i]);
		if (spec == NULL)
			return (ft_freestruct(list));
	}
	else
		return (ft_freestruct(list));
	i = spec(ap, *list);
	free(list);
	return (i);
}
