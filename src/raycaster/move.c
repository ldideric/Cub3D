/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/06 16:27:03 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/26 16:16:01 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int		can_move(char c)
{
	if (c == '0')
		return (1);
	else if (c >= '1' && c <= '9')
		return (0);
	return (1);
}

int				move_up(void)
{
	t_map	*map;
	double	movespeed;

	map = &g_vars.data.b.map;
	movespeed = g_m.move_speed;
	if (can_move(map->ptr[(int)(g_m.pos.y + (2 * map->sp_dir.y * movespeed))]
		[(int)(g_m.pos.x)]))
		g_m.pos.y += map->sp_dir.y * movespeed;
	if (can_move(map->ptr[(int)(g_m.pos.y)]
		[(int)(g_m.pos.x + (2 * map->sp_dir.x * movespeed))]))
		g_m.pos.x += map->sp_dir.x * movespeed;
	return (0);
}

int				move_down(void)
{
	t_map	*map;
	double	movespeed;

	map = &g_vars.data.b.map;
	movespeed = g_m.move_speed;
	if (can_move(map->ptr[(int)(g_m.pos.y - (2 * map->sp_dir.y * movespeed))]
		[(int)(g_m.pos.x)]))
		g_m.pos.y -= map->sp_dir.y * movespeed;
	if (can_move(map->ptr[(int)(g_m.pos.y)]
		[(int)(g_m.pos.x - (2 * map->sp_dir.x * movespeed))]))
		g_m.pos.x -= map->sp_dir.x * movespeed;
	return (0);
}

int				move_right(void)
{
	t_map	*map;
	double	movespeed;

	map = &g_vars.data.b.map;
	movespeed = g_m.move_speed;
	if (can_move(map->ptr[(int)(g_m.pos.y + (2 * g_m.plane.y * movespeed))]
		[(int)(g_m.pos.x)]))
		g_m.pos.y += g_m.plane.y * movespeed;
	if (can_move(map->ptr[(int)(g_m.pos.y)]
		[(int)(g_m.pos.x + (2 * g_m.plane.x * movespeed))]))
		g_m.pos.x += g_m.plane.x * movespeed;
	return (0);
}

int				move_left(void)
{
	t_map	*map;
	double	movespeed;

	map = &g_vars.data.b.map;
	movespeed = g_m.move_speed;
	if (can_move(map->ptr[(int)(g_m.pos.y - (2 * g_m.plane.y * movespeed))]
		[(int)(g_m.pos.x)]))
		g_m.pos.y -= g_m.plane.y * movespeed;
	if (can_move(map->ptr[(int)(g_m.pos.y)]
		[(int)(g_m.pos.x - (2 * g_m.plane.x * movespeed))]))
		g_m.pos.x -= g_m.plane.x * movespeed;
	return (0);
}
