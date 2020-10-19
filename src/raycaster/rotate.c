/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/15 17:32:20 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/19 20:37:28 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int			rot_left(void)
{
	t_map	*map;
	double	olddirx;
	double	oldplanex;
	double	rotspeed;

	map = &g_vars.data.b.map;
	rotspeed = g_m.rot_speed;
	olddirx = map->sp_dir.x;
	map->sp_dir.x = map->sp_dir.x * cos(-rotspeed)
	- map->sp_dir.y * sin(-rotspeed);
	map->sp_dir.y = olddirx * sin(-rotspeed)
	+ map->sp_dir.y * cos(-rotspeed);
	oldplanex = g_m.plane.x;
	g_m.plane.x = g_m.plane.x * cos(-rotspeed)
	- g_m.plane.y * sin(-rotspeed);
	g_m.plane.y = oldplanex * sin(-rotspeed)
	+ g_m.plane.y * cos(-rotspeed);
	return (0);
}

int			rot_right(void)
{
	t_map	*map;
	double	olddirx;
	double	oldplanex;
	double	rotspeed;

	map = &g_vars.data.b.map;
	rotspeed = g_m.rot_speed;
	olddirx = map->sp_dir.x;
	map->sp_dir.x = map->sp_dir.x * cos(rotspeed)
	- map->sp_dir.y * sin(rotspeed);
	map->sp_dir.y = olddirx * sin(rotspeed)
	+ map->sp_dir.y * cos(rotspeed);
	oldplanex = g_m.plane.x;
	g_m.plane.x = g_m.plane.x * cos(rotspeed)
	- g_m.plane.y * sin(rotspeed);
	g_m.plane.y = oldplanex * sin(rotspeed)
	+ g_m.plane.y * cos(rotspeed);
	return (0);
}
