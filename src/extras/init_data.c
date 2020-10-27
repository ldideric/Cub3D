/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/12 14:11:36 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/28 00:24:43 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

#ifndef BONUS

void			init_data(void)
{
	g_m.plane = (t_2vec){0, 0};
	g_m.plane = (g_vars.data.b.map.sp_char == 'N')
		? (t_2vec){0.66, 0} : g_m.plane;
	g_m.plane = (g_vars.data.b.map.sp_char == 'E')
		? (t_2vec){0, 0.66} : g_m.plane;
	g_m.plane = (g_vars.data.b.map.sp_char == 'S')
		? (t_2vec){-0.66, 0} : g_m.plane;
	g_m.plane = (g_vars.data.b.map.sp_char == 'W')
		? (t_2vec){0, -0.66} : g_m.plane;
	g_m.pos.x = g_vars.data.b.map.sp_pos.x;
	g_m.pos.y = g_vars.data.b.map.sp_pos.y;
	g_m.dir.x = g_vars.data.b.map.sp_dir.x;
	g_m.dir.y = g_vars.data.b.map.sp_dir.y;
	g_m.res.x = g_vars.data.b.res.x;
	g_m.res.y = g_vars.data.b.res.y;
	init_spr_img_loop();
	init_tex_img_loop();
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
		? (t_2vec){0, 0.66} : g_m.plane;
	g_m.plane = (g_vars.data.b.map.sp_char == 'S')
		? (t_2vec){-0.66, 0} : g_m.plane;
	g_m.plane = (g_vars.data.b.map.sp_char == 'W')
		? (t_2vec){0, -0.66} : g_m.plane;
	g_m.pos.x = g_vars.data.b.map.sp_pos.x;
	g_m.pos.y = g_vars.data.b.map.sp_pos.y;
	g_m.dir.x = g_vars.data.b.map.sp_dir.x;
	g_m.dir.y = g_vars.data.b.map.sp_dir.y;
	g_m.res.x = g_vars.data.b.res.x;
	g_m.res.y = g_vars.data.b.res.y;
	init_spr_img_loop();
	init_tex_img_loop();
	init_key();
	init_bonus(&g_vars.data.b.bonus, g_vars.data.b.res);
}

#endif
