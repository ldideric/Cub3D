/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 15:21:31 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/06 21:33:16 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <extra.h>

static int			move_hooks(int keycode, t_vars *vars)
{
	if (keycode == KEY_W)
		move_up(vars);
	if (keycode == KEY_A)
		move_right(vars);
	if (keycode == KEY_S)
		move_down(vars);
	if (keycode == KEY_D)
		move_left(vars);
	return (1);
}

static int			button_release_hooks(int keycode, t_vars *vars)
{
	(void)keycode;
	(void)vars;
	return (0);
}

static int			button_press_hooks(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC || keycode == KEY_Q)
		exit(mlx_destroy_window(vars->mlx, vars->win) * 0);
	if (keycode == KEY_W || keycode == KEY_A ||
		keycode == KEY_S || keycode == KEY_D)
		move_hooks(keycode, vars);
	return (1);
}

static int			destroy_notify_hooks(int x, t_vars *vars)
{
	(void)x;
	(void)vars;
	ft_printf("\x1b[38;5;196m[-]\x1b[0m Shutting down...\n");
	exit(0);
	return (1);
}

void				hooks(t_vars *vars)
{
	mlx_hook(vars->win, 2, (1L << 0), button_press_hooks, vars);
	mlx_hook(vars->win, 3, (1L << 1), button_release_hooks, vars);
	mlx_hook(vars->win, 17, 0L, destroy_notify_hooks, vars);
	return ;
}
