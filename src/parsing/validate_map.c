/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_map.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/02 13:12:20 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/05 19:55:33 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <extra.h>

static int	val_spawn(t_map *map, int x, int y)
{
	if (ft_isalpha(map->sp_char))
		return (0);
	map->sp_pos.x = x;
	map->sp_pos.y = y;
	map->sp_char = map->ptr[y][x];
	map->sp_dir = (map->sp_char == 'N') ? (t_res){0, 1} : map->sp_dir;
	map->sp_dir = (map->sp_char == 'E') ? (t_res){1, 0} : map->sp_dir;
	map->sp_dir = (map->sp_char == 'S') ? (t_res){0, -1} : map->sp_dir;
	map->sp_dir = (map->sp_char == 'W') ? (t_res){-1, 0} : map->sp_dir;
	return (1);
}

static int	val_wall(char **map, int x, int y)
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
	return (1);
}

int			val_map(t_map *map)
{
	t_res	p;

	p.y = 0;
	map->sp_char = '0';
	map->sp_dir = (t_res){0, 0};
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
					return (errors(ERR_TWO_SP));
			p.x++;
		}
		p.y++;
	}
	return (1);
}
