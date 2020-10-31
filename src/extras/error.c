/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/25 17:47:59 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/31 21:34:57 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

#define YEET 2

#if YEET == 1

int		parse_err(char *s)
{
	(void)s;
	ft_printf("Error\n");
	exit(0);
	return (0);
}

int		errors(char *error)
{
	(void)error;
	ft_printf("Error\n");
	exit(0);
	return (0);
}

#else

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
	ft_printf("%s", error);
	exit(0);
	return (0);
}

#endif