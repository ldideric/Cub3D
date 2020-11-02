/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   extra2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 20:49:35 by ldideric      #+#    #+#                 */
/*   Updated: 2020/11/02 20:49:58 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

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
