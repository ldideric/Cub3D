/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   extra1.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 15:23:37 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/02 15:19:48 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <extra.h>

void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char		*dst;

	dst = data->addr + (y * data->len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

char		**ft_realloc_arr(char **ptr)
{
	char	**new;
	int		i;

	i = 0;
	while (ptr[i][0] != '\0')
		i++;
	new = (char **)malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (ptr[i][0] != '\0')
	{
		new[i] = ptr[i];
		i++;
	}
	new[i] = "\0";
	free(ptr);
	return (new);
}

int			height_map(t_map map)
{
	int		height;
	int		i;

	i = 0;
	height = 0;
	while (map.map[i][0] != '\0')
	{
		height++;
		i++;
	}
	return (height);
}

int			int_checker(int a, int max)
{
	return (a >= 0 && a <= max);
}
