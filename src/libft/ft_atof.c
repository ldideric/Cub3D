/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atof.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/11 06:54:20 by ldideric       #+#    #+#                */
/*   Updated: 2020/03/13 14:28:28 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>

static double	atof_ext(char *c, const char *str, int len, int i)
{
	double res2;

	res2 = (double)ft_atoi(c);
	while (str[i] != '.')
		i++;
	i++;
	while (ft_isdigit(str[i + len]))
		len++;
	while (len > 0)
	{
		res2 /= 10;
		len--;
	}
	return (res2);
}

double			ft_atof(const char *str)
{
	double	res;
	double	res2;
	double	min;
	char	*c;

	if (str == NULL)
		return (0);
	c = (char *)str;
	while (*c == ' ' || *c == '\t')
		c++;
	min = (*c == '-') ? -1 : 1;
	res = (double)ft_atoi(c);
	while (*c && *c != '.' && *c != ',' && *c != ' ' && *c != '\t')
		c++;
	if (*c != '.')
		return (res);
	c++;
	res2 = atof_ext(c, str, 0, 0);
	return (min * (res + ((res >= 0) ? res2 : -res2)));
}
