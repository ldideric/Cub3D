/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_cub.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/02 13:12:20 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/27 23:51:16 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int		val_spawn(t_map *map, int x, int y)
{
	if (ft_isalpha(map->sp_char))
		return (errors(ERR_TWO_SP));
	if (!ft_ismatch(map->ptr[y][x], "NESW"))
		return (errors(ERR_SPAWN_));
	map->sp_pos = (t_2vec){x + 0.5, y + 0.5};
	map->sp_char = map->ptr[y][x];
	map->sp_dir = (map->sp_char == 'N') ? (t_2vec){0, -1} : map->sp_dir;
	map->sp_dir = (map->sp_char == 'E') ? (t_2vec){1, 0} : map->sp_dir;
	map->sp_dir = (map->sp_char == 'S') ? (t_2vec){0, 1} : map->sp_dir;
	map->sp_dir = (map->sp_char == 'W') ? (t_2vec){-1, 0} : map->sp_dir;
	return (1);
}

static void		sprite_data(t_spr *spr_data, t_2vec p, char c)
{
	if (spr_data->max == 0)
	{
		spr_data->pos = malloc(sizeof(t_2vec) * 2);
		spr_data->pos[spr_data->max] = (t_2vec){p.x + 0.5, p.y + 0.5};
		spr_data->pos[spr_data->max + 1] = (t_2vec){-1, -1};
		spr_data->sp = malloc(sizeof(int) * 2);
		spr_data->sp[spr_data->max] = c - '0';
		spr_data->sp[spr_data->max + 1] = -1;
	}
	else
	{
		spr_data->pos = ft_add_2vec(spr_data->pos,
			(t_2vec){p.x + 0.5, p.y + 0.5});
		spr_data->sp = ft_add_int(spr_data->sp, c - '0');
	}
	spr_data->max++;
}

static int		val_wall(char **map, int x, int y)
{
	static int	test[16] =
	{-1, -1, 0, -1, 1, -1, -1, 0, 1, 0, -1, 1, 0, 1, 1, 1};
	int			i;

	i = 0;
	if (map[y][x] == '0')
	{
		if (y == 0)
			return (0);
		while (i < 16)
		{
			if (map[y + test[i]][x + test[i + 1]] == ' ' ||
				map[y + test[i]][x + test[i + 1]] == '\n' ||
				map[y + test[i]][x + test[i + 1]] == '\0')
				return (0);
			i = i + 2;
		}
	}
	else if (map[y][x] >= '2' && map[y][x] <= '9')
		sprite_data(&g_vars.data.b.spr_data, (t_2vec){x, y}, map[y][x]);
	return (1);
}

int				val_map(t_map *map)
{
	t_res	p;

	p.y = 0;
	map->sp_char = '0';
	map->sp_dir = (t_2vec){0, 0};
	g_vars.data.b.spr_data.max = 0;
	while (p.y < map->height)
	{
		p.x = 0;
		while (map->ptr[p.y][p.x])
		{
			if (ft_isdigit(map->ptr[p.y][p.x]))
				if (!val_wall(map->ptr, p.x, p.y))
					return (errors(ERR_MAP_PR));
			if (ft_isalpha(map->ptr[p.y][p.x]))
				if (!val_spawn(map, p.x, p.y))
					return (0);
			p.x++;
		}
		p.y++;
	}
	return (1);
}

int				val_res(void)
{
	t_res	real;

	if (g_vars.data.b.save.save == 1)
		return (1);
	mlx_get_screen_size(g_vars.mlx, &real.x, &real.y);
	if (g_vars.data.b.res.x > real.x || g_vars.data.b.res.y > real.y)
		ft_printf("\x1b[38;5;208m[!]\x1b[0m Adjusted screen size\n");
	if (g_vars.data.b.res.x > real.x)
		g_vars.data.b.res.x = real.x;
	if (g_vars.data.b.res.y > real.y)
		g_vars.data.b.res.y = real.y;
	return (1);
}
