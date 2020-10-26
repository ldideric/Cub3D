/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pxloop.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/01 21:30:30 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/26 17:17:27 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void			calc_step(void)
{
	if (g_m.raydir.x < 0)
	{
		g_m.step.x = -1;
		g_m.sidedist.x = (g_m.pos.x - g_m.map.x) * g_m.deltadist.x;
	}
	else
	{
		g_m.step.x = 1;
		g_m.sidedist.x = (g_m.map.x + 1.0 - g_m.pos.x)
			* g_m.deltadist.x;
	}
	if (g_m.raydir.y < 0)
	{
		g_m.step.y = -1;
		g_m.sidedist.y = (g_m.pos.y - g_m.map.y) * g_m.deltadist.y;
	}
	else
	{
		g_m.step.y = 1;
		g_m.sidedist.y = (g_m.map.y + 1.0 - g_m.pos.y) *
			g_m.deltadist.y;
	}
}

void			dda_hit_checker(void)
{
	while (g_m.hit == 0)
	{
		if (g_m.sidedist.x < g_m.sidedist.y)
		{
			g_m.sidedist.x += g_m.deltadist.x;
			g_m.map.x += g_m.step.x;
			g_m.side = 0;
		}
		else
		{
			g_m.sidedist.y += g_m.deltadist.y;
			g_m.map.y += g_m.step.y;
			g_m.side = 1;
		}
		if (g_vars.data.b.map.ptr[g_m.map.y][g_m.map.x] == '1')
			g_m.hit = 1;
	}
}

void			calc_line_height(void)
{
	if (g_m.side == 0)
		g_m.perpwalldist = (g_m.map.x - g_m.pos.x
			+ (1 - g_m.step.x) / 2) / g_m.raydir.x;
	else
		g_m.perpwalldist = (g_m.map.y - g_m.pos.y
		+ (1 - g_m.step.y) / 2) / g_m.raydir.y;
	g_m.line_height = (int)(g_vars.data.b.res.y / g_m.perpwalldist);
	g_m.draw_start = -g_m.line_height / 2 + g_vars.data.b.res.y / 2;
	if (g_m.draw_start < 0)
		g_m.draw_start = 0;
	g_m.draw_end = g_m.line_height / 2 + g_vars.data.b.res.y / 2;
	if (g_m.draw_end >= g_vars.data.b.res.y)
		g_m.draw_end = g_vars.data.b.res.y - 1;
}

#ifndef BONUS

/*
** Without bonus
*/

int				pxloop(t_data *d)
{
	int		x;

	x = 0;
	mlx_sync(MLX_SYNC_IMAGE_WRITABLE, g_vars.data.img);
	floor_ceiling_fill();
	while (x < d->b.res.x)
	{
		basic_math(x);
		calc_step();
		dda_hit_checker();
		calc_line_height();
		which_texture(x);
		x++;
	}
	init_spr(&d->b.spr);
	spr_loop(&d->b.spr, &d->b.tex[4]);
	mlx_put_image_to_window(g_vars.mlx, g_vars.win, d->img, 0, 0);
	mlx_sync(MLX_SYNC_WIN_FLUSH_CMD, g_vars.win);
	return (1);
}

#else

/*
** With minimap and crosshair added
*/

int				pxloop(t_data *d)
{
	int		x;

	x = 0;
	mlx_sync(MLX_SYNC_IMAGE_WRITABLE, g_vars.data.img);
	floor_ceiling_fill();
	init_spr(&d->b.spr);
	while (x < d->b.res.x)
	{
		basic_math(x);
		calc_step();
		dda_hit_checker();
		calc_line_height();
		which_texture(x);
		x++;
	}
	spr_loop(&d->b.spr, &d->b.tex[4]);
	minimap(&g_vars.data, (t_res){0, 0}, (t_res){0, 0});
	cross_h(&g_vars.data, &d->b.bonus);
	mlx_put_image_to_window(g_vars.mlx, g_vars.win, d->img, 0, 0);
	mlx_sync(MLX_SYNC_WIN_FLUSH_CMD, g_vars.win);
	return (1);
}

#endif
