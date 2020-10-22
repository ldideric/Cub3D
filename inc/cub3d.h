/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 10:28:36 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/22 20:02:32 by ldideric      ########   odam.nl         */
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
** global variables
*/

t_vars				g_vars;
t_math				g_m;

/*
** Reader functions
*/

typedef int			(*t_read)(char *s, t_base *b);

int					rd_start(t_base *b);
int					rd_map(t_base *b, int fd);

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

void				basic_math(int x);
void				calc_step(void);
void				dda_hit_checker(void);
void				calc_line_height(void);
void				vertical_line(int x, unsigned int col);
void				floor_ceiling_fill(void);

void				which_texture(int x);
void				tex_loop(t_spr *spr, int x);
void				tex_pix_calc(t_spr *spr);
t_rgb				get_color(t_spr *spr, int x, int y);

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

void				my_mlx_pixel_put(int x, int y, int color);

char				first_char(char *s);
int					tab_checker(char *s);

int					int_checker(int a, int max);
t_rgb				color_input(int r, int g, int b, int a);

int					errors(char *error);
int					parse_err(char *s);

/*
** Hooks
*/

int					hooks(void);

int					button_press_hooks(int keycode);
int					button_release_hooks(int keycode);
int					destroy_window_hooks(int keycode);

int					move_hooks(int keycode, int o);
void				move_button_press(int keycode);
void				move_button_release(int keycode);

# ifdef BONUS

/*
** Bonus functions
*/

void				minimap(t_data *d, t_res i, t_res j);
void				cross_h(t_data *d, t_bonus *bn);

# endif
#endif
