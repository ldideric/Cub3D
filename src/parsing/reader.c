/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reader.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/02 18:57:52 by ldideric      #+#    #+#                 */
/*   Updated: 2020/09/23 21:03:02 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <extra.h>

void			rd_res(char *s, t_base *b, char *type)
{
	while (*s == ' ' || ft_isalpha(*s))
		s++;
	b->res.x_max = ft_atoi(s);
	while (*s == ' ')
		s++;
	b->res.y_max = ft_atoi(s);
}

void			rd_ground_sky(char *s, t_base *b, char *type)
{
	
}

void			rd_sprites(char *s, t_base *b, char *type)
{
	int i;

	i = 0;
	while (ft_isalpha(s[i]))
		i++;
	while (s[i] == ' ')
		i++;
	
}

static void		specifier(char *s, t_base *b)
{
	static const t_read spec[128] = {
		['1'] = &rd_sprites,
		['2'] = &rd_res,
		['3'] = &rd_ground_sky,
	};

	(*(u_int16_t *)s == *(u_int16_t *)"NO") ? spec['1'](s, b, "no") : NULL;
	(*(u_int16_t *)s == *(u_int16_t *)"EA") ? spec['1'](s, b, "ea") : NULL;
	(*(u_int16_t *)s == *(u_int16_t *)"SO") ? spec['1'](s, b, "so") : NULL;
	(*(u_int16_t *)s == *(u_int16_t *)"WE") ? spec['1'](s, b, "we") : NULL;
	(*(u_int16_t *)s == *(u_int16_t *)"S ") ? spec['1'](s, b, "s ") : NULL;
	(*(u_int16_t *)s == *(u_int16_t *)"R ") ? spec['2'](s, b, "r") : NULL;
	(*(u_int16_t *)s == *(u_int16_t *)"F ") ? spec['3'](s, b, "f") : NULL;
	(*(u_int16_t *)s == *(u_int16_t *)"C ") ? spec['3'](s, b, "c") : NULL;
}

void			reader(t_base *b)
{
	char	*temp;
	char	*s;
	int		fd;

	temp = malloc(1);
	temp[0] = '\0';
	fd = open(b->file, O_RDONLY);
	while (get_next_line(fd, &s) != 0)
	{
		if (ft_isalpha(s[0]) == 1)
			specifier(s, b);
		else if (ft_isdigit(s[0]) == 1 || ft_isprint(s[0]) == 0)
		{
			b->map = ft_strjoin(temp, s);
			free(temp);
			temp = b->map;
		}
	}
}
