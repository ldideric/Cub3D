/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/06 16:27:03 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/07 20:27:31 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <extra.h>

int			move_up(t_vars *vars)
{
	double	movespeed;

	movespeed = vars->data.b.m.move_speed;
	if (!vars->data.b.map.ptr[(int)(vars->data.b.map.sp_pos.y +
	vars->data.b.map.sp_dir.y * movespeed)][(int)(vars->data.b.map.sp_pos.x)])
		vars->data.b.map.sp_pos.x += vars->data.b.map.sp_dir.x * movespeed;
	if (!vars->data.b.map.ptr[(int)vars->data.b.map.sp_pos.y]
	[(int)(vars->data.b.map.sp_pos.x + vars->data.b.map.sp_dir.x * movespeed)])
		vars->data.b.map.sp_pos.y += vars->data.b.map.sp_dir.y * movespeed;
	return (0);
}

int			move_down(t_vars *vars)
{
	double	movespeed;

	movespeed = vars->data.b.m.move_speed;
	if (!vars->data.b.map.ptr[(int)(vars->data.b.map.sp_pos.y -
	vars->data.b.map.sp_dir.y * movespeed)][(int)(vars->data.b.map.sp_pos.x)])
		vars->data.b.map.sp_pos.x -= vars->data.b.map.sp_dir.x * movespeed;
	if (!vars->data.b.map.ptr[(int)(vars->data.b.map.sp_pos.y)]
	[(int)(vars->data.b.map.sp_pos.x - vars->data.b.map.sp_dir.x * movespeed)])
		vars->data.b.map.sp_pos.y -= vars->data.b.map.sp_dir.y * movespeed;
	return (0);
}

int			move_right(t_vars *vars)
{
	double	olddirx;
	double	oldplanex;
	double	rotspeed;

	rotspeed = vars->data.b.m.rot_speed;
	olddirx = vars->data.b.map.sp_dir.x;
	vars->data.b.map.sp_dir.x = vars->data.b.map.sp_dir.x * cos(-rotspeed) -
	vars->data.b.map.sp_dir.y * sin(-rotspeed);
	vars->data.b.map.sp_dir.y = olddirx * sin(-rotspeed) +
	vars->data.b.map.sp_dir.y * cos(-rotspeed);
	oldplanex = vars->data.b.m.plane_x;
	vars->data.b.m.plane_x = vars->data.b.m.plane_x * cos(-rotspeed) -
	vars->data.b.m.plane_y * sin(-rotspeed);
	vars->data.b.m.plane_y = oldplanex * sin(-rotspeed) +
	vars->data.b.m.plane_y * cos(-rotspeed);
	return (0);
}

int			move_left(t_vars *vars)
{
	double	olddirx;
	double	oldplanex;
	double	rotspeed;

	rotspeed = vars->data.b.m.rot_speed;
	olddirx = vars->data.b.map.sp_dir.x;
	vars->data.b.map.sp_dir.x = vars->data.b.map.sp_dir.x * cos(rotspeed) -
	vars->data.b.map.sp_dir.y * sin(rotspeed);
	vars->data.b.map.sp_dir.y = olddirx * sin(rotspeed) +
	vars->data.b.map.sp_dir.y * cos(rotspeed);
	oldplanex = vars->data.b.m.plane_x;
	vars->data.b.m.plane_x = vars->data.b.m.plane_x * cos(rotspeed) -
	vars->data.b.m.plane_y * sin(rotspeed);
	vars->data.b.m.plane_y = oldplanex * sin(rotspeed) +
	vars->data.b.m.plane_y * cos(rotspeed);
	return (0);
}
