/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 23:37:58 by timatias          #+#    #+#             */
/*   Updated: 2024/07/07 23:46:48 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 unsigned int    lcm(unsigned int a, unsigned int b)
{
	unsigned int numero = 0;

	if (a == 0 || b == 0)
		return (0);
	if (a > b)
		numero = a;
	else
		numero = b;
	while(1)
	{
		if (numero % a == 0 && numero % b == 0)
			return (numero);
		++numero;
	}
}
