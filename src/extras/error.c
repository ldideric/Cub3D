/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/25 17:47:59 by ldideric      #+#    #+#                 */
/*   Updated: 2020/09/25 15:06:15 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <extra.h>

void		*errors(char *error)
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
	return (NULL);
}
