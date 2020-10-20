/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   img_read.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/09 02:39:50 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/20 00:58:55 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int					load_img(t_spr *sprites)
{
	char *addr = mlx_get_data_addr(img, 4, ?, ? );
}

unsigned int		get_color(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->len + x * (data->bpp / 8));
	return(*(unsigned int *)dst);
}

int					img(t_base *b, int x)
{
	int y = g_m.draw_start;

	g_m.tex.num = b->map.ptr[g_m.map.y][g_m.map.x] - '1';
	if (g_m.side == 0)
		g_m.tex.wall_x = g_m.map.y + g_m.perpwalldist * g_m.raydir.y;
	else
		g_m.tex.wall_x = g_m.map.x + g_m.perpwalldist * g_m.raydir.x;
	g_m.tex.wall_x -= floor((g_m.tex.wall_x));
	g_m.tex.x = (int)(g_m.tex.wall_x * (double)(texWidth));
	
	if (g_m.side == 0 && g_m.raydir.x > 0)
		g_m.tex.x = texWidth - g_m.tex.x - 1;
	if (g_m.side == 1 && g_m.raydir.y < 0)
		g_m.tex.x = texWidth - g_m.tex.x - 1;

	g_m.tex.step = 1.0 * texHeight / g_m.line_height;
	g_m.tex.pos = (g_m.draw_start - g_m.res.y / 2 + g_m.line_height / 2) * g_m.tex.step;
	while (y < g_m.draw_end)
	{
		g_m.tex.y = (int)g_m.tex.pos & (texHeight - 1);
		g_m.tex.pos += g_m.tex.step;
		
		int color = get_color(&g_vars.data, g_m.tex.x, g_m.tex.y);
		
		if (g_m.side == 1)
			color = (color >> 1) & 8355711;
		my_mlx_pixel_put(x, y, color);
		y++;
	}
}
