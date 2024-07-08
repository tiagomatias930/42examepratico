/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 19:51:25 by timatias          #+#    #+#             */
/*   Updated: 2024/06/30 19:51:26 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	reverse_bits(unsigned char octet)
{
	int i = 8;
	unsigned char bytes;
	
	while(i--)
	{
		bytes = ((bytes * 2) + (octet % 2));
		octet /= 2;
	}
	return (bytes);
}
