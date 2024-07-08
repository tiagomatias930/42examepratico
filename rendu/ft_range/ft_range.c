/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 07:01:28 by timatias          #+#    #+#             */
/*   Updated: 2024/07/07 23:22:50 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     *ft_range(int start, int end)
{
	int *tem, num = abs(end - start) + 1, i = 0;

	tem = (int *)malloc(sizeof(int) * num);

	if (tem == NULL)
		return (NULL);
	while (i < num)
	{
		if(start < end)
		{
			tem[i] = start;
			start++;
		}
		else
		{
			tem[i] = start;
			start--;
		}
		i++;
	}
	return (tem);
}
