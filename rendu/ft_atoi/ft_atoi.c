/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 19:39:11 by timatias          #+#    #+#             */
/*   Updated: 2024/06/30 19:46:21 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef int inteiro;

int	ft_atoi(const char *str)
{
	int	resultado = 0;
	inteiro sinal = 1;
	
	while (*str == ' '  || (*str >= '\t' && *str <= '\f'))
		str++;
	if (*str == '-')
		sinal = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >=  '0' && *str <= '9')
	{
		resultado *= 10;
		resultado += *str - '0';
		str++;
	}
	return (resultado * sinal);
}
