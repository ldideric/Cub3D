/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 12:59:04 by ldideric      #+#    #+#                 */
/*   Updated: 2020/09/25 14:25:07 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	checks(int fd, char *buffer)
{
	int		ret;

	ret = 1;
	if (fd < 0 || buffer == NULL)
		return (-1);
	if (buffer[0] == '\0')
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
			return (ret);
		buffer[ret] = '\0';
		ret = (ret > 0) ? 1 : ret;
	}
	return (ret);
}

static char	*eachline(char **buffer, char *str, int ret)
{
	char *new;

	if (*buffer[0] == '\0')
	{
		new = ft_gnl_strdup(str, TRUE);
		free(str);
		if (new == NULL)
			return (NULL);
		if (ret == 0 && new[ft_gnl_len(new, TRUE) - 1] != '\n')
		{
			new[ft_gnl_len(new, FALSE)] = '\n';
			new[ft_gnl_len(new, FALSE)] = '\0';
		}
		return (new);
	}
	str = ft_gnl_strjoin(str, *buffer);
	if (str == NULL)
		return (NULL);
	*buffer = clr_to_nl(*buffer);
	if (*buffer == NULL)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

int			free_all(t_fd *list)
{
	free(list->str);
	list->str = NULL;
	free(list->buffer);
	list->buffer = NULL;
	return (-1);
}

char		*gnl_expanded(t_fd *filed, int fd, int *ret)
{
	while (filed->str[ft_gnl_len(filed->str, TRUE) - 1] != '\n')
	{
		*ret = checks(fd, filed->buffer);
		if (*ret < 0)
			return (NULL);
		filed->str = eachline(&filed->buffer, filed->str, *ret);
		if (filed->str == NULL)
			return (NULL);
	}
	if (*ret == 0)
	{
		free(filed->buffer);
		filed->buffer = NULL;
	}
	filed->str[ft_gnl_len(filed->str, TRUE) - 1] = '\0';
	return (filed->str);
}

int			get_next_line(int fd, char **line)
{
	static t_fd		filed[4096];
	int				ret;

	if (BUFFER_SIZE < 1 || fd < 0 || fd > 4095)
		return (-1);
	filed[fd].str = ft_gnl_calloc(1);
	if (filed[fd].str == NULL)
		return (free_all(&filed[fd]));
	filed[fd].str[0] = '\0';
	if (filed[fd].buffer == NULL || filed[fd].buffer[0] == '\0')
	{
		free(filed[fd].buffer);
		filed[fd].buffer = ft_gnl_calloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (filed[fd].buffer == NULL)
			return (free_all(&filed[fd]));
	}
	filed[fd].str = gnl_expanded(&filed[fd], fd, &ret);
	if (filed[fd].str == NULL)
		return (free_all(&filed[fd]));
	*line = ft_gnl_strdup(filed[fd].str, TRUE);
	free(filed[fd].str);
	return (ret);
}
