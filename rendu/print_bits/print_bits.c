/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 19:22:06 by timatias          #+#    #+#             */
/*   Updated: 2024/06/30 19:38:44 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	print_bits(unsigned char octet)
{
	int	i = 8;
	unsigned char resultado;
	while(i--)
	{
		resultado = (octet >> i  & 1) + '0';
		write(1, &resultado, 1);
	}
}
