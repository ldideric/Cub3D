/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   leak_grep.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/24 14:15:42 by ldideric      #+#    #+#                 */
/*   Updated: 2020/09/24 14:16:11 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		main(int ac, char **av)
{
	ex00();
	if (ac > 1 && !strcmp(av[1], "leaks"))
		system("leaks CUB3D");
	else
	{
		system("leaks CUB3D >> leaks.txt");
		system("grep \"total leaked bytes\" leaks.txt");
		system("rm leaks.txt");
	}
	return (0);
}
