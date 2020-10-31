/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_data_ext.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/12 14:11:36 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/29 13:15:42 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void		init_spr_trans(t_tex *s, t_base *b)
{
	t_rgb	tmp;
	int		i;

	i = 0;
	b->spr_data.trans = malloc(sizeof(unsigned int) * 8);
	while (i < 8)
	{
		s = &g_vars.data.b.spr_img[i];
		if (s->path != NULL)
		{
			tmp = get_color(s, 1, 1);
			tmp.packed.a = 0;
			b->spr_data.trans[i] = tmp.color;
		}
		i++;
	}
}

void		init_spr_img_loop(t_tex *s, char *tmp)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		s = &g_vars.data.b.spr_img[i];
		if (s->path != NULL)
		{
			tmp = ft_strdup(s->path);
			if (ft_strncmp(tmp + (ft_strlen(tmp) - 4), ".xpm", 4) == 0)
				s->img = mlx_xpm_file_to_image(g_vars.mlx, tmp, &s->x, &s->y);
			/*else if (ft_strncmp(tmp + (ft_strlen(tmp) - 4), ".png", 4) == 0)
				s->img = mlx_png_file_to_image(g_vars.mlx, tmp, &s->x, &s->y);*/
			if (s->img == NULL)
				errors(ERR_SPR_IN);
			s->addr = mlx_get_data_addr(s->img, &s->bpp, &s->len, &s->endian);
			free(tmp);
		}
		i++;
	}
	init_spr_trans(s, &g_vars.data.b);
	g_m.s.zbuffer = (int *)malloc(sizeof(int) * (g_m.res.x + 1));
}

void		init_tex_img_loop(t_tex *tex, char *tmp)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		tex = &g_vars.data.b.tex_img[i];
		tmp = ft_strdup(tex->path);
		if (ft_strncmp(tmp + (ft_strlen(tmp) - 4), ".xpm", 4) == 0)
			tex->img = mlx_xpm_file_to_image(g_vars.mlx, tmp, &tex->x, &tex->y);
		/*else if (ft_strncmp(tmp + (ft_strlen(tmp) - 4), ".png", 4) == 0)
			tex->img = mlx_png_file_to_image(g_vars.mlx,
				tmp, &tex->x, &tex->y);*/
		if (tex->img == NULL)
			errors(ERR_SPR_IN);
		tex->addr = mlx_get_data_addr(tex->img, &tex->bpp,
			&tex->len, &tex->endian);
		free(tmp);
		i++;
	}
}

void		init_key(void)
{
	g_vars.data.key.w = 0;
	g_vars.data.key.a = 0;
	g_vars.data.key.s = 0;
	g_vars.data.key.d = 0;
	g_vars.data.key.larr = 0;
	g_vars.data.key.rarr = 0;
}
