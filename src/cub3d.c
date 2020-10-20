/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 10:28:10 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/20 21:09:35 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void		*mlx_start(t_data *d)
{
	g_vars.mlx = mlx_init();
	if (g_vars.mlx == NULL)
		return (NULL);
	g_vars.win = mlx_new_window(g_vars.mlx, d->b.res.x, d->b.res.y, WIN_NAME);
	if (g_vars.win == NULL)
		return (NULL);
	d->img1 = mlx_new_image(g_vars.mlx, d->b.res.x, d->b.res.y);
	if (d->img1 == NULL)
		return (NULL);
	d->img2 = mlx_new_image(g_vars.mlx, d->b.res.x, d->b.res.y);
	if (d->img2 == NULL)
		return (NULL);
	return ("1");
}

int				main(int argc, char **argv)
{
	if (argc >= 2)
		g_vars.data.b.file = argv[1];
	else
		return (errors(ERR_NO_CUB));
	if (!rd_start(&g_vars.data.b))
		return (0);
	if (mlx_start(&g_vars.data) == NULL)
		return (errors(ERR_IN_MLX));
	init_data();
	pxloop(&g_vars.data);
	ft_printf("\x1b[38;5;83m[+]\x1b[0m Ready to play!\n");
	hooks();
	mlx_loop(g_vars.mlx);
	return (0);
}
