/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pxloop.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/01 21:30:30 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/07 20:26:07 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <extra.h>

void			basic_math(t_base *b, int x)
{
	b->m.plane_x = 0;
	b->m.plane_y = 0.66;
	b->m.move_speed = 2;
	b->m.rot_speed = 10;
	b->m.camera_x = 2 * x / (double)b->res.x - 1;
	b->m.raydir_x = b->map.sp_dir.x + b->m.plane_x * b->m.camera_x;
	b->m.raydir_y = b->map.sp_dir.y + b->m.plane_y * b->m.camera_x;
	b->m.map_x = b->map.sp_pos.x;
	b->m.map_y = b->map.sp_pos.y;
	b->m.deltadist_x = (b->m.deltadist_x == 0) ? 0 : fabs(1 / b->m.raydir_x);
	b->m.deltadist_y = (b->m.deltadist_x == 0) ? 0 : fabs(1 / b->m.raydir_y);
	b->m.hit = 0;
}

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
		if (b->map.ptr[b->m.map_y][b->m.map_x] == '1')
			b->m.hit = 1;
	}
}

void			calc_line_height(t_base *b)
{
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
}

int				pxloop(t_vars *vars)
{
	int		x;

	x = 0;
	floor_ceiling_fill(&vars->data);
	while (x < vars->data.b.res.x)
	{
		basic_math(&vars->data.b, x);
		calc_step(&vars->data.b);
		dda_hit_checker(&vars->data.b);
		calc_line_height(&vars->data.b);
		vertical_line(x, &vars->data, wall_col(&vars->data.b));
		x++;
	}
	// minimap(&vars->data, 15);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
	return (1);
}
