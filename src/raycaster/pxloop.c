/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pxloop.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/01 21:30:30 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/09 16:18:21 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <extra.h>

void			basic_math(t_base *b, int x)
{
	if (b->m.start == 0)
	{
		b->m.plane = (t_2vec){0, 0};
		b->m.plane = (b->map.sp_char == 'N') ? (t_2vec){-0.66, 0} : b->m.plane;
		b->m.plane = (b->map.sp_char == 'E') ? (t_2vec){0, 0.66} : b->m.plane;
		b->m.plane = (b->map.sp_char == 'S') ? (t_2vec){0.66, 0} : b->m.plane;
		b->m.plane = (b->map.sp_char == 'W') ? (t_2vec){0, -0.66} : b->m.plane;
		b->m.start = 1;
	}
	b->m.move_speed = 0.05;
	b->m.rot_speed = 0.03;
	b->m.camera_x = 2 * x / (double)b->res.x - 1;
	b->m.raydir.x = b->map.sp_dir.x + b->m.plane.x * b->m.camera_x;
	b->m.raydir.y = b->map.sp_dir.y + b->m.plane.y * b->m.camera_x;
	b->m.map.x = b->map.sp_pos.x;
	b->m.map.y = b->map.sp_pos.y;
	b->m.deltadist.x = (b->m.deltadist.x == 0) ? 0 : fabs(1 / b->m.raydir.x);
	b->m.deltadist.y = (b->m.deltadist.x == 0) ? 0 : fabs(1 / b->m.raydir.y);
	b->m.hit = 0;
}

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
	minimap(&vars->data, (t_res){0, 0}, (t_res){0, 0}, 15);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
	return (1);
}
