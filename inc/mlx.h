/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cub3d migration                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31                                  #+#    #+#             */
/*   Updated: 2026/03/31                                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_H
# define MLX_H

# include <stdbool.h>
# include <stdint.h>
# include <MLX42/MLX42.h>

void	*c3d_mlx_init(void);
void	*c3d_mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
void	*c3d_mlx_new_image(void *mlx_ptr, int width, int height);
char	*c3d_mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,
				int *size_line, int *endian);
int		c3d_mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr,
				int x, int y);
int		c3d_mlx_destroy_window(void *mlx_ptr, void *win_ptr);
int		c3d_mlx_loop(void *mlx_ptr);
int		c3d_mlx_loop_hook(void *mlx_ptr, int (*f)(), void *param);
int		c3d_mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(),
				void *param);
int		c3d_mlx_do_key_autorepeatoff(void *mlx_ptr);
void	*c3d_mlx_xpm_file_to_image(void *mlx_ptr, char *filename,
				int *width, int *height);
int		c3d_mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);
int		c3d_mlx_sync(int cmd, void *ptr);

# define mlx_init c3d_mlx_init
# define mlx_new_window c3d_mlx_new_window
# define mlx_new_image c3d_mlx_new_image
# define mlx_get_data_addr c3d_mlx_get_data_addr
# define mlx_put_image_to_window c3d_mlx_put_image_to_window
# define mlx_destroy_window c3d_mlx_destroy_window
# define mlx_loop c3d_mlx_loop
# define mlx_loop_hook c3d_mlx_loop_hook
# define mlx_hook c3d_mlx_hook
# define mlx_do_key_autorepeatoff c3d_mlx_do_key_autorepeatoff
# define mlx_xpm_file_to_image c3d_mlx_xpm_file_to_image
# define mlx_get_screen_size c3d_mlx_get_screen_size
# define mlx_sync c3d_mlx_sync

#endif
