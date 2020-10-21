/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   img_read.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/09 02:39:50 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/21 15:00:45 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static unsigned int	get_color(t_spr *spr, int x, int y)
{
	char	*dst;

	dst = spr->addr + (y * spr->len + x * (spr->bpp / 8));
	return (*(unsigned int *)dst);
}

int					img(t_spr *spr, int x)
{
	int color;
	int y;

	if (g_m.side == 0)
		g_m.tex.wall_x = g_m.map.y + g_m.perpwalldist * g_m.raydir.y;
	else
		g_m.tex.wall_x = g_m.map.x + g_m.perpwalldist * g_m.raydir.x;
	g_m.tex.wall_x -= floor((g_m.tex.wall_x));
	g_m.tex.x = (int)(g_m.tex.wall_x * (double)(spr->x));
	if (g_m.side == 0 && g_m.raydir.x > 0)
		g_m.tex.x = spr->x - g_m.tex.x - 1;
	if (g_m.side == 1 && g_m.raydir.y < 0)
		g_m.tex.x = spr->x - g_m.tex.x - 1;
	g_m.tex.step = 1.0 * spr->y / g_m.line_height;
	g_m.tex.pos = (g_m.draw_start - g_m.res.y / 2 + g_m.line_height / 2) * g_m.tex.step;
	
	y = g_m.draw_start;
	while (y < g_m.draw_end)
	{
		g_m.tex.y = (int)g_m.tex.pos & (spr->y - 1);
		g_m.tex.pos += g_m.tex.step;
		color = get_color(spr, g_m.tex.x, g_m.tex.y);
		// if (g_m.side == 1)
		// 	color = (color >> 1) & 8355711;
		my_mlx_pixel_put(x, y, color);
		y++;
	}
	return (0);
}

void				which_texture(t_spr (*spr)[5], int x)
{
	// if (g_m.side == 0 && g_m.raydir.x >= 0)
	// 	img(spr[1], x);
	// else if (g_m.side == 0 && g_m.raydir.x < 0)
	// 	img(spr[3], x);
	// else if (g_m.side == 1 && g_m.raydir.y >= 0)
	// 	img(spr[2], x);
	// else
		img(spr[0], x);
}
