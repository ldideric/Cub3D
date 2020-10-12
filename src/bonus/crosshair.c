/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   crosshair.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/12 14:06:31 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/12 17:08:46 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <extra.h>

void			cross_check(t_data *d, t_bonus *bn, int gap, t_res p)
{
	int		length;

	length = gap / 2 + bn->cr_length;
	if (
		(
			(
				(p.x + bn->cr_width >= d->b.res.x / 2)
				&&
				(p.x - bn->cr_width <= d->b.res.x / 2)
			)
			||
			(
				(p.y + bn->cr_width >= d->b.res.y / 2)
				&&
				(p.y - bn->cr_width <= d->b.res.y / 2)
			)
		)
		&&
		(
			(
				(p.x < d->b.res.x / 2 + length)
				&&
				(p.x > d->b.res.x / 2 - length)
			)
			||
			(
				(p.y < d->b.res.y / 2 + length)
				&&
				(p.y > d->b.res.y / 2 - length)
			)
		)
	)
		my_mlx_pixel_put(d, p.x, p.y, bn->cr_col.color);
}

void			cross_h(t_data *d, t_bonus *bn)
{
	int		gap;
	t_res	max;
	t_res	p;

	gap = bn->cr_length / 4;
	max.x = d->b.res.x;
	max.y = d->b.res.y;
	p.y = 0;
	while (p.y < max.y)
	{
		p.x = 0;
		while (p.x < max.x)
		{
			cross_check(d, bn, gap, p);
			p.x++;
		}
		p.y++;
	}
}
