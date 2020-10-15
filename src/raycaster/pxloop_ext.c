/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pxloop_ext.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/06 21:20:44 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/15 19:18:31 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void			basic_math(t_base *b, int x)
{
	b->m.move_speed = 0.05;
	b->m.rot_speed = 0.03;
	b->m.camera_x = 2 * x / (double)b->res.x - 1;
	b->m.raydir.x = b->map.sp_dir.x + b->m.plane.x * b->m.camera_x;
	b->m.raydir.y = b->map.sp_dir.y + b->m.plane.y * b->m.camera_x;
	b->m.map.x = b->map.sp_pos.x;
	b->m.map.y = b->map.sp_pos.y;
	b->m.deltadist.x = fabs(1 / b->m.raydir.x);
	b->m.deltadist.y = fabs(1 / b->m.raydir.y);
	b->m.hit = 0;
}

void			vertical_line(int x, t_data *d, unsigned int col)
{
	while (d->b.m.draw_start < d->b.m.draw_end)
	{
		my_mlx_pixel_put(d, x, d->b.m.draw_start, col);
		d->b.m.draw_start++;
	}
}

void			floor_ceiling_fill(t_data *d)
{
	int x;
	int y;

	y = 0;
	while (y < d->b.res.y)
	{
		x = 0;
		while (x < d->b.res.x)
		{
			if (y < (d->b.res.y / 2))
				my_mlx_pixel_put(d, x, y, d->b.ceiling.color);
			else
				my_mlx_pixel_put(d, x, y, d->b.floor.color);
			x++;
		}
		y++;
	}
}
