/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 10:28:36 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/05 19:48:16 by ldideric      ########   odam.nl         */
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

# define WIN_NAME "Gameboy Advanced"
# define TRUE	1
# define FALSE	0

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
	t_res			sp_pos;
	t_res			sp_dir;
	char			sp_char;
	int				height;
}					t_map;

/*
** all basic input from .cub file
*/
typedef struct		s_base
{
	char			*file;
	char			*line;
	t_map			map;
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

typedef int			(*t_read)(char *s, t_base *b);
// typedef void		(*t_read_o)(char *s, t_objs *o);
// typedef t_vect		(*t_hit_o)(t_vect *rd, t_data *data, t_objs *o);

void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
char				**ft_realloc_arr(char **ptr);
int					int_checker(int a, int max);

void				hooks(t_vars *vars);
int					errors(char *error);

/*
** Reader functions
*/

void				pix_loop(t_data *d);

// int					reader(t_base *b, char *s, int fd, int ret);
int					rd_start(t_base *b);
int					rd_struct_free(char *s, t_base *b);
int					val_map(t_map *map);
// t_objs				*read_loop(t_base *b, t_objs *o, char *s);
// int					obj_cntr(char *s);
// int					cam_light_cntr(char *s, char c);
// void				*reader_free(void *a, void *b, void *c, void *d);

int					rd_sprites(char *s, t_base *b);
int					rd_res(char *s, t_base *b);
int					rd_ground_sky(char *s, t_base *b);
int					rd_rgb(char *s, t_rgb *rgb);

#endif
