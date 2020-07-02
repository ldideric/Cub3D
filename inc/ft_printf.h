/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 17:15:25 by ldideric      #+#    #+#                 */
/*   Updated: 2020/07/02 18:21:09 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <libft.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct	s_arg
{
	int			prec;
	int			intprec;
	int			width;
	int			intwidth;
	int			minus;
	int			zero;
	int			hex;
}				t_arg;

typedef int		(*t_spec)(va_list ap, t_arg list);

int				ft_printf(const char *format, ...);
int				ft_flags(char *str, va_list ap);
t_arg			ft_yesflag(char *str, t_arg list, int *i);
t_arg			*ft_argnew(void);
int				ft_numlen(char *str);
int				ft_freestruct(t_arg *list);
int				ft_freestr(char *s);
int				ft_intchars(long long a, int base);
char			*ft_itoa_base(long long a, int base, int big);
char			*ft_ultoa_base(unsigned long a, unsigned long base, int big);
int				printf_c(va_list ap, t_arg list);
int				printf_s(va_list ap, t_arg list);
int				printf_p(va_list ap, t_arg list);
int				printf_di(va_list ap, t_arg list);
int				printf_u(va_list ap, t_arg list);
int				printf_x(va_list ap, t_arg list);
int				printf_per(va_list ap, t_arg list);

#endif
