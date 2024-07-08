/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 21:27:37 by timatias          #+#    #+#             */
/*   Updated: 2024/06/30 21:34:44 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		max(int* tab, unsigned int len)
{
	 int	maior = tab[0];
	unsigned int	ti  = 0;

	if (len == 0)
		return (0);
	while(ti <= len)
	{
		if (maior <= tab[ti])
			maior = tab[ti];
		ti++;
	}
	return (maior);
}
