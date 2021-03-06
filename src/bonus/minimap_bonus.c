/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap_bonus.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/01 21:39:37 by ldideric      #+#    #+#                 */
/*   Updated: 2020/11/02 20:49:10 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void			draw_rect(t_res cord, int size, int color)
{
	int i;
	int j;

	j = cord.y;
	while (j < size + cord.y)
	{
		i = cord.x;
		while (i < size + cord.x)
		{
			my_mlx_pixel_put(i, j, color);
			i++;
		}
		j++;
	}
}

static t_rgb		color_pick(t_data *d, t_res i)
{
	if ((g_m.pos.x > i.x && g_m.pos.x < i.x + 1) &&
		(g_m.pos.y > i.y && g_m.pos.y < i.y + 1))
		return (color_input(255, 0, 0, 0));
	else if (d->b.map.ptr[i.y][i.x] == '1')
		return (color_input(255, 255, 255, 0));
	else if (d->b.map.ptr[i.y][i.x] == '0' ||
	ft_isalpha(d->b.map.ptr[i.y][i.x]))
		return (color_input(174, 182, 191, 0));
	else
		return (color_input(0, 255, 0, 0));
}

void				minimap(t_data *d, t_res i, t_res j)
{
	int size;

	size = ((d->b.res.x > d->b.res.y) ? d->b.res.y : d->b.res.x) / 50;
	if (g_m.pos.x > 5)
		i.x = (int)(g_m.pos.x - 5);
	if (g_m.pos.y > 5)
		i.y = (int)(g_m.pos.y - 5);
	while (i.y < d->b.map.height + 1 && i.y < g_m.pos.y + 5)
	{
		i.x = 0;
		if (g_m.pos.x > 5)
			i.x = g_m.pos.x - 5;
		j.x = 0;
		while (i.x < (int)ft_strlen(d->b.map.ptr[i.y])
			&& i.x < g_m.pos.x + 5)
		{
			draw_rect(j, size, (int)color_pick(d, i).color);
			i.x++;
			j.x = j.x + size;
		}
		i.y++;
		j.y = j.y + size;
	}
}

void				bonus_call(t_data *d)
{
	minimap(d, (t_res){0, 0}, (t_res){0, 0});
	cross_h(d, &d->b.bonus);
}
