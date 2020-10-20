/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   extra1.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 15:23:37 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/20 00:41:19 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void		my_mlx_pixel_put(int x, int y, int color)
{
	char		*dst;

	dst = g_vars.data.addr + (y * g_vars.data.len + x * (g_vars.data.bpp / 8));
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
	free_arr(ptr);
	return (new);
}

void		free_arr(char **s)
{
	int i;

	i = 0;
	while (s[i][0] != '\0')
	{
		free(s[i]);
		i++;
	}
	free(s);
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

void		switch_ptr(void)
{
	void	*tmp;

	tmp = *g_vars.data.img_ptr1;
	*g_vars.data.img_ptr1 = *g_vars.data.img_ptr2;
	*g_vars.data.img_ptr2 = tmp;
}
