/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reader.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/02 18:57:52 by ldideric      #+#    #+#                 */
/*   Updated: 2020/09/24 22:21:16 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <extra.h>

void			rd_sprites(char *s, t_base *b)
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
}

static void		specifier(char *s, t_base *b)
{
	static const t_read spec[128] = {
		['1'] = &rd_sprites,
		['2'] = &rd_res,
		['3'] = &rd_ground_sky,
	};

	(*(u_int16_t *)s == *(u_int16_t *)"NO") ? spec['1'](s, b) : NULL;
	(*(u_int16_t *)s == *(u_int16_t *)"EA") ? spec['1'](s, b) : NULL;
	(*(u_int16_t *)s == *(u_int16_t *)"SO") ? spec['1'](s, b) : NULL;
	(*(u_int16_t *)s == *(u_int16_t *)"WE") ? spec['1'](s, b) : NULL;
	(*(u_int16_t *)s == *(u_int16_t *)"S ") ? spec['1'](s, b) : NULL;
	(*(u_int16_t *)s == *(u_int16_t *)"R ") ? spec['2'](s, b) : NULL;
	(*(u_int16_t *)s == *(u_int16_t *)"F ") ? spec['3'](s, b) : NULL;
	(*(u_int16_t *)s == *(u_int16_t *)"C ") ? spec['3'](s, b) : NULL;
}

static void		rd_map(t_base *b, int fd, char **s)
{
	int		i;

	i = 1;
	b->map = malloc(sizeof(char **) * 2);
	b->map[0] = ft_strdup(*s);
	b->map[1] = "\0";
	free(*s);
	while (get_next_line(fd, s) != 0)
	{
		b->map = ft_realloc_arr(b->map);
		b->map[i] = ft_strdup(*s);
		b->map[i + 1] = "\0";
		free(*s);
		i++;
	}
}

void			*reader(t_base *b, char *s, int fd, int ret)
{
	while (ret != 0)
	{
		if (ft_isalpha(s[0]) == 1)
			specifier(s, b);
		else if (ft_isdigit(s[0]) == 1 || s[0] == ' ')
		{
			rd_map(b, fd, &s);
			break ;
		}
		free(s);
		ret = get_next_line(fd, &s);
		if (ret == -1)
			return (errors(ERR_IN_GNL));
	}
	free(s);
	return (NULL);
}

void			*rd_start(t_base *b)
{
	char	*s;
	int		fd;
	int		ret;

	ret = 0;
	fd = open(b->file, O_RDONLY);
	ret = get_next_line(fd, &s);
	if (ret == -1)
		return (errors(ERR_IN_GNL));
	reader(b, s, fd, ret);
	return (NULL);
}
