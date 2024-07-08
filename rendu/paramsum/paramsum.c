/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 23:47:22 by timatias          #+#    #+#             */
/*   Updated: 2024/07/07 23:53:01 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putnumero(int numero)
{
	char first, last;

	if (numero < 10)
	{
		first = numero + '0';
		write (1, &first, 1);
	}
	else 
	{
		first = numero / 10 + '0';
		last = numero % 10 + '0';
		write (1, &first, 1);
		write (1, &last, 1);
	}
}

int main(int ac, char *av[])
{
	(void)av;

	putnumero(ac - 1);
	write (1, "\n", 1);
	return (0);
}
