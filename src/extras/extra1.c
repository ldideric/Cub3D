/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   extra1.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 15:23:37 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/14 22:30:22 by ldideric      ########   odam.nl         */
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
	if (ptr == NULL)
		return (NULL);
	while (ptr[i][0] != '\0')
		i++;
	new = (char **)malloc(sizeof(char *) * (i + 2));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (ptr[i][0] != '\0')
	{
		new[i] = ft_strdup(ptr[i]);
		i++;
	}
	free(ptr);
	return (new);
}

int			int_checker(int a, int max)
{
	return (a >= 0 && a <= max);
}

t_rgb		color_input(int r, int g, int b, int a)
{
	t_rgb	color;

	color.packed.r = r;
	color.packed.g = g;
	color.packed.b = b;
	color.packed.a = a;
	return (color);
}

void		switch_ptr(t_vars *vars)
{
	void	*tmp;

	tmp = *vars->data.img_ptr1;
	*vars->data.img_ptr1 = *vars->data.img_ptr2;
	*vars->data.img_ptr2 = tmp;
}
