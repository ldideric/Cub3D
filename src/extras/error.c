/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/25 17:47:59 by ldideric      #+#    #+#                 */
/*   Updated: 2020/09/29 18:36:38 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <extra.h>

int		rd_struct_free(char *s, t_base *b)
{
	if (b->sprites.no)
		free(b->sprites.no);
	if (b->sprites.so)
		free(b->sprites.so);
	if (b->sprites.we)
		free(b->sprites.we);
	if (b->sprites.ea)
		free(b->sprites.ea);
	if (b->sprites.s)
		free(b->sprites.s);
	printf(ERR_STRING, ERR_PARSER, ft_substr(s, 0, 2));
	return (0);
}

int		errors(char *error)
{
	if (error == ERR_NO_CUB)
		ft_printf(ERR_NO_CUB);
	if (error == ERR_IN_CUB)
		ft_printf(ERR_IN_CUB);
	if (error == ERR_MALLOC)
		ft_printf(ERR_MALLOC);
	if (error == ERR_IN_MLX)
		ft_printf(ERR_IN_MLX);
	if (error == ERR_IN_GNL)
		ft_printf(ERR_IN_GNL);
	return (0);
}
