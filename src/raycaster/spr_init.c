/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spr_init.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/24 22:05:31 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/29 03:34:46 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void		sort_spr_all(t_spr *spr_data, double **dist, t_res i)
{
	t_2vec	vtmp;
	int		itmp;

	itmp = (*dist)[i.x];
	(*dist)[i.x] = (*dist)[i.y];
	(*dist)[i.y] = itmp;
	vtmp = spr_data->pos[i.x];
	spr_data->pos[i.x] = spr_data->pos[i.y];
	spr_data->pos[i.y] = vtmp;
	itmp = spr_data->sp[i.x];
	spr_data->sp[i.x] = spr_data->sp[i.y];
	spr_data->sp[i.y] = itmp;
	itmp = spr_data->trans[i.x];
	spr_data->trans[i.x] = spr_data->trans[i.y];
	spr_data->trans[i.y] = itmp;
}

static void		sort_sprites(t_spr *spr_data, double *dist, int max, t_res i)
{
	while (i.x < max)
	{
		i.y = i.x + 1;
		while (i.y < max)
		{
			if (dist[i.x] < dist[i.y])
				sort_spr_all(spr_data, &dist, i);
			++i.y;
		}
		++i.x;
	}
}

void			spr_init(t_spr *spr_data)
{
	double	spr_dist[spr_data->max];
	int		i;

	g_m.s.num_spr = spr_data->max;
	i = 0;
	while (i < g_m.s.num_spr)
	{
		spr_dist[i] =
			((g_m.pos.x - spr_data->pos[i].x) * (g_m.pos.x - spr_data->pos[i].x)
		+ (g_m.pos.y - spr_data->pos[i].y) * (g_m.pos.y - spr_data->pos[i].y));
		i++;
	}
	sort_sprites(spr_data, spr_dist, g_m.s.num_spr, (t_res){0, 0});
}
