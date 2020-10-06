/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pxloop_ext.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/06 21:20:44 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/06 21:23:39 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <extra.h>

void			vertical_line(int x, t_data *d, t_rgb col)
{
	while (d->b.m.draw_start < d->b.m.draw_end)
	{
		my_mlx_pixel_put(d, x, d->b.m.draw_start, col.color);
		d->b.m.draw_start++;
	}
}

void			basic_math(t_base *b, int x)
{
	b->m.move_speed = 2;
	b->m.rot_speed = 10;
	b->m.camera_x = 2 * x / (double)b->res.x - 1;
	b->m.raydir_x = b->map.sp_dir.x + b->m.plane_x * b->m.camera_x;
	b->m.raydir_y = b->map.sp_dir.y + b->m.plane_y * b->m.camera_x;
	b->m.map_x = b->map.sp_pos.x;
	b->m.map_y = b->map.sp_pos.y;
	b->m.deltadist_x = fabs(1 / b->m.raydir_x);
	b->m.deltadist_y = fabs(1 / b->m.raydir_y);
	b->m.hit = 0;
}

t_rgb			wall_col(t_base *b)
{
	t_rgb color;

	if (b->map.ptr[b->m.map_y][b->m.map_x] == '1')
		color.color = 0xFF0000;
	else if (b->map.ptr[b->m.map_y][b->m.map_x] == '2')
		color.color = 0x00FF00;
	else
		color.color = 0xFFFF00;
	if (b->m.side == 1)
		color.color = color.color / 2;
	return (color);
}
