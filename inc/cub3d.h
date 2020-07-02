/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 10:28:36 by ldideric      #+#    #+#                 */
/*   Updated: 2020/07/02 18:59:47 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <libft.h>
# include <ft_printf.h>

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

# define ERR_IN_CUB_FILE		0
# define ERR_MALLOC			1
# define ERR_MLX			2
# define ERR_NO_CUB			3

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
	int				x_max;
	int				y_max;
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

/*
** all basic input from .cub file
*/
typedef struct		s_base
{
	char			*file;
	t_res			res;
	t_spr			sprites;
	t_rgb			floor;
	t_rgb			ceiling;
	char			**map;
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

// typedef void		(*t_read_b)(char *s, t_base *b);
// typedef void		(*t_read_o)(char *s, t_objs *o);
// typedef t_vect		(*t_hit_o)(t_vect *rd, t_data *data, t_objs *o);

void				my_mlx_pixel_put(t_data *data, int x, int y, int color);

void				*errors(int error);
void				hooks(t_vars *vars);

/*
** Reader functions
*/

void				*reader(t_base *b);
// t_objs				*read_loop(t_base *b, t_objs *o, char *s);
// int					obj_cntr(char *s);
// int					cam_light_cntr(char *s, char c);
// void				*reader_free(void *a, void *b, void *c, void *d);

// char				*rd_vect(char *s, t_vect *vect);
// char				*rd_rgb(char *s, t_rgb *rgb);

// void				rd_res(char *s, t_base *t);
// void				rd_amb(char *s, t_base *t);
// void				rd_cam(char *s, t_base *t);
// void				rd_light(char *s, t_base *t);

// void				rd_sphere(char *s, t_objs *o);
// void				rd_plane(char *s, t_objs *o);
// void				rd_square(char *s, t_objs *o);
// void				rd_cylinder(char *s, t_objs *o);
// void				rd_triangle(char *s, t_objs *o);

#endif
