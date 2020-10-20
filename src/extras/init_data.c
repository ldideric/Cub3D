/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/12 14:11:36 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/20 03:16:59 by ldideric      ########   odam.nl         */
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

static void		init_sprite_img(t_spr *sprites)
{
	sprites->no.img = mlx_new_image(g_vars.mlx, g_vars.data.b.res.x, g_vars.data.b.res.y);
	sprites->no.img = mlx_png_file_to_image(g_vars.mlx, sprites->no.path,
		&sprites->no.x, &sprites->no.y);
	sprites->ea.img = mlx_xpm_file_to_image(g_vars.mlx, sprites->ea.path,
		&sprites->ea.x, &sprites->ea.y);
	sprites->so.img = mlx_xpm_file_to_image(g_vars.mlx, sprites->so.path,
		&sprites->so.x, &sprites->so.y);
	sprites->we.img = mlx_xpm_file_to_image(g_vars.mlx, sprites->we.path,
		&sprites->we.x, &sprites->we.y);
	sprites->s.img = mlx_xpm_file_to_image(g_vars.mlx, sprites->s.path,
		&sprites->s.x, &sprites->s.y);
	if (sprites->no.img == NULL || sprites->ea.img == NULL ||
		sprites->so.img == NULL || sprites->we.img == NULL ||
		sprites->s.img == NULL)
		errors(ERR_SPR_IN);
}

#ifndef BONUS

void			init_data(void)
{
	g_m.plane = (t_2vec){0, 0};
	g_m.plane = (g_vars.data.b.map.sp_char == 'N')
		? (t_2vec){-0.66, 0} : g_m.plane;
	g_m.plane = (g_vars.data.b.map.sp_char == 'E')
		? (t_2vec){0, -0.66} : g_m.plane;
	g_m.plane = (g_vars.data.b.map.sp_char == 'S')
		? (t_2vec){0.66, 0} : g_m.plane;
	g_m.plane = (g_vars.data.b.map.sp_char == 'W')
		? (t_2vec){0, 0.66} : g_m.plane;
	g_m.pos.x = g_vars.data.b.map.sp_pos.x;
	g_m.pos.y = g_vars.data.b.map.sp_pos.y;
	g_m.res.x = g_vars.data.b.res.x;
	g_m.res.y = g_vars.data.b.res.y;
	g_vars.data.img_ptr1 = &g_vars.data.img1;
	g_vars.data.img_ptr2 = &g_vars.data.img2;
	init_sprite_img(&g_vars.data.b.sprites);
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
		? (t_2vec){-0.66, 0} : g_m.plane;
	g_m.plane = (g_vars.data.b.map.sp_char == 'E')
		? (t_2vec){0, -0.66} : g_m.plane;
	g_m.plane = (g_vars.data.b.map.sp_char == 'S')
		? (t_2vec){0.66, 0} : g_m.plane;
	g_m.plane = (g_vars.data.b.map.sp_char == 'W')
		? (t_2vec){0, 0.66} : g_m.plane;
	g_m.pos.x = g_vars.data.b.map.sp_pos.x;
	g_m.pos.y = g_vars.data.b.map.sp_pos.y;
	g_m.res.x = g_vars.data.b.res.x;
	g_m.res.y = g_vars.data.b.res.y;
	g_vars.data.img_ptr1 = &g_vars.data.img1;
	g_vars.data.img_ptr2 = &g_vars.data.img2;
	init_sprite_img();
	init_key();
	init_bonus(&g_vars.data.b.bonus, g_vars.data.b.res);
}

#endif
