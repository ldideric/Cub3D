/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/12 14:11:36 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/15 20:45:52 by ldideric      ########   odam.nl         */
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

#ifndef BONUS

void			init_data(void)
{
	g_vars.data.b.m.plane = (t_2vec){0, 0};
	g_vars.data.b.m.plane = (g_vars.data.b.map.sp_char == 'N')
		? (t_2vec){-0.66, 0} : g_vars.data.b.m.plane;
	g_vars.data.b.m.plane = (g_vars.data.b.map.sp_char == 'E')
		? (t_2vec){0, -0.66} : g_vars.data.b.m.plane;
	g_vars.data.b.m.plane = (g_vars.data.b.map.sp_char == 'S')
		? (t_2vec){0.66, 0} : g_vars.data.b.m.plane;
	g_vars.data.b.m.plane = (g_vars.data.b.map.sp_char == 'W')
		? (t_2vec){0, 0.66} : g_vars.data.b.m.plane;
	g_vars.data.img_ptr1 = &g_vars.data.img1;
	g_vars.data.img_ptr2 = &g_vars.data.img2;
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
	g_vars.data.b.m.plane = (t_2vec){0, 0};
	g_vars.data.b.m.plane = (g_vars.data.b.map.sp_char == 'N')
		? (t_2vec){-0.66, 0} : g_vars.data.b.m.plane;
	g_vars.data.b.m.plane = (g_vars.data.b.map.sp_char == 'E')
		? (t_2vec){0, 0.66} : g_vars.data.b.m.plane;
	g_vars.data.b.m.plane = (g_vars.data.b.map.sp_char == 'S')
		? (t_2vec){0.66, 0} : g_vars.data.b.m.plane;
	g_vars.data.b.m.plane = (g_vars.data.b.map.sp_char == 'W')
		? (t_2vec){0, -0.66} : g_vars.data.b.m.plane;
	g_vars.data.img_ptr1 = &g_vars.data.img1;
	g_vars.data.img_ptr2 = &g_vars.data.img2;
	init_key();
	init_bonus(&g_vars.data.b.bonus, g_vars.data.b.res);
}

#endif
