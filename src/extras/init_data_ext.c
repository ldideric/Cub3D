/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_data_ext.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/12 14:11:36 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/28 00:30:25 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void		init_key(void)
{
	g_vars.data.key.w = 0;
	g_vars.data.key.a = 0;
	g_vars.data.key.s = 0;
	g_vars.data.key.d = 0;
	g_vars.data.key.larr = 0;
	g_vars.data.key.rarr = 0;
}

void		init_tex_img_loop(void)
{
	t_tex	*tex;
	char	*tmp;
	int		i;

	i = 0;
	while (i < 5)
	{
		tex = &g_vars.data.b.tex_img[i];
		tmp = ft_strtrim(tex->path, " \n\t");
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

void		init_spr_img_loop(void)
{
	t_tex	*sp;
	char	*tmp;
	int		i;

	i = 0;
	g_m.s.zbuffer = (int *)malloc(sizeof(int) * (g_m.res.x + 1));
	while (i < g_vars.data.b.spr_data.max) // HOW MANY DIFFERENT SPRITES ARE BEING ADDED
	{
		sp = &g_vars.data.b.spr_img[i];
		tmp = ft_strtrim(sp->path, " \n\t");
		if (ft_strncmp(tmp + (ft_strlen(tmp) - 4), ".xpm", 4) == 0)
			sp->img = mlx_xpm_file_to_image(g_vars.mlx, tmp, &sp->x, &sp->y);
		/*else if (ft_strncmp(tmp + (ft_strlen(tmp) - 4), ".png", 4) == 0)
			sp->img = mlx_png_file_to_image(g_vars.mlx, tmp, &sp->x, &sp->y);*/
		if (sp->img == NULL)
			errors(ERR_SPR_IN);
		sp->addr = mlx_get_data_addr(sp->img, &sp->bpp, &sp->len, &sp->endian);
		free(tmp);
		i++;
	}
}
