/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 10:28:10 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/21 21:39:20 by ldideric      ########   odam.nl         */
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

// void	draw_texture(t_player *p, int x)
// {
// 	t_res	xy;
// 	t_rgb	color;
// 	int		i;
	
// 	xy.x = x;
// 	*i = set_texture(w, p);
// 	g_m.tex.wall_x -= floor((g_m.tex.wall_x));
// 	g_m.tex.x = (int)(g_m.tex.wall_x * (double)spr->x);
	
// 	if ((g_m.side == 0 && g_m.raydir.x > 0) || (g_m.side == 1 && g_m.raydir.y < 0))
// 		g_m.tex.x = spr->x - g_m.tex.x - 1;
	
// 	g_m.step = 1.0 * spr->y / g_m.line_height;
// 	g_m.tex.pos = (g_m.draw_start - g_m.res.y / 2 + g_m.line_height / 2) * g_m.tex.step;
// 	xy.y = g_m.draw_start;
// 	while (xy.y < g_m.draw_end)
// 	{
// 		g_m.tex.y = (int)g_m.tex.pos & (g_data->textures[i].h - 1);
// 		g_m.tex.pos += g_m.tex.step;
// 		color.color = read_image(g_data->textures[i], g_data->textures[i].tp,
// 		g_m.tex.x, g_m.tex.y);
// 		pixel_put(&g_data->mlx_data, xy.x, xy.y, color);
// 		xy.y++;
// 	}
// }
