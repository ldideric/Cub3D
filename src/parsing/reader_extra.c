/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reader_extra.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/24 18:37:06 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/24 17:30:32 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int			rd_sprites(char *s, t_base *b)
{
	char	**ptr;
	int		i;

	i = 0;
	ptr = (void *)0;
	ptr = (*(u_int16_t *)s == *(u_int16_t *)"NO") ? &b->tex[0].path : ptr;
	ptr = (*(u_int16_t *)s == *(u_int16_t *)"EA") ? &b->tex[1].path : ptr;
	ptr = (*(u_int16_t *)s == *(u_int16_t *)"SO") ? &b->tex[2].path : ptr;
	ptr = (*(u_int16_t *)s == *(u_int16_t *)"WE") ? &b->tex[3].path : ptr;
	ptr = (*(u_int16_t *)s == *(u_int16_t *)"S ") ? &b->tex[4].path : ptr;
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
	b->res.x = ft_atoi(s);
	if (b->res.x < 0)
		return (0);
	while (ft_isdigit(*s))
		s++;
	while (*s == ' ')
		s++;
	b->res.y = ft_atoi(s);
	if (b->res.y < 0)
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
