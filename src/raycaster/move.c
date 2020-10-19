/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/06 16:27:03 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/19 20:39:10 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int			move_up(void)
{
	t_map	*map;
	double	movespeed;

	map = &g_vars.data.b.map;
	movespeed = g_m.move_speed;
	if (map->ptr[(int)(g_m.pos.y + (2 * map->sp_dir.y * movespeed))]
		[(int)(g_m.pos.x)] != '1')
		g_m.pos.y += map->sp_dir.y * movespeed;
	if (map->ptr[(int)(g_m.pos.y)]
		[(int)(g_m.pos.x + (2 * map->sp_dir.x * movespeed))] != '1')
		g_m.pos.x += map->sp_dir.x * movespeed;
	return (0);
}

int			move_down(void)
{
	t_map	*map;
	double	movespeed;

	map = &g_vars.data.b.map;
	movespeed = g_m.move_speed;
	if (map->ptr[(int)(g_m.pos.y - (2 * map->sp_dir.y * movespeed))]
		[(int)(g_m.pos.x)] != '1')
		g_m.pos.y -= map->sp_dir.y * movespeed;
	if (map->ptr[(int)(g_m.pos.y)]
		[(int)(g_m.pos.x - (2 * map->sp_dir.x * movespeed))] != '1')
		g_m.pos.x -= map->sp_dir.x * movespeed;
	return (0);
}

int			move_right(void)
{
	t_map	*map;
	double	movespeed;

	map = &g_vars.data.b.map;
	movespeed = g_m.move_speed;
	if (map->ptr[(int)(g_m.pos.y + (2 * g_m.plane.y * movespeed))]
		[(int)(g_m.pos.x)] != '1')
		g_m.pos.y += g_m.plane.y * movespeed;
	if (map->ptr[(int)(g_m.pos.y)]
		[(int)(g_m.pos.x + (2 * g_m.plane.x * movespeed))] != '1')
		g_m.pos.x += g_m.plane.x * movespeed;
	return (0);
}

int			move_left(void)
{
	t_map	*map;
	double	movespeed;

	map = &g_vars.data.b.map;
	movespeed = g_m.move_speed;
	if (map->ptr[(int)(g_m.pos.y - (2 * g_m.plane.y * movespeed))]
		[(int)(g_m.pos.x)] != '1')
		g_m.pos.y -= g_m.plane.y * movespeed;
	if (map->ptr[(int)(g_m.pos.y)]
		[(int)(g_m.pos.x - (2 * g_m.plane.x * movespeed))] != '1')
		g_m.pos.x -= g_m.plane.x * movespeed;
	return (0);
}
