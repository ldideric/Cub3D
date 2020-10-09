/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   img_read.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/09 02:39:50 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/09 02:45:52 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <extra.h>

int			load_img(t_vars *vars)
{
	void	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(vars->mlx, vars->data.b.sprites.s, &img_width, &img_height);
}
