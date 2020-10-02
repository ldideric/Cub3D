/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_map.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/02 13:12:20 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/02 15:27:54 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <extra.h>

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
	map->height = height_map(*map);
	map->sp_char = '0';
	while (map->map[p.y])
	{
		p.x = 0;
		while (map->map[p.y][p.x])
		{
			if (ft_isdigit(map->map[p.y][p.x]))
				if (!val_wall(map->map, p.x, p.y))
					return (errors(ERR_MAP_PR));
			if (ft_isalpha(map->map[p.y][p.x]))
			{
				if (ft_isalpha(map->sp_char))
					return (errors(ERR_TWO_SP));
				else
					map->sp_char = map->map[p.y][p.x];
			}
			p.x++;
		}
		p.y++;
	}
	return (1);
}
