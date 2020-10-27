/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bmp.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 20:35:55 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/27 22:14:35 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void		bmp_head_ext(t_res *res, t_save *s)
{
	s->bmp = (unsigned char *)malloc(sizeof(unsigned char) * 40);
	if (s->bmp == NULL)
		errors(ERR_MALLOC);
	ft_bzero(s->bmp, 40);
	s->bmp[0] = 40;
	s->bmp[4] = res->x;
	s->bmp[5] = res->x >> 8;
	s->bmp[6] = res->x >> 16;
	s->bmp[7] = res->x >> 24;
	s->bmp[8] = res->y;
	s->bmp[9] = res->y >> 8;
	s->bmp[10] = res->y >> 16;
	s->bmp[11] = res->y >> 24;
	s->bmp[12] = 1;
	s->bmp[14] = 32;
	write(s->fd, s->bmp, 40);
	free(s->bmp);
}

static void		bmp_head(t_res *res, t_save *s)
{
	s->bmp = (unsigned char *)malloc(sizeof(unsigned char) * 14);
	if (s->bmp == NULL)
		errors(ERR_MALLOC);
	ft_bzero(s->bmp, 14);
	s->size = 54 + (4 * res->x + s->pad_s) * res->y;
	s->bmp[0] = 'B';
	s->bmp[1] = 'M';
	s->bmp[2] = s->size;
	s->bmp[3] = s->size >> 8;
	s->bmp[4] = s->size >> 16;
	s->bmp[5] = s->size >> 24;
	s->bmp[10] = 54;
	write(s->fd, s->bmp, 14);
	free(s->bmp);
	bmp_head_ext(res, s);
}

static void		bmp_data(t_data *data, t_res *res, t_save *s)
{
	int		y;
	int		x;

	ft_bzero(s->pad, 3);
	y = (res->y == 1) ? res->y : res->y - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < data->b.res.x)
		{
			write(s->fd, data->addr + (y * data->len + x * data->bpp / 8),
				sizeof(int));
			x++;
		}
		write(s->fd, s->pad, s->pad_s);
		y--;
	}
}

void			bmp(t_data *data, t_save *s)
{
	s->pad_s = (4 - (data->b.res.x * 4) % 4) % 4;
	s->fd = open("screenshot.bmp", O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (s->fd == -1)
		errors(ERR_OPEN_F);
	bmp_head(&data->b.res, &data->b.save);
	bmp_data(data, &data->b.res, s);
	close(s->fd);
	exit(0);
}
