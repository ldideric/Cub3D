/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/12 14:11:36 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/14 22:32:57 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <extra.h>

#ifndef BONUS

void			init_data(t_vars *vars)
{
	vars->data.b.m.plane = (t_2vec){0, 0};
	vars->data.b.m.plane = (vars->data.b.map.sp_char == 'N')
		? (t_2vec){-0.66, 0} : vars->data.b.m.plane;
	vars->data.b.m.plane = (vars->data.b.map.sp_char == 'E')
		? (t_2vec){0, 0.66} : vars->data.b.m.plane;
	vars->data.b.m.plane = (vars->data.b.map.sp_char == 'S')
		? (t_2vec){0.66, 0} : vars->data.b.m.plane;
	vars->data.b.m.plane = (vars->data.b.map.sp_char == 'W')
		? (t_2vec){0, -0.66} : vars->data.b.m.plane;
	vars->data.img_ptr1 = &vars->data.img1;
	vars->data.img_ptr2 = &vars->data.img2;
}

#else

static void		init_bonus(t_bonus *bn, t_res res)
{
	bn->cr_length = (res.x > res.y) ? res.y / 75 : res.x / 75;
	bn->cr_width = bn->cr_length / 5;
	bn->cr_col = color_input(0, 0, 255, 0);
}

void			init_data(t_vars *vars)
{
	vars->data.b.m.plane = (t_2vec){0, 0};
	vars->data.b.m.plane = (vars->data.b.map.sp_char == 'N')
		? (t_2vec){-0.66, 0} : vars->data.b.m.plane;
	vars->data.b.m.plane = (vars->data.b.map.sp_char == 'E')
		? (t_2vec){0, 0.66} : vars->data.b.m.plane;
	vars->data.b.m.plane = (vars->data.b.map.sp_char == 'S')
		? (t_2vec){0.66, 0} : vars->data.b.m.plane;
	vars->data.b.m.plane = (vars->data.b.map.sp_char == 'W')
		? (t_2vec){0, -0.66} : vars->data.b.m.plane;
	init_bonus(&vars->data.b.bonus, vars->data.b.res);
	vars->data.img_ptr1 = &vars->data.img1;
	vars->data.img_ptr2 = &vars->data.img2;
}

#endif
