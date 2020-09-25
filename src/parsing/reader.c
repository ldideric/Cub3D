/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reader.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/02 18:57:52 by ldideric      #+#    #+#                 */
/*   Updated: 2020/09/25 15:50:51 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <extra.h>

static int		specifier(char *s, t_base *b)
{
	int					a;
	static const t_read	spec[128] = {
		['1'] = &rd_sprites,
		['2'] = &rd_res,
		['3'] = &rd_ground_sky,
	};

	a = -1;
	a = (*(u_int16_t *)s == *(u_int16_t *)"NO") ? spec['1'](s, b) : a;
	a = (*(u_int16_t *)s == *(u_int16_t *)"EA") ? spec['1'](s, b) : a;
	a = (*(u_int16_t *)s == *(u_int16_t *)"SO") ? spec['1'](s, b) : a;
	a = (*(u_int16_t *)s == *(u_int16_t *)"WE") ? spec['1'](s, b) : a;
	a = (*(u_int16_t *)s == *(u_int16_t *)"S ") ? spec['1'](s, b) : a;
	if (a == 0)
		return (0);
	a = (*(u_int16_t *)s == *(u_int16_t *)"R ") ? spec['2'](s, b) : a;
	if (a == 0)
		return (0);
	a = (*(u_int16_t *)s == *(u_int16_t *)"F ") ? spec['3'](s, b) : a;
	a = (*(u_int16_t *)s == *(u_int16_t *)"C ") ? spec['3'](s, b) : a;
	if (a == 0)
		return (0);
}

return (((*(u_int16_t *)s == *(u_int16_t *)"NO") && ((int (*)(char *, t_rgb *))spec['1'])(s, b)) ||
	((*(u_int16_t *)s == *(u_int16_t *)"EA") && ((int (*)(char *, t_rgb *))spec['1'])(s, b)) || 
	((*(u_int16_t *)s == *(u_int16_t *)"SO") && ((int (*)(char *, t_rgb *))spec['1'])(s, b)) ||
	((*(u_int16_t *)s == *(u_int16_t *)"WE") && ((int (*)(char *, t_rgb *))spec['1'])(s, b)) ||
	((*(u_int16_t *)s == *(u_int16_t *)"S ") && ((int (*)(char *, t_rgb *))spec['1'])(s, b)) ||
	((*(u_int16_t *)s == *(u_int16_t *)"R ") && ((int (*)(char *, t_rgb *))spec['2'])(s, b)) ||
	((*(u_int16_t *)s == *(u_int16_t *)"F ") && ((int (*)(char *, t_rgb *))spec['3'])(s, b)) ||
	((*(u_int16_t *)s == *(u_int16_t *)"C ") && ((int (*)(char *, t_rgb *))spec['3'])(s, b)));
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
