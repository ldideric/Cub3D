/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 18:43:08 by ldideric       #+#    #+#                */
/*   Updated: 2020/03/13 10:27:14 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

t_arg		*ft_argnew(void)
{
	t_arg *new;

	new = malloc(sizeof(t_arg));
	if (!new)
		return (NULL);
	new->intprec = 0;
	new->intwidth = 0;
	new->minus = 0;
	new->prec = 0;
	new->width = 0;
	new->zero = 0;
	new->hex = 0;
	return (new);
}

int			ft_numlen(char *str)
{
	int i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}

int			ft_intchars(long long a, int base)
{
	int i;

	i = 0;
	if (a < 0)
	{
		a = -a;
		i++;
	}
	while (a / base > 0)
	{
		a = a / base;
		i++;
	}
	if (a > 0 && a < base)
		i++;
	i = (a == 0) ? 1 : i;
	return (i);
}

int			ft_freestruct(t_arg *list)
{
	free(list);
	return (0);
}

int			ft_freestr(char *s)
{
	free(s);
	return (0);
}
