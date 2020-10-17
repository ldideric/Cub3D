/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/25 17:47:59 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/15 20:14:34 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int		parse_err(char *s)
{
	if (*(u_int16_t *)ft_substr(s, 0, 2) == *(u_int16_t *)"NO" ||
		*(u_int16_t *)ft_substr(s, 0, 2) == *(u_int16_t *)"EA" ||
		*(u_int16_t *)ft_substr(s, 0, 2) == *(u_int16_t *)"SO" ||
		*(u_int16_t *)ft_substr(s, 0, 2) == *(u_int16_t *)"WE" ||
		*ft_substr(s, 0, 2) == 'S')
		printf(ERR_SPRITE, ERR_PARSER, ft_substr(s, 0, 2));
	else if (*ft_substr(s, 0, 2) == 'F')
		printf(ERR_F_COL_, ERR_PARSER);
	else if (*ft_substr(s, 0, 2) == 'C')
		printf(ERR_C_COL_, ERR_PARSER);
	else if (*ft_substr(s, 0, 2) == 'R')
		printf(ERR_PR_RES, ERR_PARSER);
	exit(0);
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
	if (error == ERR_TWO_SP)
		ft_printf(ERR_TWO_SP);
	if (error == ERR_MAP_PR)
		ft_printf(ERR_MAP_PR);
	if (error == ERR_SPAWN_)
		ft_printf(ERR_SPAWN_);
	exit(0);
	return (0);
}
