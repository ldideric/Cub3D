/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reader.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/02 18:57:52 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/28 15:08:15 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int		specifier(char *s, t_base *b)
{
	static const t_read	spec[4] = {
		[0] = &rd_tex,
		[1] = &rd_res,
		[2] = &rd_f_c,
		[3] = &rd_spr,
	};

	return (((*(u_int16_t *)s == *(u_int16_t *)"NO") && spec[0](s, b)) ||
			((*(u_int16_t *)s == *(u_int16_t *)"EA") && spec[0](s, b)) ||
			((*(u_int16_t *)s == *(u_int16_t *)"SO") && spec[0](s, b)) ||
			((*(u_int16_t *)s == *(u_int16_t *)"WE") && spec[0](s, b)) ||
			((*(u_int16_t *)s == *(u_int16_t *)"R ") && spec[1](s, b)) ||
			((*(u_int16_t *)s == *(u_int16_t *)"F ") && spec[2](s, b)) ||
			((*(u_int16_t *)s == *(u_int16_t *)"C ") && spec[2](s, b)) ||
			((*s == *"S") && spec[3](s, b)));
}

static int		reader(t_base *b, int fd, int ret)
{
	int		i;

	while (ret > 0)
	{
		i = 0;
		if (tab_checker(b->line))
			return (errors(ERR_IN_TAB));
		if (ft_isalpha(first_char(b->line)))
		{
			while (!ft_isalpha(b->line[i]))
				i++;
			if (!specifier(b->line + i, b))
				return (parse_err(b->line + i));
		}
		else if (ft_isdigit(b->line[i]) == 1 || b->line[i] == ' ')
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
	t_tex_bzero(b);
	if (!reader(b, fd, ret) || !val_map(&b->map) || !val_res())
		return (0);
	close(fd);
	return (1);
}
