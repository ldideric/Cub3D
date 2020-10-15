/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pxloop.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/01 21:30:30 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/15 20:47:46 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void			calc_step(t_base *b)
{
	if (b->m.raydir.x < 0)
	{
		b->m.step.x = -1;
		b->m.sidedist.x = (b->map.sp_pos.x - b->m.map.x) * b->m.deltadist.x;
	}
	else
	{
		b->m.step.x = 1;
		b->m.sidedist.x = (b->m.map.x + 1.0 - b->map.sp_pos.x)
			* b->m.deltadist.x;
	}
	if (b->m.raydir.y < 0)
	{
		b->m.step.y = -1;
		b->m.sidedist.y = (b->map.sp_pos.y - b->m.map.y) * b->m.deltadist.y;
	}
	else
	{
		b->m.step.y = 1;
		b->m.sidedist.y = (b->m.map.y + 1.0 - b->map.sp_pos.y) *
			b->m.deltadist.y;
	}
}

void			dda_hit_checker(t_base *b)
{
	while (b->m.hit == 0)
	{
		if (b->m.sidedist.x < b->m.sidedist.y)
		{
			b->m.sidedist.x += b->m.deltadist.x;
			b->m.map.x += b->m.step.x;
			b->m.side = 0;
		}
		else
		{
			b->m.sidedist.y += b->m.deltadist.y;
			b->m.map.y += b->m.step.y;
			b->m.side = 1;
		}
		if (b->map.ptr[b->m.map.y][b->m.map.x] == '1')
			b->m.hit = 1;
	}
}

void			calc_line_height(t_base *b)
{
	if (b->m.side == 0)
		b->m.perpwalldist = (b->m.map.x - b->map.sp_pos.x
			+ (1 - b->m.step.x) / 2) / b->m.raydir.x;
	else
		b->m.perpwalldist = (b->m.map.y - b->map.sp_pos.y
		+ (1 - b->m.step.y) / 2) / b->m.raydir.y;
	b->m.line_height = (int)(b->res.y / b->m.perpwalldist);
	b->m.draw_start = -b->m.line_height / 2 + b->res.y / 2;
	if (b->m.draw_start < 0)
		b->m.draw_start = 0;
	b->m.draw_end = b->m.line_height / 2 + b->res.y / 2;
	if (b->m.draw_end >= b->res.y)
		b->m.draw_end = b->res.y - 1;
}

#ifndef BONUS

/*
** Without bonus
*/

int				pxloop(t_data *d)
{
	int		x;

	x = 0;
	d->addr = mlx_get_data_addr(*d->img_ptr2, &d->bpp,
		&d->len, &d->endian);
	if (d->addr == NULL)
		return (errors(ERR_IN_MLX));
	floor_ceiling_fill(&g_vars.data);
	while (x < d->b.res.x)
	{
		basic_math(&d->b, x);
		calc_step(&d->b);
		dda_hit_checker(&d->b);
		calc_line_height(&d->b);
		vertical_line(x, &g_vars.data, 0xFF0000);
		x++;
	}
	switch_ptr();
	mlx_put_image_to_window(g_vars.mlx, g_vars.win, *d->img_ptr1, 0, 0);
	return (1);
}

#else

/*
** With bonus
*/

int				pxloop(t_data *d)
{
	int		x;

	x = 0;
	d->addr = mlx_get_data_addr(*d->img_ptr2, &d->bpp,
		&d->len, &d->endian);
	if (d->addr == NULL)
		return (errors(ERR_IN_MLX));
	floor_ceiling_fill(&g_vars.data);
	while (x < d->b.res.x)
	{
		basic_math(&d->b, x);
		calc_step(&d->b);
		dda_hit_checker(&d->b);
		calc_line_height(&d->b);
		vertical_line(x, &g_vars.data, 0xFF0000);
		x++;
	}
	minimap(&g_vars.data, (t_res){0, 0}, (t_res){0, 0});
	cross_h(&g_vars.data, &d->b.bonus);
	switch_ptr();
	mlx_put_image_to_window(g_vars.mlx, g_vars.win, *d->img_ptr1, 0, 0);
	return (1);
}

#endif
