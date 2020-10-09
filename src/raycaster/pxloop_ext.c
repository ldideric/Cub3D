/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pxloop_ext.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/06 21:20:44 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/09 02:34:26 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <extra.h>

void			vertical_line(int x, t_data *d, t_rgb col)
{
	while (d->b.m.draw_start < d->b.m.draw_end)
	{
		my_mlx_pixel_put(d, x, d->b.m.draw_start, col.color);
		d->b.m.draw_start++;
	}
}

t_rgb			wall_col(t_base *b)
{
	t_rgb color;

	(void)b;
	color.color = 0xFF0000;
	return (color);
}

void			floor_ceiling_fill(t_data *d)
{
	int x;
	int y;

	y = 0;
	while (y < d->b.res.y)
	{
		x = 0;
		while (x < d->b.res.x)
		{
			if (y < (d->b.res.y / 2))
				my_mlx_pixel_put(d, x, y, d->b.ceiling.color);
			else
				my_mlx_pixel_put(d, x, y, d->b.floor.color);
			x++;
		}
		y++;
	}
}
