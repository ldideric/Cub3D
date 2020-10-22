/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   extra1.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 15:23:37 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/22 20:02:17 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void		my_mlx_pixel_put(int x, int y, int color)
{
	char		*dst;

	dst = g_vars.data.addr + (y * g_vars.data.len + x * (g_vars.data.bpp / 8));
	*(unsigned int *)dst = color;
}

int			int_checker(int a, int max)
{
	return (a >= 0 && a <= max);
}

char		first_char(char *s)
{
	while (*s == ' ' && *s != '\0' && *s)
		s++;
	return (*s);
}

int			tab_checker(char *s)
{
	while (*s != '\0')
	{
		if (*s == '\t')
			return (1);
		s++;
	}
	return (0);
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
