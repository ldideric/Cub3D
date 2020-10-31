/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reader_extra.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/24 18:37:06 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/31 21:45:33 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

char		**rd_ptr_ret(char *s, t_base *b, int spr)
{
	char	**p;

	p = NULL;
	if (spr == TRUE)
	{
		p = (*(u_int16_t *)s == *(u_int16_t *)"S ") ? &b->spr_img[0].path : p;
		p = (*(u_int16_t *)s == *(u_int16_t *)"S1") ? &b->spr_img[1].path : p;
		p = (*(u_int16_t *)s == *(u_int16_t *)"S2") ? &b->spr_img[2].path : p;
		p = (*(u_int16_t *)s == *(u_int16_t *)"S3") ? &b->spr_img[3].path : p;
		p = (*(u_int16_t *)s == *(u_int16_t *)"S4") ? &b->spr_img[4].path : p;
		p = (*(u_int16_t *)s == *(u_int16_t *)"S5") ? &b->spr_img[5].path : p;
		p = (*(u_int16_t *)s == *(u_int16_t *)"S6") ? &b->spr_img[6].path : p;
		p = (*(u_int16_t *)s == *(u_int16_t *)"S7") ? &b->spr_img[7].path : p;
		return (p);
	}
	p = (*(u_int16_t *)s == *(u_int16_t *)"NO") ? &b->tex_img[0].path : p;
	p = (*(u_int16_t *)s == *(u_int16_t *)"EA") ? &b->tex_img[1].path : p;
	p = (*(u_int16_t *)s == *(u_int16_t *)"SO") ? &b->tex_img[2].path : p;
	p = (*(u_int16_t *)s == *(u_int16_t *)"WE") ? &b->tex_img[3].path : p;
	return (p);
}

int			rd_spr(char *s, t_base *b)
{
	char	**ptr;
	int		i;

	i = 0;
	ptr = rd_ptr_ret(s, b, TRUE);
	if (s[i] != 'S')
		return (0);
	i++;
	if (s[i] != '\0')
	{
		if (!(s[i] == ' ' && s[i + i] != '\0') && !(s[i] >= '1' && s[i] <= '7' && s[i + 1] == ' '))
			return (0);
	}
	else
		return (0);
	i++;
	*ptr = ft_strtrim(s + i, " \n\t");
	return (*ptr != NULL);
}

int			rd_tex(char *s, t_base *b)
{
	char	**ptr;
	int		i;

	i = 0;
	ptr = rd_ptr_ret(s, b, FALSE);
	i++;
	i++;
	*ptr = ft_strtrim(s + i, " \n\t");
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
	b->is_res = 1;
	return (1);
}

int			rd_rgb(char *s, t_rgb *rgb)
{
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
	rgb->packed.a = 0;
	return (1);
}

int			rd_f_c(char *s, t_base *b)
{
	if (*s == 'F')
	{
		s++;
		while (*s == ' ')
		{
			if (*s == '\0')
				return (0);
			s++;
		}
		if (rd_rgb(s, &b->floor) == 1)
		{
			b->is_floor = 1;
			return (1);
		}
		return (0);
	}
	else if (*s == 'C')
	{
		s++;
		while (*s == ' ')
		{
			if (*s == '\0')
				return (0);
			s++;
		}
		if (rd_rgb(s, &b->ceiling) == 1)
		{
			b->is_ceiling = 1;
			return (1);
		}
		return (0);
	}
	return (0);
}
