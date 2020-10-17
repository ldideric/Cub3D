/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reader.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/02 18:57:52 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/15 16:46:14 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

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

static int		rd_map_alloc(t_base *b, int start)
{
	if (start == TRUE)
		b->map.ptr = (char **)malloc(sizeof(char *) * 2);
	else
		b->map.ptr = ft_realloc_arr(b->map.ptr);
	if (b->map.ptr == NULL)
		return (errors(ERR_MALLOC));
	b->map.ptr[b->map.height] = ft_strdup(b->line);
	if (b->map.ptr[b->map.height] == NULL)
		return (errors(ERR_MALLOC));
	b->map.ptr[b->map.height + 1] = "\0";
	return (1);
}

static int		rd_map(t_base *b, int fd)
{
	int		ret;

	ret = 1;
	b->map.height = 0;
	b->map.ptr = NULL;
	if (rd_map_alloc(b, TRUE) == 0)
		return (0);
	b->map.height++;
	while (ret > 0)
	{
		free(b->line);
		ret = get_next_line(fd, &b->line);
		if (ret == -1)
			return (errors(ERR_IN_GNL));
		if (rd_map_alloc(b, FALSE) == 0)
			return (0);
		b->map.height = (ret == 0) ? b->map.height : b->map.height + 1;
	}
	return (1);
}

static int		reader(t_base *b, int fd, int ret)
{
	while (ret > 0)
	{
		if (ft_isalpha(b->line[0]) == 1)
		{
			if (!specifier(b->line, b))
				return (parse_err(b->line));
		}
		else if (ft_isdigit(b->line[0]) == 1 || b->line[0] == ' ')
			return (rd_map(b, fd));
		free(b->line);
		ret = get_next_line(fd, &b->line);
		if (ret == -1)
			return (errors(ERR_IN_GNL));
	}
	free(b->line);
	return (1);
}

int				rd_start(t_base *b)
{
	int		fd;
	int		ret;

	ret = 0;
	fd = open(b->file, O_RDONLY);
	ret = get_next_line(fd, &b->line);
	if (ret == -1)
		return (errors(ERR_IN_GNL));
	if (!reader(b, fd, ret) || !val_map(&b->map) || !val_res())
		return (0);
	return (1);
}
