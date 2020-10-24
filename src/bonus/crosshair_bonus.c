/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   crosshair_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/12 14:06:31 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/24 17:24:08 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void			cross_pixel_put(t_bonus *bn)
{
	int i;

	i = 0;
	while (i < bn->cr_pmax)
	{
		my_mlx_pixel_put(bn->cr_pix[i].x, bn->cr_pix[i].y, bn->cr_col.color);
		i++;
	}
}

void			fill_cross_arr(t_bonus *bn, t_res p)
{
	if (bn->cr_pmax == 0)
	{
		bn->cr_pix = malloc(sizeof(t_res) * 2);
		bn->cr_pix[bn->cr_pmax] = p;
		bn->cr_pix[bn->cr_pmax + 1] = (t_res){-1, -1};
	}
	else
		bn->cr_pix = ft_add_res(bn->cr_pix, p);
}

void			cross_check(t_data *d, t_bonus *bn, int gap, t_res p)
{
	int		length;

	length = gap / 2 + bn->cr_length;
	if ((
		(p.x > (d->b.res.x / 2) - bn->cr_width)
			&& (p.x < (d->b.res.x / 2) + bn->cr_width)
			&& (p.y < (d->b.res.y / 2) + length)
			&& (p.y > (d->b.res.y / 2) - length)
			&& !(((p.y > (d->b.res.y / 2) - (gap / 2 + bn->cr_width / 2)))
				&& ((p.y < (d->b.res.y / 2) + (gap / 2 + bn->cr_width / 2)))))
	|| ((p.y > (d->b.res.y / 2) - bn->cr_width)
			&& (p.y < (d->b.res.y / 2) + bn->cr_width)
			&& (p.x < (d->b.res.x / 2) + length)
			&& (p.x > (d->b.res.x / 2) - length)
			&& !(((p.x > (d->b.res.x / 2) - (gap / 2 + bn->cr_width / 2)))
				&& ((p.x < (d->b.res.x / 2) + (gap / 2 + bn->cr_width / 2))))))
	{
		fill_cross_arr(bn, p);
		bn->cr_pmax++;
	}
}

void			cross_h(t_data *d, t_bonus *bn)
{
	int		gap;
	t_res	max;
	t_res	p;

	if (bn->cr_pmax == 0)
	{
		gap = bn->cr_length / 4;
		max.x = d->b.res.x;
		max.y = d->b.res.y;
		p.y = 0;
		bn->cr_pmax = 0;
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
	cross_pixel_put(bn);
}
