/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/06 16:27:03 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/15 19:57:25 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int			move_up(void)
{
	t_base	*b;
	double	movespeed;

	b = &g_vars.data.b;
	movespeed = b->m.move_speed;
	if (b->map.ptr[(int)(b->map.sp_pos.y + (2 * b->map.sp_dir.y * movespeed))]
		[(int)(b->map.sp_pos.x)] != '1')
		b->map.sp_pos.y += b->map.sp_dir.y * movespeed;
	if (b->map.ptr[(int)(b->map.sp_pos.y)]
		[(int)(b->map.sp_pos.x + (2 * b->map.sp_dir.x * movespeed))] != '1')
		b->map.sp_pos.x += b->map.sp_dir.x * movespeed;
	return (0);
}

int			move_down(void)
{
	t_base	*b;
	double	movespeed;

	b = &g_vars.data.b;
	movespeed = b->m.move_speed;
	if (b->map.ptr[(int)(b->map.sp_pos.y - (2 * b->map.sp_dir.y * movespeed))]
		[(int)(b->map.sp_pos.x)] != '1')
		b->map.sp_pos.y -= b->map.sp_dir.y * movespeed;
	if (b->map.ptr[(int)(b->map.sp_pos.y)]
		[(int)(b->map.sp_pos.x - (2 * b->map.sp_dir.x * movespeed))] != '1')
		b->map.sp_pos.x -= b->map.sp_dir.x * movespeed;
	return (0);
}

int			move_right(void)
{
	t_base	*b;
	double	movespeed;

	b = &g_vars.data.b;
	movespeed = b->m.move_speed;
	if (b->map.ptr[(int)(b->map.sp_pos.y + (2 * b->m.plane.y * movespeed))]
		[(int)(b->map.sp_pos.x)] != '1')
		b->map.sp_pos.y += b->m.plane.y * movespeed;
	if (b->map.ptr[(int)(b->map.sp_pos.y)]
		[(int)(b->map.sp_pos.x + (2 * b->m.plane.x * movespeed))] != '1')
		b->map.sp_pos.x += b->m.plane.x * movespeed;
	return (0);
}

int			move_left(void)
{
	t_base	*b;
	double	movespeed;

	b = &g_vars.data.b;
	movespeed = b->m.move_speed;
	if (b->map.ptr[(int)(b->map.sp_pos.y - (2 * b->m.plane.y * movespeed))]
		[(int)(b->map.sp_pos.x)] != '1')
		b->map.sp_pos.y -= b->m.plane.y * movespeed;
	if (b->map.ptr[(int)(b->map.sp_pos.y)]
		[(int)(b->map.sp_pos.x - (2 * b->m.plane.x * movespeed))] != '1')
		b->map.sp_pos.x -= b->m.plane.x * movespeed;
	return (0);
}
