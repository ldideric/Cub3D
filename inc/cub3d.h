/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 10:28:36 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/15 18:19:41 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <defines.h>
# include <structs.h>

# include <libft.h>
# include <ft_printf.h>
# include <get_next_line.h>

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

/*
** global variable with all data
*/
t_vars				g_vars;

/*
** Reader functions
*/

typedef int			(*t_read)(char *s, t_base *b);

int					rd_start(t_base *b);
int					rd_sprites(char *s, t_base *b);
int					rd_res(char *s, t_base *b);
int					rd_ground_sky(char *s, t_base *b);
int					rd_rgb(char *s, t_rgb *rgb);

int					val_map(t_map *map);
int					val_res(void);

/*
** Math functions
*/

int					pxloop(t_data *d);

void				basic_math(t_base *b, int x);
void				calc_step(t_base *b);
void				dda_hit_checker(t_base *b);
void				calc_line_height(t_base *b);
void				vertical_line(int x, t_data *d, unsigned int col);
void				floor_ceiling_fill(t_data *d);

int					move_up(void);
int					move_down(void);
int					move_right(void);
int					move_left(void);
int					rot_right(void);
int					rot_left(void);

/*
** extra functions
*/

void				init_data(void);

void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
char				**ft_realloc_arr(char **ptr);
int					int_checker(int a, int max);
t_rgb				color_input(int r, int g, int b, int a);
void				switch_ptr(void);

void				hooks(void);
int					errors(char *error);
int					parse_err(char *s);

# ifdef BONUS

/*
** Bonus functions
*/

void				minimap(t_data *d, t_res i, t_res j);
void				cross_h(t_data *d, t_bonus *bn);

# endif
#endif
