/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 10:28:36 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/08 20:05:51 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <libft.h>
# include <ft_printf.h>
# include <get_next_line.h>

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

/*
** DEFINES ---------------------------------------------------- |
*/

# define WIN_NAME	"Gameboy Advanced"
# define TRUE		1
# define FALSE		0

# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_ESC	53
# define KEY_Q		12

/*
** ERROR MESSAGES
*/

# define ERR_PARSER	"Something went wrong with parsing the"
# define ERR_STRING	"\x1b[31mERROR\x1b[0m:\n%s %s sprite!"
# define ERR_IN_CUB	"\x1b[31mERROR\x1b[0m:\nWrong .cub file input!\n"
# define ERR_MALLOC	"\x1b[31mERROR\x1b[0m:\nMemory allocating failed."
# define ERR_IN_MLX	"\x1b[31mERROR\x1b[0m:\nSomething went wrong with MLX!"
# define ERR_NO_CUB	"\x1b[31mERROR\x1b[0m:\nNo .cub file given!"
# define ERR_IN_GNL	"\x1b[31mERROR\x1b[0m:\nSomething went wrong with GNL!"
# define ERR_TWO_SP	"\x1b[31mERROR\x1b[0m:\nTwo or more spawn points in map!"
# define ERR_MAP_PR	"\x1b[31mERROR\x1b[0m:\nWalls in map not correct!"

/*
** STRUCTS ---------------------------------------------------- |
*/

typedef struct		s_col
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;
}					t_col;

typedef union		u_rgb
{
	unsigned int	color;
	t_col			packed;
}					t_rgb;

typedef struct		s_res
{
	int				x;
	int				y;
}					t_res;

typedef struct		s_2vec
{
	double			x;
	double			y;
}					t_2vec;

typedef struct		s_spr
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
}					t_spr;

typedef struct		s_map
{
	char			**ptr;
	t_2vec			sp_pos;
	t_2vec			sp_dir;
	char			sp_char;
	int				height;
}					t_map;

typedef struct		s_math
{
	int				start;
	double			move_speed;
	double			rot_speed;
	t_2vec			plane;
	double			camera_x;
	t_2vec			raydir;
	t_res			map;
	t_2vec			sidedist;
	t_2vec			deltadist;
	double			perpwalldist;
	t_res			step;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
}					t_math;

/*
** all basic input from .cub file
*/
typedef struct		s_base
{
	char			*file;
	char			*line;
	t_map			map;
	t_math			m;
	t_res			res;
	t_spr			sprites;
	t_rgb			floor;
	t_rgb			ceiling;
}					t_base;

/*
** | ----------------------------------------------------------------------- |
*/

typedef struct		s_data
{
	void			*img;
	void			*temp;
	char			*addr;
	int				bpp;
	int				len;
	int				endian;
	t_base			b;
}					t_data;

typedef struct		s_vars
{
	void			*mlx;
	void			*win;
	t_data			data;
}					t_vars;

/*
** | ----------------------------------------------------------------------- |
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
** | ----------------------------------------------------------------------- |
*/

void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
char				**ft_realloc_arr(char **ptr);
int					int_checker(int a, int max);

void				hooks(t_vars *vars);
int					errors(char *error);

/*
** Reader functions
*/

typedef int			(*t_read)(char *s, t_base *b);

void				minimap(t_data *d, t_res i, t_res j, int size);

int					rd_start(t_base *b);
int					rd_sprites(char *s, t_base *b);
int					rd_res(char *s, t_base *b);
int					rd_ground_sky(char *s, t_base *b);
int					rd_rgb(char *s, t_rgb *rgb);
int					rd_struct_free(char *s, t_base *b);

int					val_map(t_map *map);

#endif
