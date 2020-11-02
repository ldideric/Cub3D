/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reader_map.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/20 21:10:30 by ldideric      #+#    #+#                 */
/*   Updated: 2020/11/02 20:35:09 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void		free_arr(char **s)
{
	int i;

	i = 0;
	while (s[i][0] != '\n')
	{
		free(s[i]);
		i++;
	}
	free(s);
}

static char		**ft_realloc_arr(char **ptr)
{
	char	**new;
	int		i;

	i = 0;
	if (ptr == NULL)
		return (NULL);
	while (ptr[i][0] != '\n')
		i++;
	new = (char **)malloc(sizeof(char *) * (i + 2));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (ptr[i][0] != '\n')
	{
		new[i] = ft_strdup(ptr[i]);
		i++;
	}
	free_arr(ptr);
	return (new);
}

static int		rd_map_alloc(t_base *b, int start)
{
	if (start == TRUE)
		b->map.ptr = (char **)malloc(sizeof(char *) * 2);
	else
		b->map.ptr = ft_realloc_arr(b->map.ptr);
	if (b->map.ptr == NULL)
		return (errors(ERR_MALLOC));
	b->map.ptr[b->map.height] = ft_strdup(b->line);
	if (b->map.ptr[b->map.height] == NULL)
		return (errors(ERR_MALLOC));
	b->map.ptr[b->map.height + 1] = "\n";
	return (1);
}

int				rd_map(t_base *b, int fd)
{
	int		ret;

	ret = 1;
	b->map.height = 0;
	b->map.ptr = NULL;
	if (rd_map_alloc(b, TRUE) == 0)
		return (0);
	b->map.height++;
	while (ret > 0)
	{
		free(b->line);
		ret = get_next_line(fd, &b->line);
		if (ret == -1)
			return (errors(ERR_IN_CUB));
		if (rd_map_alloc(b, FALSE) == 0)
			return (0);
		b->map.height = (ret == 0) ? b->map.height : b->map.height + 1;
	}
	return (1);
}
