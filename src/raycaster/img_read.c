/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   img_read.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/09 02:39:50 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/21 22:35:41 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_rgb			get_color(t_spr *spr, int x, int y)
{
	t_rgb	color;
	char	*dst;

	dst = spr->addr + (y * spr->len + x * (spr->bpp / 8));
	color.color = *(unsigned int *)dst;
	return (color);
}

void			tex_pix_calc(t_spr *spr)
{
	if (g_m.side == 0)
		g_m.tex.wall_x = g_m.pos.y + g_m.perpwalldist * g_m.raydir.y;
	else
		g_m.tex.wall_x = g_m.pos.x + g_m.perpwalldist * g_m.raydir.x;
	g_m.tex.wall_x -= floor((g_m.tex.wall_x));
	g_m.tex.x = (int)(g_m.tex.wall_x * (double)(spr->x));
	if ((g_m.side == 0 && g_m.raydir.x > 0) ||
		(g_m.side == 1 && g_m.raydir.y < 0))
		g_m.tex.x = spr->x - g_m.tex.x - 1;
	g_m.tex.step = 1.0 * spr->y / g_m.line_height;
	g_m.tex.pos = (g_m.draw_start - g_m.res.y / 2 + g_m.line_height / 2)
				* g_m.tex.step;
}

void			tex_loop(t_spr *spr, int x)
{
	t_rgb	color;
	int		y;

	tex_pix_calc(spr);
	y = g_m.draw_start;
	while (y < g_m.draw_end)
	{
		g_m.tex.y = (int)g_m.tex.pos & (spr->y - 1);
		g_m.tex.pos += g_m.tex.step;
		color = get_color(spr, g_m.tex.x, g_m.tex.y);
		if (color.packed.a > 0)
			color.packed.a = 0;
		my_mlx_pixel_put(x, y, color.color);
		y++;
	}
}

void			which_texture(int x)
{
	if (g_m.side == 0 && g_m.raydir.x >= 0)
		tex_loop(&g_vars.data.b.sprites[1], x);
	else if (g_m.side == 0 && g_m.raydir.x < 0)
		tex_loop(&g_vars.data.b.sprites[3], x);
	else if (g_m.side == 1 && g_m.raydir.y >= 0)
		tex_loop(&g_vars.data.b.sprites[2], x);
	else
		tex_loop(&g_vars.data.b.sprites[0], x);
}
