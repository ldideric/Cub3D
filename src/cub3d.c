/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 10:28:10 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/27 22:35:26 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void		input_check(int ac, char **av, t_base *b)
{
	if (ac >= 2)
	{
		b->file = av[1];
		if (ac == 3)
		{
			if (ft_strncmp(av[2], "--save", 7) == 0)
				b->save.save = 1;
			else
				errors(ERR_S_FLAG);
		}
		else
			b->save.save = 0;
	}
	else
		errors(ERR_NO_CUB);
}

static void		*mlx_start(t_data *d)
{
	g_vars.mlx = mlx_init();
	if (g_vars.mlx == NULL)
		return (NULL);
	g_vars.win = mlx_new_window(g_vars.mlx, d->b.res.x, d->b.res.y, WIN_NAME);
	if (g_vars.win == NULL)
		return (NULL);
	d->img = mlx_new_image(g_vars.mlx, d->b.res.x, d->b.res.y);
	if (d->img == NULL)
		return (NULL);
	d->addr = mlx_get_data_addr(d->img, &d->bpp, &d->len, &d->endian);
	if (d->addr == NULL)
		return (NULL);
	return ("1");
}

int				loops(void)
{
	mlx_do_key_autorepeatoff(g_vars.mlx);
	mlx_hook(g_vars.win, 2, (1L << 0), button_press_hooks, &g_vars);
	mlx_hook(g_vars.win, 3, (1L << 1), button_release_hooks, &g_vars);
	mlx_hook(g_vars.win, 17, 0L, destroy_window_hooks, &g_vars);
	mlx_loop_hook(g_vars.mlx, &pxloop, &g_vars.data);
	if (g_vars.data.b.save.save == 0)
		ft_printf("\x1b[38;5;83m[+]\x1b[0m Ready to play!\n");
	else
		ft_printf("\x1b[38;5;83m[+]\x1b[0m Writing into .bmp file!\n");
	mlx_loop(g_vars.mlx);
	return (1);
}

int				main(int ac, char **av)
{
	input_check(ac, av, &g_vars.data.b);
	if (!rd_start(&g_vars.data.b))
		return (0);
	if (mlx_start(&g_vars.data) == NULL)
		return (errors(ERR_IN_MLX));
	init_data();
	loops();
	return (0);
}
