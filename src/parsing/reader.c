/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reader.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/02 18:57:52 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/02 01:53:55 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <extra.h>

static int		specifier(char *s, t_base *b)
{
	static const t_read	spec[128] = {
		['1'] = &rd_sprites,
		['2'] = &rd_res,
		['3'] = &rd_ground_sky,
	};

	return (((*(u_int16_t *)s == *(u_int16_t *)"NO") && spec['1'](s, b)) ||
			((*(u_int16_t *)s == *(u_int16_t *)"EA") && spec['1'](s, b)) ||
			((*(u_int16_t *)s == *(u_int16_t *)"SO") && spec['1'](s, b)) ||
			((*(u_int16_t *)s == *(u_int16_t *)"WE") && spec['1'](s, b)) ||
			((*(u_int16_t *)s == *(u_int16_t *)"S ") && spec['1'](s, b)) ||
			((*(u_int16_t *)s == *(u_int16_t *)"R ") && spec['2'](s, b)) ||
			((*(u_int16_t *)s == *(u_int16_t *)"F ") && spec['3'](s, b)) ||
			((*(u_int16_t *)s == *(u_int16_t *)"C ") && spec['3'](s, b)));
}

static int		rd_map_alloc(char ***map, char *s, int start, int i)
{
	if (start == TRUE)
		*map = malloc(sizeof(char **) * 2);
	else
		*map = ft_realloc_arr(*map);
	if (*map == NULL)
		return (errors(ERR_MALLOC));
	*map[i] = ft_strdup(s);
	if (*map[i] == NULL)
		return (errors(ERR_MALLOC));
	*map[i + 1][0] = '\0';
	return (1);
}

static int		rd_map(t_base *b, int fd, char **s)
{
	int		ret;
	int		i;

	i = 1;
	ret = 1;
	if (rd_map_alloc(&b->map, *s, TRUE, 0) == 0)
		return (0);
	free(*s);
	while (ret > 0)
	{
		ret = get_next_line(fd, s);
		if (ret == -1)
			return (errors(ERR_IN_GNL));
		if (rd_map_alloc(&b->map, *s, FALSE, i) == 0)
			return (0);
		free((ret > 0) ? *s : NULL);
		i++;
	}
	return (1);
}

static int		reader(t_base *b, char *s, int fd, int ret)
{
	while (ret > 0)
	{
		if (ft_isalpha(s[0]) == 1)
		{
			if (!specifier(s, b))
				return (rd_struct_free(s, b));
		}
		else if (ft_isdigit(s[0]) == 1 || s[0] == ' ')
		{
			if (!rd_map(b, fd, &s))
				return (0);
			break ;
		}
		free(s);
		ret = get_next_line(fd, &s);
		if (ret == -1)
			return (errors(ERR_IN_GNL));
	}
	free(s);
	return (1);
}

int				rd_start(t_base *b)
{
	char	*s;
	int		fd;
	int		ret;

	ret = 0;
	fd = open(b->file, O_RDONLY);
	ret = get_next_line(fd, &s);
	if (ret == -1)
		return (errors(ERR_IN_GNL));
	return (reader(b, s, fd, ret));
}
