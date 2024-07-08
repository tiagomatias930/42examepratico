/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 23:53:42 by timatias          #+#    #+#             */
/*   Updated: 2024/07/07 23:59:39 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main(int ac, char *av[])
{
	int numero1 = 0, numero2 =  0;

	if(ac == 3)
	{
		if ((numero1 = atoi(av[1])) > 0 && (numero2 = atoi(av[2])) > 0)
		{
			while (numero1 != numero2)
			{
				if (numero1 > numero2)
					numero1 -= numero2;
				else
					numero2 -= numero1;
			}
			printf("%d", numero1);
		}
	}
	printf("\n");
	return (0);
}
