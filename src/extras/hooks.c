/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 15:21:31 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/19 16:00:39 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int			move_hooks(void)
{
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

static int			button_press_hooks(int keycode)
{
	if (keycode == KEY_ESC || keycode == KEY_Q)
	{
		ft_printf("\x1b[38;5;196m[-]\x1b[0m Shutting down...\n");
		system("leaks cub3D >> leaks.txt");
		system("tail -n +19 leaks.txt");
		system("rm leaks.txt");
		exit(mlx_destroy_window(g_vars.mlx, g_vars.win) * 0);
	}
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
	move_hooks();
	return (1);
}

static int			button_release_hooks(int keycode)
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
	move_hooks();
	return (1);
}

static int			destroy_window_hooks(int keycode)
{
	(void)keycode;
	ft_printf("\x1b[38;5;196m[-]\x1b[0m Shutting down...\n");
	exit(0);
	return (1);
}

void				hooks(void)
{
	mlx_hook(g_vars.win, 2, (1L << 0), button_press_hooks, &g_vars);
	mlx_hook(g_vars.win, 3, (1L << 1), button_release_hooks, &g_vars);
	mlx_hook(g_vars.win, 17, 0L, destroy_window_hooks, &g_vars);
	return ;
}
