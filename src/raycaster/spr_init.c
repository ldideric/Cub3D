/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spr_init.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/24 22:05:31 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/27 23:46:32 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void		sort_sprites(t_spr *spr, double *dist, int max, t_res i)
{
	t_2vec	tmp;
	int		a;

	while (i.x < max)
	{
		i.y = i.x + 1;
		while (i.y < max)
		{
			if (dist[i.x] < dist[i.y])
			{
				a = dist[i.x];
				dist[i.x] = dist[i.y];
				dist[i.y] = a;
				tmp = spr->pos[i.x];
				spr->pos[i.x] = spr->pos[i.y];
				spr->pos[i.y] = tmp;
				a = spr->sp[i.x];
				spr->sp[i.x] = spr->sp[i.y];
				spr->sp[i.y] = a;
			}
			++i.y;
		}
		++i.x;
	}
}

void			init_spr(t_spr *spr_data)
{
	double	spr_dist[spr_data->max];
	int		spr_ord[spr_data->max];
	int		i;

	g_m.s.num_spr = spr_data->max;
	i = 0;
	while (i < g_m.s.num_spr)
	{
		spr_ord[i] = i;
		spr_dist[i] =
			((g_m.pos.x - spr_data->pos[i].x) * (g_m.pos.x - spr_data->pos[i].x)
		+ (g_m.pos.y - spr_data->pos[i].y) * (g_m.pos.y - spr_data->pos[i].y));
		i++;
	}
	sort_sprites(spr_data, spr_dist, g_m.s.num_spr, (t_res){0, 0});
}
