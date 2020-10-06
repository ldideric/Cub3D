/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pxloop.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/01 21:30:30 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/06 21:31:48 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <extra.h>

void			calc_step(t_base *b)
{
	if (b->m.raydir_x < 0)
	{
		b->m.step_x = -1;
		b->m.sidedist_x = (b->map.sp_pos.x - b->m.map_x) * b->m.deltadist_x;
	}
	else
	{
		b->m.step_x = 1;
		b->m.sidedist_x = (b->m.map_x + 1.0 - b->map.sp_pos.x)
			* b->m.deltadist_x;
	}
	if (b->m.raydir_y < 0)
	{
		b->m.step_y = -1;
		b->m.sidedist_y = (b->map.sp_pos.y - b->m.map_y) * b->m.deltadist_y;
	}
	else
	{
		b->m.step_y = 1;
		b->m.sidedist_y = (b->m.map_y + 1.0 - b->map.sp_pos.y) *
			b->m.deltadist_y;
	}
}

void			dda_hit_checker(t_base *b)
{
	while (b->m.hit == 0)
	{
		if (b->m.sidedist_x < b->m.sidedist_y)
		{
			b->m.sidedist_x += b->m.deltadist_x;
			b->m.map_x += b->m.step_x;
			b->m.side = 0;
		}
		else
		{
			b->m.sidedist_y += b->m.deltadist_y;
			b->m.map_y += b->m.step_y;
			b->m.side = 1;
		}
		if (b->map.ptr[b->m.map_y][b->m.map_x] > 0)
			b->m.hit = 1;
	}
}

int				pxloop(t_data *d, t_base *b, int x)
{
	while (x < b->res.x)
	{
		basic_math(b, x);
		calc_step(b);
		dda_hit_checker(b);
		if (b->m.side == 0)
			b->m.perpwalldist = (b->m.map_x - b->map.sp_pos.x
				+ (1 - b->m.step_x) / 2) / b->m.raydir_x;
		else
			b->m.perpwalldist = (b->m.map_y - b->map.sp_pos.y
			+ (1 - b->m.step_y) / 2) / b->m.raydir_y;
		b->m.line_height = (int)(b->res.y / b->m.perpwalldist);
		b->m.draw_start = -b->m.line_height / 2 + b->res.y / 2;
		if (b->m.draw_start < 0)
			b->m.draw_start = 0;
		b->m.draw_end = b->m.line_height / 2 + b->res.y / 2;
		if (b->m.draw_end >= b->res.y)
			b->m.draw_end = b->res.y - 1;
		vertical_line(x, d, wall_col(b));
		x++;
	}
	return (1);
}

int				render_start(t_vars *vars)
{
	vars->data.b.m.plane_x = 0;
	vars->data.b.m.plane_y = 0.66;
	pxloop(&vars->data, &vars->data.b, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
	return (1);
}
