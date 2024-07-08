/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 20:32:59 by timatias          #+#    #+#             */
/*   Updated: 2024/06/30 20:33:00 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t i = 0, ti = 0;
	
	while (s[i] != '\0')
	{
		ti = 0;
		while (reject[ti] != '\0')
		{
			if (reject[ti] == s[i])
				return (i);
			ti++;
		
		}
		i++;
	}
	return (i);
}
