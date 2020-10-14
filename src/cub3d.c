/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 10:28:10 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/14 22:19:15 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <extra.h>

void			*mlx_start(t_data *d, t_vars *v)
{
	v->mlx = mlx_init();
	if (v->mlx == NULL)
		return (NULL);
	v->win = mlx_new_window(v->mlx, d->b.res.x, d->b.res.y, WIN_NAME);
	if (v->win == NULL)
		return (NULL);
	d->img1 = mlx_new_image(v->mlx, d->b.res.x, d->b.res.y);
	if (d->img1 == NULL)
		return (NULL);
	d->img2 = mlx_new_image(v->mlx, d->b.res.x, d->b.res.y);
	if (d->img2 == NULL)
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
	if (!rd_start(&vars, &vars.data.b))
		return (0);
	init_data(&vars);
	if (mlx_start(&vars.data, &vars) == NULL)
		return (errors(ERR_IN_MLX));
	pxloop(&vars);
	hooks(&vars);
	mlx_loop(vars.mlx);
	return (0);
}
