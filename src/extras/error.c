/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/25 17:47:59 by ldideric      #+#    #+#                 */
/*   Updated: 2020/09/24 22:00:26 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <extra.h>

void		*errors(char *error)
{
	(error == ERR_NO_CUB) ? ft_printf(ERR_NO_CUB) : (int)NULL;
	(error == ERR_IN_CUB) ? ft_printf(ERR_IN_CUB) : (int)NULL;
	(error == ERR_MALLOC) ? ft_printf(ERR_MALLOC) : (int)NULL;
	(error == ERR_IN_MLX) ? ft_printf(ERR_IN_MLX) : (int)NULL;
	(error == ERR_IN_GNL) ? ft_printf(ERR_IN_GNL) : (int)NULL;
	return (NULL);
}
