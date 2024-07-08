/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 23:24:13 by timatias          #+#    #+#             */
/*   Updated: 2024/07/07 23:30:11 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     *ft_rrange(int start, int end)
{
	int	*resul, maior = 0, menor = 0, contador = 0, tamanho = 0;

	if (start > end)
	{
		maior = start;
		menor = end;
	}
	else
	{
		maior = end;
		menor = start;
	}
	tamanho = maior - menor;
	resul = malloc(sizeof(int ) * tamanho + 1);

	while (maior >= menor)
	{
		resul [contador] = maior;
		--maior;
		contador++;
	}
	return (resul);
}
