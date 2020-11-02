/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reader_extra.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/24 18:37:06 by ldideric      #+#    #+#                 */
/*   Updated: 2020/11/02 20:51:26 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

char		**rd_ptr_ret(char *s, t_base *b, int spr)
{
	char	**p;

	p = NULL;
	if (spr == TRUE)
	{
		p = (*(u_int16_t *)s == *(u_int16_t *)"S ") ? &b->spr_img[0].path : p;
		p = (*(u_int16_t *)s == *(u_int16_t *)"S1") ? &b->spr_img[1].path : p;
		p = (*(u_int16_t *)s == *(u_int16_t *)"S2") ? &b->spr_img[2].path : p;
		p = (*(u_int16_t *)s == *(u_int16_t *)"S3") ? &b->spr_img[3].path : p;
		p = (*(u_int16_t *)s == *(u_int16_t *)"S4") ? &b->spr_img[4].path : p;
		p = (*(u_int16_t *)s == *(u_int16_t *)"S5") ? &b->spr_img[5].path : p;
		p = (*(u_int16_t *)s == *(u_int16_t *)"S6") ? &b->spr_img[6].path : p;
		p = (*(u_int16_t *)s == *(u_int16_t *)"S7") ? &b->spr_img[7].path : p;
		return (p);
	}
	p = (*(u_int16_t *)s == *(u_int16_t *)"NO") ? &b->tex_img[0].path : p;
	p = (*(u_int16_t *)s == *(u_int16_t *)"EA") ? &b->tex_img[1].path : p;
	p = (*(u_int16_t *)s == *(u_int16_t *)"SO") ? &b->tex_img[2].path : p;
	p = (*(u_int16_t *)s == *(u_int16_t *)"WE") ? &b->tex_img[3].path : p;
	return (p);
}

int			rd_spr(char *s, t_base *b)
{
	char	**ptr;
	int		i;

	i = 0;
	ptr = rd_ptr_ret(s, b, TRUE);
	if (s[i] != 'S')
		return (0);
	i++;
	if (s[i] != '\0')
	{
		if (!(s[i] == ' ' && s[i + i] != '\0') &&
			!(s[i] >= '1' && s[i] <= '7' && s[i + 1] == ' '))
			return (0);
	}
	else
		return (0);
	i++;
	if (*ptr != NULL)
		return (0);
	*ptr = ft_strtrim(s + i, " \n\t");
	return (*ptr != NULL);
}

int			rd_tex(char *s, t_base *b)
{
	char	**ptr;
	int		i;

	i = 0;
	ptr = rd_ptr_ret(s, b, FALSE);
	i++;
	i++;
	if (*ptr != NULL)
		return (0);
	*ptr = ft_strtrim(s + i, " \n\t");
	return (*ptr != NULL);
}
