/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 13:56:19 by ldideric      #+#    #+#                 */
/*   Updated: 2020/09/25 14:25:39 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1048
# endif

# define TRUE 1
# define FALSE 0

typedef struct	s_fd
{
	int			fd;
	char		*str;
	char		*buffer;
}				t_fd;

int				get_next_line(int fd, char **line);
char			*ft_gnl_strdup(char *s1, int a);
char			*ft_gnl_strjoin(char *s1, char *s2);
int				ft_gnl_len(char *str, int a);
char			*clr_to_nl(char *buffer);
void			*ft_gnl_calloc(size_t count);

#endif
