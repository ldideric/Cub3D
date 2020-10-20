/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks_move.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/20 22:03:40 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/20 22:14:22 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void		move_button_press(int keycode)
{
	if (keycode == KEY_W)
		g_vars.data.key.w = 1;
	if (keycode == KEY_A)
		g_vars.data.key.a = 1;
	if (keycode == KEY_S)
		g_vars.data.key.s = 1;
	if (keycode == KEY_D)
		g_vars.data.key.d = 1;
	if (keycode == KEY_LFT)
		g_vars.data.key.larr = 1;
	if (keycode == KEY_RGT)
		g_vars.data.key.rarr = 1;
}

void		move_button_release(int keycode)
{
	if (keycode == KEY_W)
		g_vars.data.key.w = 0;
	if (keycode == KEY_A)
		g_vars.data.key.a = 0;
	if (keycode == KEY_S)
		g_vars.data.key.s = 0;
	if (keycode == KEY_D)
		g_vars.data.key.d = 0;
	if (keycode == KEY_LFT)
		g_vars.data.key.larr = 0;
	if (keycode == KEY_RGT)
		g_vars.data.key.rarr = 0;
}

int			move_hooks(int keycode, int o)
{
	if (o == 0)
		move_button_release(keycode);
	if (o == 1)
		move_button_press(keycode);
	if (g_vars.data.key.w == 1)
		move_up();
	if (g_vars.data.key.a == 1)
		move_left();
	if (g_vars.data.key.s == 1)
		move_down();
	if (g_vars.data.key.d == 1)
		move_right();
	if (g_vars.data.key.larr == 1)
		rot_left();
	if (g_vars.data.key.rarr == 1)
		rot_right();
	pxloop(&g_vars.data);
	return (1);
}
