/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reader_res_f_c.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 20:50:56 by ldideric      #+#    #+#                 */
/*   Updated: 2020/11/02 20:56:35 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	rd_res_ext(char *s, t_base *b)
{
	b->res.y = ft_atoi(s);
	if (b->res.y <= 0)
		return (0);
	while (ft_isdigit(*s))
	{
		s++;
		b->is_res++;
	}
	if (b->is_res > 6)
		return (0);
	b->is_res = 1;
	while (*s == ' ')
		s++;
	if (*s != '\0')
		return (0);
	return (1);
}

int			rd_res(char *s, t_base *b)
{
	s++;
	while (*s == ' ')
		s++;
	if (!ft_isdigit(*s))
		return (0);
	b->res.x = ft_atoi(s);
	if (b->res.x <= 0)
		return (0);
	while (ft_isdigit(*s))
	{
		s++;
		b->is_res++;
	}
	if (b->is_res > 6)
		return (0);
	b->is_res = 0;
	while (*s == ' ')
		s++;
	if (!ft_isdigit(*s))
		return (0);
	return (rd_res_ext(s, b));
}

static int	rd_rgb_ext(char *s, t_rgb *rgb)
{
	while (*s != ',')
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	s++;
	if (!ft_isdigit(*s) || (ft_atoi(s) < 0 || ft_atoi(s) > 255))
		return (0);
	rgb->packed.b = (unsigned char)ft_atoi(s);
	while (ft_isdigit(*s))
		s++;
	if (*s != '\0')
		return (0);
	rgb->packed.a = 0;
	return (1);
}

int			rd_rgb(char *s, t_rgb *rgb)
{
	s++;
	if (*s == '\0')
		return (0);
	if (!ft_isdigit(*s) || (ft_atoi(s) < 0 || ft_atoi(s) > 255))
		return (0);
	rgb->packed.r = (unsigned char)ft_atoi(s);
	while (*s != ',')
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	s++;
	if (!ft_isdigit(*s) || (ft_atoi(s) < 0 || ft_atoi(s) > 255))
		return (0);
	rgb->packed.g = (unsigned char)ft_atoi(s);
	return (rd_rgb_ext(s, rgb));
}

int			rd_f_c(char *s, t_base *b)
{
	s = ft_skipchar(s, ' ');
	if (*s == 'F' && b->is_floor == 0)
	{
		if (rd_rgb(s, &b->floor) == 1)
		{
			b->is_floor = 1;
			free(s);
			return (1);
		}
		return (0);
	}
	else if (*s == 'C' && b->is_ceiling == 0)
	{
		if (rd_rgb(s, &b->ceiling) == 1)
		{
			b->is_ceiling = 1;
			free(s);
			return (1);
		}
		return (0);
	}
	return (0);
}
