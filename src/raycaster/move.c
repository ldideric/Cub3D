/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/06 16:27:03 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/07 22:54:18 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <extra.h>

int			move_up(t_vars *vars)
{
	t_base	*b;
	double	movespeed;

	b = &vars->data.b;
	movespeed = b->m.move_speed;
	if (b->map.ptr[(int)(b->map.sp_pos.y + b->map.sp_dir.y * movespeed)]
		[(int)(b->map.sp_pos.x)] != '1')
		b->map.sp_pos.x += b->map.sp_dir.x * movespeed;
	if (b->map.ptr[(int)b->map.sp_pos.y]
		[(int)(b->map.sp_pos.x + b->map.sp_dir.x * movespeed)] != '1')
		b->map.sp_pos.y += b->map.sp_dir.y * movespeed;
	return (0);
}

int			move_down(t_vars *vars)
{
	t_base	*b;
	double	movespeed;

	b = &vars->data.b;
	movespeed = b->m.move_speed;
	if (b->map.ptr[(int)(b->map.sp_pos.y - b->map.sp_dir.y * movespeed)]
		[(int)(b->map.sp_pos.x)] != '1')
		b->map.sp_pos.x -= b->map.sp_dir.x * movespeed;
	if (b->map.ptr[(int)(b->map.sp_pos.y)]
		[(int)(b->map.sp_pos.x - b->map.sp_dir.x * movespeed)] != '1')
		b->map.sp_pos.y -= b->map.sp_dir.y * movespeed;
	return (0);
}

int			move_right(t_vars *vars)
{
	t_base	*b;
	double	olddirx;
	double	oldplanex;
	double	rotspeed;

	b = &vars->data.b;
	rotspeed = b->m.rot_speed;
	olddirx = b->map.sp_dir.x;
	b->map.sp_dir.x = b->map.sp_dir.x * cos(-rotspeed) -
	b->map.sp_dir.y * sin(-rotspeed);
	b->map.sp_dir.y = olddirx * sin(-rotspeed) +
	b->map.sp_dir.y * cos(-rotspeed);
	oldplanex = b->m.plane_x;
	b->m.plane_x = b->m.plane_x * cos(-rotspeed) -
	b->m.plane_y * sin(-rotspeed);
	b->m.plane_y = oldplanex * sin(-rotspeed) +
	b->m.plane_y * cos(-rotspeed);
	return (0);
}

int			move_left(t_vars *vars)
{
	t_base	*b;
	double	olddirx;
	double	oldplanex;
	double	rotspeed;

	b = &vars->data.b;
	rotspeed = b->m.rot_speed;
	olddirx = b->map.sp_dir.x;
	b->map.sp_dir.x = b->map.sp_dir.x * cos(rotspeed) -
	b->map.sp_dir.y * sin(rotspeed);
	b->map.sp_dir.y = olddirx * sin(rotspeed) +
	b->map.sp_dir.y * cos(rotspeed);
	oldplanex = b->m.plane_x;
	b->m.plane_x = b->m.plane_x * cos(rotspeed) -
	b->m.plane_y * sin(rotspeed);
	b->m.plane_y = oldplanex * sin(rotspeed) +
	b->m.plane_y * cos(rotspeed);
	return (0);
}
