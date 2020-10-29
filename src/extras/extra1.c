/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   extra1.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 15:23:37 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/28 15:00:24 by ldideric      ########   odam.nl         */
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

t_res			*ft_add_res(t_res *old, t_res p)
{
	t_res	*new;
	int		i;

	i = 0;
	while (old[i].x != -1)
		i++;
	new = malloc(sizeof(t_res) * (i + 2));
	i = 0;
	while (old[i].x != -1)
	{
		new[i].x = old[i].x;
		new[i].y = old[i].y;
		i++;
	}
	new[i] = p;
	new[i + 1] = (t_res){-1, -1};
	free(old);
	return (new);
}

t_2vec			*ft_add_2vec(t_2vec *old, t_2vec p)
{
	t_2vec	*new;
	int		i;

	i = 0;
	while (old[i].x != -1)
		i++;
	new = malloc(sizeof(t_2vec) * (i + 2));
	i = 0;
	while (old[i].x != -1)
	{
		new[i].x = old[i].x;
		new[i].y = old[i].y;
		i++;
	}
	new[i] = p;
	new[i + 1] = (t_2vec){-1, -1};
	free(old);
	return (new);
}

int				*ft_add_int(int *old, int p)
{
	int		*new;
	int		i;

	i = 0;
	while (old[i] != -1)
		i++;
	new = malloc(sizeof(int) * (i + 2));
	i = 0;
	while (old[i] != -1)
	{
		new[i] = old[i];
		i++;
	}
	new[i] = p;
	new[i + 1] = -1;
	free(old);
	return (new);
}

void			t_tex_bzero(t_base *b)
{
	int		i;

	i = 0;
	while (i < 9)
	{
		b->spr_img[i].path = NULL;
		if (i < 5)
			b->tex_img[i].path = NULL;
		i++;
	}
}
