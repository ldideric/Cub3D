/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spr_init.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/24 22:05:31 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/24 22:07:43 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void		sort_sprites(t_spr *spr, double *dist, int amount)
{
	t_2vec	tmp;
	int		a;
	int		i;
	int		j;

	i = 0;
	while (i < amount)
	{
		j = i + 1;
		while (j < amount)
		{
			if (dist[i] < dist[j])
			{
				a = dist[i];
				dist[i] = dist[j];
				dist[j] = a;
				tmp = spr->pos[i];
				spr->pos[i] = spr->pos[j];
				spr->pos[j] = tmp;
			}
			++j;
		}
		++i;
	}
}

void			init_spr(t_spr *spr)
{
	double	spr_dist[g_vars.data.b.spr.max];
	int		spr_ord[g_vars.data.b.spr.max];
	int		i;

	g_m.s.num_spr = g_vars.data.b.spr.max;
	i = 0;
	while (i < g_m.s.num_spr)
	{
		spr_ord[i] = i;
		spr_dist[i] = ((g_m.pos.x - spr->pos[i].x) * (g_m.pos.x - spr->pos[i].x)
			+ (g_m.pos.y - spr->pos[i].y) * (g_m.pos.y - spr->pos[i].y));
		i++;
	}
	sort_sprites(spr, spr_dist, g_m.s.num_spr);
}
