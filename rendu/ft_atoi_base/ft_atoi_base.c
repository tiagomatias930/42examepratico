/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 03:58:19 by timatias          #+#    #+#             */
/*   Updated: 2024/07/04 07:00:43 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_base(const char *str, int str_base)
{
	int	resu = 0, div = 0, sinal = 1, i = 0;
	char *number;

	number = (char *) str;
	if (number[i] == '-')
	{
		sinal = -1;
		i++;
	}
	while (number[i] != '\0')
	{
		if (number[i] >= '0' && number[i] <= '9')
			div = number[i] - '0';
		else if (number[i] >= 'A' && number[i] <= 'F')
			div = number[i] - 'A' + 10;
		else if (number[i] >= 'a' && number[i] <= 'f')
			div = number[i] - 'a' + 10;
		else
			break;
		if (div >= str_base)
			break;
		resu = resu * str_base + div;
		i++;
	}
	resu *= sinal;
	return (resu);
}
