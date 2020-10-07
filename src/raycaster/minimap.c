/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/01 21:39:37 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/07 20:23:57 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <extra.h>

static t_rgb		color_input(int r, int g, int b, int a)
{
	t_rgb	color;

	color.packed.r = r;
	color.packed.g = g;
	color.packed.b = b;
	color.packed.a = a;
	return (color);
}

static void			draw_rect(t_data *d, t_res cord, int size, int color)
{
	int i;
	int j;

	j = cord.y;
	while (j < size + cord.y)
	{
		i = cord.x;
		while (i < size + cord.x)
		{
			my_mlx_pixel_put(d, i, j, color);
			i++;
		}
		j++;
	}
}

void				minimap(t_data *d, int size)
{
	t_res	i;
	t_res	j;
	t_rgb	col;

	i.y = 0;
	j.y = 0;
	while (i.y < d->b.map.height)
	{
		i.x = 0;
		j.x = 0;
		while (ft_strlen(d->b.map.ptr[i.y]) > (size_t)i.x)
		{
			if (d->b.map.ptr[i.y][i.x] == '0')
				col = color_input(174, 182, 191, 0);
			else if (d->b.map.ptr[i.y][i.x] == '1')
				col = color_input(255, 255, 255, 0);
			else if (d->b.map.ptr[i.y][i.x] == '2')
				col = color_input(130, 224, 170, 0);
			else
				col = color_input(0, 0, 0, 0);
			draw_rect(d, j, size, (int)col.color);
			i.x++;
			j.x = j.x + size;
		}
		i.y++;
		j.y = j.y + size;
	}
}
