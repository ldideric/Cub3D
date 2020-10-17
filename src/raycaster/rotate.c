/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/15 17:32:20 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/15 20:00:17 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int			rot_left(void)
{
	t_base	*b;
	double	olddirx;
	double	oldplanex;
	double	rotspeed;

	b = &g_vars.data.b;
	rotspeed = b->m.rot_speed;
	olddirx = b->map.sp_dir.x;
	b->map.sp_dir.x = b->map.sp_dir.x * cos(-rotspeed)
	- b->map.sp_dir.y * sin(-rotspeed);
	b->map.sp_dir.y = olddirx * sin(-rotspeed)
	+ b->map.sp_dir.y * cos(-rotspeed);
	oldplanex = b->m.plane.x;
	b->m.plane.x = b->m.plane.x * cos(-rotspeed)
	- b->m.plane.y * sin(-rotspeed);
	b->m.plane.y = oldplanex * sin(-rotspeed)
	+ b->m.plane.y * cos(-rotspeed);
	return (0);
}

int			rot_right(void)
{
	t_base	*b;
	double	olddirx;
	double	oldplanex;
	double	rotspeed;

	b = &g_vars.data.b;
	rotspeed = b->m.rot_speed;
	olddirx = b->map.sp_dir.x;
	b->map.sp_dir.x = b->map.sp_dir.x * cos(rotspeed)
	- b->map.sp_dir.y * sin(rotspeed);
	b->map.sp_dir.y = olddirx * sin(rotspeed)
	+ b->map.sp_dir.y * cos(rotspeed);
	oldplanex = b->m.plane.x;
	b->m.plane.x = b->m.plane.x * cos(rotspeed)
	- b->m.plane.y * sin(rotspeed);
	b->m.plane.y = oldplanex * sin(rotspeed)
	+ b->m.plane.y * cos(rotspeed);
	return (0);
}
