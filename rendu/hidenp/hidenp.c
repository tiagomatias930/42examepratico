/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 23:30:51 by timatias          #+#    #+#             */
/*   Updated: 2024/07/07 23:37:13 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char *av[])
{
	int texto1 = 0, texto2 = 0;

	if (ac == 3)
	{
		while (av[1][texto1] && av[2][texto2])
		{
			if (av[1][texto1] == av[2][texto2])
				texto1++;
			texto2++;
		}
		if (av[1][texto1] == '\0')
			write (1, "1", 1);
		else
			write (1, "0", 1);
	}
	write (1, "\n", 1);
	return(0);
}
