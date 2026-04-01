#include <stdlib.h>
#include <MLX42/MLX42.h>
#include <libft.h>

typedef struct s_mlx42_bridge
{
	mlx_t		*mlx;
	mlx_image_t	*window_img;
	int32_t		window_img_instance;
	int			(*press_cb)(int);
	int			(*release_cb)(int);
	int			(*close_cb)(int);
	int			(*loop_cb)();
	void		*loop_param;
}t_mlx42_bridge;

static void	key_hook_bridge(mlx_key_data_t keydata, void *param)
{
	t_mlx42_bridge	*ctx;

	ctx = (t_mlx42_bridge *)param;
	if (!ctx)
		return ;
	if ((keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
		&& ctx->press_cb)
		ctx->press_cb((int)keydata.key);
	if (keydata.action == MLX_RELEASE && ctx->release_cb)
		ctx->release_cb((int)keydata.key);
}

static void	close_hook_bridge(void *param)
{
	t_mlx42_bridge	*ctx;

	ctx = (t_mlx42_bridge *)param;
	if (ctx && ctx->close_cb)
		ctx->close_cb(0);
}

static void	loop_hook_bridge(void *param)
{
	t_mlx42_bridge	*ctx;

	ctx = (t_mlx42_bridge *)param;
	if (ctx && ctx->loop_cb)
		ctx->loop_cb(ctx->loop_param);
}

void	*c3d_mlx_init(void)
{
	t_mlx42_bridge	*ctx;

	ctx = ft_calloc(1, sizeof(t_mlx42_bridge));
	if (!ctx)
		return (NULL);
	ctx->window_img_instance = -1;
	return (ctx);
}

void	*c3d_mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title)
{
	t_mlx42_bridge	*ctx;

	ctx = (t_mlx42_bridge *)mlx_ptr;
	if (!ctx)
		return (NULL);
	if (!ctx->mlx)
		ctx->mlx = mlx_init(size_x, size_y, title, false);
	if (!ctx->mlx)
		return (NULL);
	mlx_key_hook(ctx->mlx, &key_hook_bridge, ctx);
	mlx_close_hook(ctx->mlx, &close_hook_bridge, ctx);
	return (ctx);
}

void	*c3d_mlx_new_image(void *mlx_ptr, int width, int height)
{
	t_mlx42_bridge	*ctx;

	ctx = (t_mlx42_bridge *)mlx_ptr;
	if (!ctx || !ctx->mlx)
		return (NULL);
	return (mlx_new_image(ctx->mlx, (uint32_t)width, (uint32_t)height));
}

char	*c3d_mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,
		int *size_line, int *endian)
{
	mlx_image_t	*img;

	img = (mlx_image_t *)img_ptr;
	if (!img)
		return (NULL);
	if (bits_per_pixel)
		*bits_per_pixel = 32;
	if (size_line)
		*size_line = (int)(img->width * 4);
	if (endian)
		*endian = 0;
	return ((char *)img->pixels);
}

int	c3d_mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr,
		int x, int y)
{
	t_mlx42_bridge	*ctx;
	mlx_image_t		*img;

	(void)win_ptr;
	ctx = (t_mlx42_bridge *)mlx_ptr;
	img = (mlx_image_t *)img_ptr;
	if (!ctx || !ctx->mlx || !img)
		return (0);
	if (ctx->window_img != img || ctx->window_img_instance < 0)
	{
		ctx->window_img = img;
		ctx->window_img_instance = mlx_image_to_window(ctx->mlx, img, x, y);
	}
	return (ctx->window_img_instance >= 0);
}

int	c3d_mlx_destroy_window(void *mlx_ptr, void *win_ptr)
{
	t_mlx42_bridge	*ctx;

	(void)win_ptr;
	ctx = (t_mlx42_bridge *)mlx_ptr;
	if (!ctx)
		return (0);
	if (ctx->mlx)
	{
		mlx_close_window(ctx->mlx);
		mlx_terminate(ctx->mlx);
	}
	free(ctx);
	return (1);
}

int	c3d_mlx_loop(void *mlx_ptr)
{
	t_mlx42_bridge	*ctx;

	ctx = (t_mlx42_bridge *)mlx_ptr;
	if (!ctx || !ctx->mlx)
		return (0);
	mlx_loop(ctx->mlx);
	return (1);
}

int	c3d_mlx_loop_hook(void *mlx_ptr, int (*f)(), void *param)
{
	t_mlx42_bridge	*ctx;

	ctx = (t_mlx42_bridge *)mlx_ptr;
	if (!ctx || !ctx->mlx || !f)
		return (0);
	ctx->loop_cb = f;
	ctx->loop_param = param;
	return (mlx_loop_hook(ctx->mlx, &loop_hook_bridge, ctx));
}

int	c3d_mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(),
		void *param)
{
	t_mlx42_bridge	*ctx;

	(void)x_mask;
	(void)param;
	ctx = (t_mlx42_bridge *)win_ptr;
	if (!ctx || !funct)
		return (0);
	if (x_event == 2)
		ctx->press_cb = (int (*)(int))funct;
	else if (x_event == 3)
		ctx->release_cb = (int (*)(int))funct;
	else if (x_event == 17)
		ctx->close_cb = (int (*)(int))funct;
	return (1);
}

int	c3d_mlx_do_key_autorepeatoff(void *mlx_ptr)
{
	(void)mlx_ptr;
	return (0);
}

void	*c3d_mlx_xpm_file_to_image(void *mlx_ptr, char *filename,
		int *width, int *height)
{
	t_mlx42_bridge	*ctx;
	xpm_t			*xpm;
	mlx_image_t		*img;
	mlx_texture_t	*tex;
	char			*png_path;
	size_t			len;

	ctx = (t_mlx42_bridge *)mlx_ptr;
	if (!ctx || !ctx->mlx || !filename)
		return (NULL);
	xpm = mlx_load_xpm42(filename);
	if (xpm)
	{
		img = mlx_texture_to_image(ctx->mlx, &xpm->texture);
		if (width)
			*width = (int)xpm->texture.width;
		if (height)
			*height = (int)xpm->texture.height;
		mlx_delete_xpm42(xpm);
		return (img);
	}
	len = ft_strlen(filename);
	if (len < 4 || ft_strncmp(filename + len - 4, ".xpm", 4) != 0)
		return (NULL);
	png_path = ft_strdup(filename);
	if (!png_path)
		return (NULL);
	png_path[len - 3] = 'p';
	png_path[len - 2] = 'n';
	png_path[len - 1] = 'g';
	tex = mlx_load_png(png_path);
	free(png_path);
	if (!tex)
		return (NULL);
	img = mlx_texture_to_image(ctx->mlx, tex);
	if (width)
		*width = (int)tex->width;
	if (height)
		*height = (int)tex->height;
	mlx_delete_texture(tex);
	return (img);
}

int	c3d_mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey)
{
	(void)mlx_ptr;
	mlx_get_monitor_size(0, sizex, sizey);
	return (1);
}

int	c3d_mlx_sync(int cmd, void *ptr)
{
	(void)cmd;
	(void)ptr;
	return (1);
}
