/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pxloop.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/01 21:30:30 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/14 22:33:31 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <extra.h>

void			calc_step(t_base *b)
{
	if (b->m.raydir.x < 0)
	{
		b->m.step.x = -1;
		b->m.sidedist.x = (b->map.sp_pos.x - b->m.map.x) * b->m.deltadist.x;
	}
	else
	{
		b->m.step.x = 1;
		b->m.sidedist.x = (b->m.map.x + 1.0 - b->map.sp_pos.x)
			* b->m.deltadist.x;
	}
	if (b->m.raydir.y < 0)
	{
		b->m.step.y = -1;
		b->m.sidedist.y = (b->map.sp_pos.y - b->m.map.y) * b->m.deltadist.y;
	}
	else
	{
		b->m.step.y = 1;
		b->m.sidedist.y = (b->m.map.y + 1.0 - b->map.sp_pos.y) *
			b->m.deltadist.y;
	}
}

void			dda_hit_checker(t_base *b)
{
	while (b->m.hit == 0)
	{
		if (b->m.sidedist.x < b->m.sidedist.y)
		{
			b->m.sidedist.x += b->m.deltadist.x;
			b->m.map.x += b->m.step.x;
			b->m.side = 0;
		}
		else
		{
			b->m.sidedist.y += b->m.deltadist.y;
			b->m.map.y += b->m.step.y;
			b->m.side = 1;
		}
		if (b->map.ptr[b->m.map.y][b->m.map.x] == '1')
			b->m.hit = 1;
	}
}

void			calc_line_height(t_base *b)
{
	if (b->m.side == 0)
		b->m.perpwalldist = (b->m.map.x - b->map.sp_pos.x
			+ (1 - b->m.step.x) / 2) / b->m.raydir.x;
	else
		b->m.perpwalldist = (b->m.map.y - b->map.sp_pos.y
		+ (1 - b->m.step.y) / 2) / b->m.raydir.y;
	b->m.line_height = (int)(b->res.y / b->m.perpwalldist);
	b->m.draw_start = -b->m.line_height / 2 + b->res.y / 2;
	if (b->m.draw_start < 0)
		b->m.draw_start = 0;
	b->m.draw_end = b->m.line_height / 2 + b->res.y / 2;
	if (b->m.draw_end >= b->res.y)
		b->m.draw_end = b->res.y - 1;
}

#ifndef BONUS

/*
** Without bonus
*/

int				pxloop(t_vars *vars)
{
	int		x;

	x = 0;
	vars->data.addr = mlx_get_data_addr(*vars->data.img_ptr2, &vars->data.bpp,
		&vars->data.len, &vars->data.endian);
	if (vars->data.addr == NULL)
		return (errors(ERR_IN_MLX));
	floor_ceiling_fill(&vars->data);
	while (x < vars->data.b.res.x)
	{
		basic_math(&vars->data.b, x);
		calc_step(&vars->data.b);
		dda_hit_checker(&vars->data.b);
		calc_line_height(&vars->data.b);
		vertical_line(x, &vars->data, wall_col(&vars->data.b));
		x++;
	}
	// ft_printf("\x1b[38;5;83m[+]\x1b[0m Ready to play!\n");
	switch_ptr(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, *vars->data.img_ptr1, 0, 0);
	return (1);
}

#else

/*
** With bonus
*/

int				pxloop(t_vars *vars)
{
	int		x;

	x = 0;
	vars->data.addr = mlx_get_data_addr(*vars->data.img_ptr2, &vars->data.bpp,
		&vars->data.len, &vars->data.endian);
	if (vars->data.addr == NULL)
		return (errors(ERR_IN_MLX));
	floor_ceiling_fill(&vars->data);
	while (x < vars->data.b.res.x)
	{
		basic_math(&vars->data.b, x);
		calc_step(&vars->data.b);
		dda_hit_checker(&vars->data.b);
		calc_line_height(&vars->data.b);
		vertical_line(x, &vars->data, wall_col(&vars->data.b));
		x++;
	}
	minimap(&vars->data, (t_res){0, 0}, (t_res){0, 0});
	cross_h(&vars->data, &vars->data.b.bonus);
	// ft_printf("\x1b[38;5;83m[+]\x1b[0m Ready to play!\n");
	switch_ptr(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, *vars->data.img_ptr1, 0, 0);
	return (1);
}

#endif
