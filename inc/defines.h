/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   defines.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/12 14:28:12 by ldideric      #+#    #+#                 */
/*   Updated: 2020/11/02 18:43:22 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/*
** DEFINES
*/

# define MLX_SYNC_IMAGE_WRITABLE		1
# define MLX_SYNC_WIN_FLUSH_CMD			2
# define MLX_SYNC_WIN_CMD_COMPLETED		3

# define WIN_NAME	"Gameboy Advanced"
# define TRUE		1
# define FALSE		0

# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_Q		12
# define KEY_ESC	53
# define KEY_LFT	123
# define KEY_RGT	124

/*
** ERROR MESSAGES
*/

# define ERR_NO_CUB	"\x1b[31mERROR\x1b[0m:\nNo .cub file given!"
# define ERR_S_FLAG	"\x1b[31mERROR\x1b[0m:\nWrong second argument given!"
# define ERR_IN_CUB	"\x1b[31mERROR\x1b[0m:\nWrong .cub file input!\n"
# define ERR_IN_TAB	"\x1b[31mERROR\x1b[0m:\nTabulation in .cub file!\n"
# define ERR_MALLOC	"\x1b[31mERROR\x1b[0m:\nMemory allocating failed."
# define ERR_IN_MLX	"\x1b[31mERROR\x1b[0m:\nSomething went wrong with MLX!"
# define ERR_IN_GNL	"\x1b[31mERROR\x1b[0m:\nSomething went wrong with GNL!"
# define ERR_OPEN_F	"\x1b[31mERROR\x1b[0m:\nOpen failed!"

# define ERR_TWO_SP	"\x1b[31mERROR\x1b[0m:\nWrong num of spawn points in map!"
# define ERR_SPAWN_ "\x1b[31mERROR\x1b[0m:\nWrong spawnpoint character!"
# define ERR_MAP_PR	"\x1b[31mERROR\x1b[0m:\nWalls in map not correct!"
# define ERR_SPR_IN	"\x1b[31mERROR\x1b[0m:\nSprite input not correct!"
# define ERR_TEX_IN	"\x1b[31mERROR\x1b[0m:\nTexture input not correct!"

# define ERR_PARSER	"Something went wrong with parsing the"
# define ERR_SPRITE	"\x1b[31mERROR\x1b[0m:\n%s %s sprite!"
# define ERR_C_COL_	"\x1b[31mERROR\x1b[0m:\n%s ceiling color!"
# define ERR_F_COL_	"\x1b[31mERROR\x1b[0m:\n%s floor color!"
# define ERR_PR_RES	"\x1b[31mERROR\x1b[0m:\n%s resolution!"

#endif
