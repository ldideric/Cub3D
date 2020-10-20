/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 15:21:31 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/20 22:22:44 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int			button_release_hooks(int keycode)
{
	if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S ||
		keycode == KEY_D || keycode == KEY_LFT || keycode == KEY_RGT)
		move_hooks(keycode, 0);
	return (1);
}

#ifndef LEAKS

int			button_press_hooks(int keycode)
{
	if (keycode == KEY_ESC || keycode == KEY_Q)
	{
		ft_printf("\x1b[38;5;196m[-]\x1b[0m Shutting down...\n");
		exit(mlx_destroy_window(g_vars.mlx, g_vars.win) * 0);
	}
	else if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S ||
			keycode == KEY_D || keycode == KEY_LFT || keycode == KEY_RGT)
		move_hooks(keycode, 1);
	return (1);
}

int			destroy_window_hooks(int keycode)
{
	(void)keycode;
	ft_printf("\x1b[38;5;196m[-]\x1b[0m Shutting down...\n");
	exit(0);
	return (1);
}

#else

int			button_press_hooks(int keycode)
{
	if (keycode == KEY_ESC || keycode == KEY_Q)
	{
		ft_printf("\x1b[38;5;196m[-]\x1b[0m Shutting down...\n");
		system("leaks cub3D >> leaks.txt");
		system("tail -n +19 leaks.txt");
		system("rm leaks.txt");
		exit(mlx_destroy_window(g_vars.mlx, g_vars.win) * 0);
	}
	else if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S ||
			keycode == KEY_D || keycode == KEY_LFT || keycode == KEY_RGT)
		move_hooks(keycode, 1);
	return (1);
}

int			destroy_window_hooks(int keycode)
{
	(void)keycode;
	ft_printf("\x1b[38;5;196m[-]\x1b[0m Shutting down...\n");
	system("leaks cub3D >> leaks.txt");
	system("tail -n +19 leaks.txt");
	system("rm leaks.txt");
	exit(0);
	return (1);
}

#endif

void		hooks(void)
{
	mlx_hook(g_vars.win, 2, (1L << 0), button_press_hooks, &g_vars);
	mlx_hook(g_vars.win, 3, (1L << 1), button_release_hooks, &g_vars);
	mlx_hook(g_vars.win, 17, 0L, destroy_window_hooks, &g_vars);
	return ;
}
