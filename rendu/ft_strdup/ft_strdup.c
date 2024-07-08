/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 20:39:27 by timatias          #+#    #+#             */
/*   Updated: 2024/06/30 20:48:04 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>

char    *ft_strdup(char *src)
{
	int	length = 0;
	int	i = 0;
	char	*strcyp;

	while(src [length] != '\0')
		length++;
	strcyp = malloc (sizeof(*strcyp) * (length + 1));
	if( strcyp != NULL)
	{
		while(src[i] != '\0')
		{
			strcyp[i] = src[i];

			i ++; 
		}
	}
	return (strcyp);



}
