/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprites.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/24 17:41:42 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/24 22:22:19 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void		spr_vert_line(t_tex *tex, int stripe)
{
	t_rgb	color;
	int		y;
	int		d;

	y = g_m.s.draw_start.y;
	while (y < g_m.s.draw_end.y)
	{
		d = y * 256 - g_vars.data.b.res.y * 128 + g_m.s.spr_h * 128;
		g_m.s.tex.y = ((d * tex->y) / g_m.s.spr_h) / 256;
		color = get_color(tex, g_m.s.tex.x, g_m.s.tex.y);
		if ((color.color & 0x00FFFFFF) != 0)
			my_mlx_pixel_put(stripe, y, color.color);
		y++;
	}
}

void		spr_width_calc(void)
{
	g_m.s.spr_w = abs((int)(g_vars.data.b.res.y / (g_m.s.transform.y)));
	g_m.s.draw_start.x = -g_m.s.spr_w / 2 + g_m.s.spr_screenx;
	if (g_m.s.draw_start.x < 0)
		g_m.s.draw_start.x = 0;
	g_m.s.draw_end.x = g_m.s.spr_w / 2 + g_m.s.spr_screenx;
	if (g_m.s.draw_end.x >= g_vars.data.b.res.x)
		g_m.s.draw_end.x = g_vars.data.b.res.x - 1;
}

void		basic_spr_math(t_spr *spr, int i)
{
	g_m.s.spr.x = spr->pos[i].x - g_m.pos.x;
	g_m.s.spr.y = spr->pos[i].y - g_m.pos.y;
	g_m.s.inv_det = 1.0 / (g_m.plane.x * g_m.raydir.y
		- g_m.raydir.x * g_m.plane.y);
	g_m.s.transform.x = g_m.s.inv_det * (g_m.raydir.y * g_m.s.spr.x
		- g_m.raydir.x * g_m.s.spr.y);
	g_m.s.transform.y = g_m.s.inv_det * (-g_m.plane.y * g_m.s.spr.x
		+ g_m.plane.x * g_m.s.spr.y);
	g_m.s.spr_screenx = (int)((g_vars.data.b.res.x / 2)
		* (1 + g_m.s.transform.x / g_m.s.transform.y));
	g_m.s.spr_h = abs((int)(g_vars.data.b.res.y / (g_m.s.transform.y)));
	g_m.s.draw_start.y = -g_m.s.spr_h / 2 + g_vars.data.b.res.y / 2;
	if (g_m.s.draw_start.y < 0)
		g_m.s.draw_start.y = 0;
	g_m.s.draw_end.y = g_m.s.spr_h / 2 + g_vars.data.b.res.y / 2;
	if (g_m.s.draw_end.y >= g_vars.data.b.res.y)
		g_m.s.draw_end.y = g_vars.data.b.res.y - 1;
}

void		spr_loop(t_spr *spr, t_tex *tex)
{
	int		stripe;
	int		i;

	i = 0;
	while (i < g_m.s.num_spr)
	{
		basic_spr_math(spr, i);
		spr_width_calc();
		stripe = g_m.s.draw_start.x;
		while (stripe < g_m.s.draw_end.x)
		{
			g_m.s.tex.x = (int)(256 * (stripe -
				(-g_m.s.spr_w / 2 + g_m.s.spr_screenx))
				* tex->x / g_m.s.spr_w) / 256;
			if (g_m.s.transform.y > 0 && stripe > 0 &&
				stripe < g_vars.data.b.res.x)
				spr_vert_line(tex, stripe);
			stripe++;
		}
		i++;
	}
}
