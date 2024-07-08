/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 19:57:21 by timatias          #+#    #+#             */
/*   Updated: 2024/06/30 20:31:57 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strrev(char *str)
{
	int	i = -1;
	int	length = 0;
       	char	temporary;
	while(str[length] != '\0')
		length++;
	
	while(++i < length / 2)	
	{
		temporary = str[i];
		str[i] = str[length - 1 - i];
		str[length - 1 -i] = temporary;
	}
	return (str);

}
