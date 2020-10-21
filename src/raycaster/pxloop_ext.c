/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pxloop_ext.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/06 21:20:44 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/21 22:35:14 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void			basic_math(int x)
{
	g_m.move_speed = 0.1;
	g_m.rot_speed = 0.05;
	g_m.camera_x = 2 * x / (double)g_vars.data.b.res.x - 1;
	g_m.raydir.x = g_vars.data.b.map.sp_dir.x + g_m.plane.x * g_m.camera_x;
	g_m.raydir.y = g_vars.data.b.map.sp_dir.y + g_m.plane.y * g_m.camera_x;
	g_m.map.x = g_m.pos.x;
	g_m.map.y = g_m.pos.y;
	g_m.deltadist.x = fabs(1 / g_m.raydir.x);
	g_m.deltadist.y = fabs(1 / g_m.raydir.y);
	g_m.hit = 0;
}

void			floor_ceiling_fill(void)
{
	int x;
	int y;

	y = 0;
	while (y < g_vars.data.b.res.y)
	{
		x = 0;
		while (x < g_vars.data.b.res.x)
		{
			if (y < (g_vars.data.b.res.y / 2))
				my_mlx_pixel_put(x, y, g_vars.data.b.ceiling.color);
			else
				my_mlx_pixel_put(x, y, g_vars.data.b.floor.color);
			x++;
		}
		y++;
	}
}
