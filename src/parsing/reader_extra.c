/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reader_extra.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/24 18:37:06 by ldideric      #+#    #+#                 */
/*   Updated: 2020/09/24 19:09:12 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <extra.h>

void			rd_rgb(char *s, t_rgb *rgb)
{
	rgb->packed.r = (unsigned char)ft_atoi(s);
	while (*s != ',')
		s++;
	s++;
	rgb->packed.g = (unsigned char)ft_atoi(s);
	while (*s != ',')
		s++;
	s++;
	rgb->packed.b = (unsigned char)ft_atoi(s);
	while (ft_isdigit(*s) || *s == '.' || *s == '-')
		s++;
	rgb->packed.a = 0;
}

void			rd_ground_sky(char *s, t_base *b)
{
	if (*s == 'F')
	{
		while (*s == ' ' || ft_isalpha(*s) == 1)
			s++;
		rd_rgb(s, &b->floor);
	}
	else if (*s == 'C')
	{
		while (*s == ' ' || ft_isalpha(*s) == 1)
			s++;
		rd_rgb(s, &b->ceiling);
	}
}

void			rd_res(char *s, t_base *b)
{
	while (*s == ' ' || ft_isalpha(*s))
		s++;
	b->res.x_max = ft_atoi(s);
	while (ft_isdigit(*s))
		s++;
	while (*s == ' ')
		s++;
	b->res.y_max = ft_atoi(s);
}
