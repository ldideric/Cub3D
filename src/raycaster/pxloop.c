/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pxloop.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/01 21:39:37 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/02 01:26:35 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <extra.h>

t_rgb		color_input(int r, int g, int b, int a)
{
	t_rgb	color;

	color.packed.r = r;
	color.packed.g = g;
	color.packed.b = b;
	color.packed.a = a;
	return (color);
}

void	draw_rect(t_data *d, int x_topleft, int y_topleft, int width, int height, int color)
{
	int i;
	int j;

	j = y_topleft;
	while (j < height + y_topleft)
	{
		i = x_topleft;
		while (i < width + x_topleft)
		{
			my_mlx_pixel_put(d, i, j, color);
			i++;
		}
		j++;
	}
}

void		pix_loop(t_data *d)
{
	int		big;
	int		x;
	int		y;
	int		x_px;
	int		y_px;
	t_rgb	col;

	y = 0;
	y_px = 0;
	big = 50;
	while (y < 14)
	{
		x = 0;
		x_px = 0;
		while (ft_strlen(d->b.map[y]) > (size_t)x)
		{
			if (d->b.map[y][x] == '0')
				col = color_input(0, 0, 255, 0);
			else if (d->b.map[y][x] == '1')
				col = color_input(255, 0, 0, 0);
			else if (d->b.map[y][x] == '2')
				col = color_input(0, 255, 0, 0);
			else
				col = color_input(0, 0, 0, 0);
			draw_rect(d, x_px, y_px, big, big, (int)col.color);
			x++;
			x_px = x_px + big;
		}
		y++;
		y_px = y_px + big;
	}
}
