/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 10:28:10 by ldideric      #+#    #+#                 */
/*   Updated: 2020/09/28 15:37:13 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <extra.h>

void			*mlx_start(t_data *d, t_vars *v)
{
	v->mlx = mlx_init();
	if (v->mlx == NULL)
		return (NULL);
	v->win = mlx_new_window(v->mlx, d->b.res.x_max, d->b.res.y_max, WIN_NAME);
	if (v->win == NULL)
		return (NULL);
	d->img = mlx_new_image(v->mlx, d->b.res.x_max, d->b.res.y_max);
	if (d->img == NULL)
		return (NULL);
	d->addr = mlx_get_data_addr(d->img, &d->bpp, &d->len, &d->endian);
	if (d->addr == NULL)
		return (NULL);
	return ("1");
}

int				main(int argc, char **argv)
{
	t_vars		vars;

	if (argc >= 2)
		vars.data.b.file = argv[1];
	else
		return (errors(ERR_NO_CUB));
	if (!rd_start(&vars.data.b))
		return (0);
	if (mlx_start(&vars.data, &vars) == NULL)
		return (errors(ERR_IN_MLX));
	// px_loop(&vars.data);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.data.img, 0, 0);
	hooks(&vars);
	mlx_loop(vars.mlx);
	return (0);
}
