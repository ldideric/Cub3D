/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   defines.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/12 14:28:12 by ldideric      #+#    #+#                 */
/*   Updated: 2020/10/14 17:11:46 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/*
** DEFINES
*/

# define WIN_NAME	"Gameboy Advanced"
# define TRUE		1
# define FALSE		0

# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_ESC	53
# define KEY_Q		12

/*
** ERROR MESSAGES
*/

# define ERR_PARSER	"Something went wrong with parsing the"
# define ERR_STRING	"\x1b[31mERROR\x1b[0m:\n%s %s sprite!"
# define ERR_IN_CUB	"\x1b[31mERROR\x1b[0m:\nWrong .cub file input!\n"
# define ERR_MALLOC	"\x1b[31mERROR\x1b[0m:\nMemory allocating failed."
# define ERR_IN_MLX	"\x1b[31mERROR\x1b[0m:\nSomething went wrong with MLX!"
# define ERR_NO_CUB	"\x1b[31mERROR\x1b[0m:\nNo .cub file given!"
# define ERR_IN_GNL	"\x1b[31mERROR\x1b[0m:\nSomething went wrong with GNL!"
# define ERR_TWO_SP	"\x1b[31mERROR\x1b[0m:\nTwo or more spawn points in map!"
# define ERR_MAP_PR	"\x1b[31mERROR\x1b[0m:\nWalls in map not correct!"

#endif
