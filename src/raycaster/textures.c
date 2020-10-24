/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textures.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/09 02:39:50 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/24 21:52:32 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_rgb			get_color(t_tex *tex, int x, int y)
{
	t_rgb	color;
	char	*dst;

	dst = tex->addr + (y * tex->len + x * (tex->bpp / 8));
	color.color = *(unsigned int *)dst;
	return (color);
}

void			tex_pix_calc(t_tex *tex)
{
	if (g_m.side == 0)
		g_m.t.wall_x = g_m.pos.y + g_m.perpwalldist * g_m.raydir.y;
	else
		g_m.t.wall_x = g_m.pos.x + g_m.perpwalldist * g_m.raydir.x;
	g_m.t.wall_x -= floor((g_m.t.wall_x));
	g_m.t.x = (int)(g_m.t.wall_x * (double)(tex->x));
	if ((g_m.side == 0 && g_m.raydir.x > 0) ||
		(g_m.side == 1 && g_m.raydir.y < 0))
		g_m.t.x = tex->x - g_m.t.x - 1;
	g_m.t.step = 1.0 * tex->y / g_m.line_height;
	g_m.t.pos = (g_m.draw_start - g_m.res.y / 2 + g_m.line_height / 2)
				* g_m.t.step;
}

void			tex_loop(t_tex *tex, int x)
{
	t_rgb	color;
	int		y;

	tex_pix_calc(tex);
	y = g_m.draw_start;
	while (y < g_m.draw_end)
	{
		g_m.t.y = (int)g_m.t.pos & (tex->y - 1);
		g_m.t.pos += g_m.t.step;
		color = get_color(tex, g_m.t.x, g_m.t.y);
		if (color.packed.a > 0)
			color.packed.a = 0;
		my_mlx_pixel_put(x, y, color.color);
		y++;
	}
}

void			which_texture(int x)
{
	if (g_m.side == 0 && g_m.raydir.x >= 0)
		tex_loop(&g_vars.data.b.tex[1], x);
	else if (g_m.side == 0 && g_m.raydir.x < 0)
		tex_loop(&g_vars.data.b.tex[3], x);
	else if (g_m.side == 1 && g_m.raydir.y >= 0)
		tex_loop(&g_vars.data.b.tex[2], x);
	else
		tex_loop(&g_vars.data.b.tex[0], x);
}