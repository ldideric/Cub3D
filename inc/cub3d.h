/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 10:28:36 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/12 15:01:02 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <libft.h>
# include <ft_printf.h>
# include <get_next_line.h>

# include <defines.h>
# include <structs.h>

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

/*
** Reader functions
*/

typedef int			(*t_read)(char *s, t_base *b);

void				minimap(t_data *d, t_res i, t_res j);
void				cross_h(t_data *d, t_bonus *bn);

int					rd_start(t_base *b);
int					rd_sprites(char *s, t_base *b);
int					rd_res(char *s, t_base *b);
int					rd_ground_sky(char *s, t_base *b);
int					rd_rgb(char *s, t_rgb *rgb);
int					rd_struct_free(char *s, t_base *b);

int					val_map(t_map *map);

/*
** Math functions
*/

int					pxloop(t_vars *vars);

void				basic_math(t_base *b, int x);
void				calc_step(t_base *b);
void				dda_hit_checker(t_base *b);
void				calc_line_height(t_base *b);
void				vertical_line(int x, t_data *d, t_rgb col);
t_rgb				wall_col(t_base *b);
void				floor_ceiling_fill(t_data *d);

int					move_up(t_vars *vars);
int					move_down(t_vars *vars);
int					move_right(t_vars *vars);
int					move_left(t_vars *vars);

/*
** extra functions
*/

void				init_data(t_vars *vars);

void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
char				**ft_realloc_arr(char **ptr);
int					int_checker(int a, int max);
t_rgb				color_input(int r, int g, int b, int a);

void				hooks(t_vars *vars);
int					errors(char *error);

#endif
