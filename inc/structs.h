/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/12 14:29:42 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/22 15:50:34 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/*
** Struct used in coloring union
*/
typedef struct		s_col
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;
}					t_col;

/*
** Union used for colors
*/
typedef union		u_rgb
{
	unsigned int	color;
	t_col			packed;
}					t_rgb;

/*
** Simple struct for two integers
*/
typedef struct		s_res
{
	int				x;
	int				y;
}					t_res;

/*
** Simple struct for two doubles
*/
typedef struct		s_2vec
{
	double			x;
	double			y;
}					t_2vec;

/*
** Sprites
*/
typedef struct		s_spr
{
	char			*path;
	void			*img;
	char			*addr;
	int				bpp;
	int				len;
	int				endian;
	int				x;
	int				y;
}					t_spr;

/*
** Data read from the map
*/
typedef struct		s_map
{
	char			**ptr;
	t_2vec			sp_pos;
	t_2vec			sp_dir;
	char			sp_char;
	int				height;
}					t_map;

/*
** Mathematical variables used for textures
*/
typedef struct		s_texm
{
	int				x;
	int				y;
	double			step;
	double			pos;
	double			wall_x;
}					t_texm;

/*
** All mathematical variables used in raycasting
*/
typedef struct		s_math
{
	double			move_speed;
	double			rot_speed;
	t_res			res;
	t_2vec			pos;
	t_res			map;
	t_2vec			plane;
	double			camera_x;
	t_2vec			raydir;
	t_2vec			sidedist;
	t_2vec			deltadist;
	double			perpwalldist;
	t_res			step;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	t_texm			tex;
}					t_math;

/*
** Info about keypresses
*/
typedef struct		s_key
{
	int				w;
	int				a;
	int				s;
	int				d;
	int				larr;
	int				rarr;
}					t_key;

# ifndef BONUS

/*
** All basic input from .cub file
*/
typedef struct		s_base
{
	char			*file;
	char			*line;
	t_map			map;
	t_res			res;
	t_spr			spr[5];
	t_rgb			floor;
	t_rgb			ceiling;
}					t_base;

# else

/*
** Variables used for bonus functions
*/
typedef struct		s_bonus
{
	t_rgb			cr_col;
	t_res			*cr_pix;
	int				cr_pmax;
	int				cr_length;
	int				cr_width;
}					t_bonus;

/*
** All basic input from .cub file + bonus
*/
typedef struct		s_base
{
	char			*file;
	char			*line;
	t_map			map;
	t_math			m;
	t_res			res;
	t_spr			spr[5];
	t_rgb			floor;
	t_rgb			ceiling;
	t_bonus			bonus;
}					t_base;

# endif

/*
** Struct used for MLX functions
*/
typedef struct		s_data
{
	void			*img1;
	void			*img2;
	void			**img_ptr1;
	void			**img_ptr2;
	char			*addr;
	t_key			key;
	int				bpp;
	int				len;
	int				endian;
	t_base			b;
}					t_data;

/*
** Main struct with all the data
*/
typedef struct		s_vars
{
	void			*mlx;
	void			*win;
	t_data			data;
}					t_vars;

#endif
