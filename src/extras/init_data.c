/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/12 14:11:36 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/24 20:52:54 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void		init_key(void)
{
	g_vars.data.key.w = 0;
	g_vars.data.key.a = 0;
	g_vars.data.key.s = 0;
	g_vars.data.key.d = 0;
	g_vars.data.key.larr = 0;
	g_vars.data.key.rarr = 0;
}

static void		init_spr_loop(void)
{
	t_tex	*sp;
	char	*tmp;
	int		i;

	i = 0;
	while (i < 5)
	{
		sp = &g_vars.data.b.tex[i];
		tmp = ft_strtrim(sp->path, " \n\t");
		if (ft_strncmp(tmp + (ft_strlen(tmp) - 4), ".xpm", 4) == 0)
			sp->img = mlx_xpm_file_to_image(g_vars.mlx, tmp, &sp->x, &sp->y);
		else if (ft_strncmp(tmp + (ft_strlen(tmp) - 4), ".png", 4) == 0)
			sp->img = mlx_png_file_to_image(g_vars.mlx, tmp, &sp->x, &sp->y);
		if (sp->img == NULL)
			errors(ERR_SPR_IN);
		sp->addr = mlx_get_data_addr(sp->img, &sp->bpp, &sp->len, &sp->endian);
		free(tmp);
		i++;
	}
}

#ifndef BONUS

void			init_data(void)
{
	g_m.plane = (t_2vec){0, 0};
	g_m.plane = (g_vars.data.b.map.sp_char == 'N')
		? (t_2vec){0.66, 0} : g_m.plane;
	g_m.plane = (g_vars.data.b.map.sp_char == 'E')
		? (t_2vec){0, -0.66} : g_m.plane;
	g_m.plane = (g_vars.data.b.map.sp_char == 'S')
		? (t_2vec){-0.66, 0} : g_m.plane;
	g_m.plane = (g_vars.data.b.map.sp_char == 'W')
		? (t_2vec){0, 0.66} : g_m.plane;
	g_m.pos.x = g_vars.data.b.map.sp_pos.x;
	g_m.pos.y = g_vars.data.b.map.sp_pos.y;
	g_m.res.x = g_vars.data.b.res.x;
	g_m.res.y = g_vars.data.b.res.y;
	init_spr_loop();
	init_key();
}

#else

static void		init_bonus(t_bonus *bn, t_res res)
{
	bn->cr_length = (res.x > res.y) ? res.y / 75 : res.x / 75;
	bn->cr_width = bn->cr_length / 5;
	bn->cr_col = color_input(0, 255, 255, 0);
}

void			init_data(void)
{
	g_m.plane = (t_2vec){0, 0};
	g_m.plane = (g_vars.data.b.map.sp_char == 'N')
		? (t_2vec){0.66, 0} : g_m.plane;
	g_m.plane = (g_vars.data.b.map.sp_char == 'E')
		? (t_2vec){0, -0.66} : g_m.plane;
	g_m.plane = (g_vars.data.b.map.sp_char == 'S')
		? (t_2vec){-0.66, 0} : g_m.plane;
	g_m.plane = (g_vars.data.b.map.sp_char == 'W')
		? (t_2vec){0, 0.66} : g_m.plane;
	g_m.pos.x = g_vars.data.b.map.sp_pos.x;
	g_m.pos.y = g_vars.data.b.map.sp_pos.y;
	g_m.res.x = g_vars.data.b.res.x;
	g_m.res.y = g_vars.data.b.res.y;
	init_spr_loop();
	init_key();
	init_bonus(&g_vars.data.b.bonus, g_vars.data.b.res);
}

#endif
