/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reader_extra.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/24 18:37:06 by ldideric      #+#    #+#                 */
/*   Updated: 2020/09/25 15:36:25 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <extra.h>

int			rd_sprites(char *s, t_base *b)
{
	char	**ptr;
	int		i;

	i = 0;
	ptr = (void *)0;
	ptr = (*(u_int16_t *)s == *(u_int16_t *)"NO") ? &b->sprites.no : ptr;
	ptr = (*(u_int16_t *)s == *(u_int16_t *)"EA") ? &b->sprites.ea : ptr;
	ptr = (*(u_int16_t *)s == *(u_int16_t *)"SO") ? &b->sprites.so : ptr;
	ptr = (*(u_int16_t *)s == *(u_int16_t *)"WE") ? &b->sprites.we : ptr;
	ptr = (*(u_int16_t *)s == *(u_int16_t *)"S ") ? &b->sprites.s : ptr;
	while (ft_isalpha(s[i]))
		i++;
	while (s[i] == ' ')
		i++;
	*ptr = ft_substr(s, i, 255);
	return (*ptr != NULL);
}

int			rd_res(char *s, t_base *b)
{
	while (*s == ' ' || ft_isalpha(*s))
		s++;
	if (int_checker(ft_atoi(s), 3840) == 1)
		b->res.x_max = ft_atoi(s);
	else
		return (0);
	while (ft_isdigit(*s))
		s++;
	while (*s == ' ')
		s++;
	if (int_checker(ft_atoi(s), 3840) == 1)
		b->res.y_max = ft_atoi(s);
	else
		return (0);
	return (1);
}

int			rd_rgb(char *s, t_rgb *rgb)
{
	if (int_checker(ft_atoi(s), 255) == 1)
		rgb->packed.r = (unsigned char)ft_atoi(s);
	else
		return (0);
	while (*s != ',')
		s++;
	s++;
	if (int_checker(ft_atoi(s), 255) == 1)
		rgb->packed.g = (unsigned char)ft_atoi(s);
	else
		return (0);
	while (*s != ',')
		s++;
	s++;
	if (int_checker(ft_atoi(s), 255) == 1)
		rgb->packed.b = (unsigned char)ft_atoi(s);
	else
		return (0);
	while (ft_isdigit(*s) || *s == '.' || *s == '-')
		s++;
	rgb->packed.a = 0;
	return (1);
}

int			rd_ground_sky(char *s, t_base *b)
{
	if (*s == 'F')
	{
		while (*s == ' ' || ft_isalpha(*s) == 1)
			s++;
		return (rd_rgb(s, &b->floor));
	}
	else if (*s == 'C')
	{
		while (*s == ' ' || ft_isalpha(*s) == 1)
			s++;
		return (rd_rgb(s, &b->ceiling));
	}
	return (0);
}
