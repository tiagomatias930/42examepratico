/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:17:55 by timatias          #+#    #+#             */
/*   Updated: 2024/07/05 14:37:53 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int resu = 0;

	while(*str >= '0' && *str <= '9')
	{
		resu = resu * 10;
		resu = resu + *str - '0';
		str++;
	}
	return (resu);
}

void	putnbr(int number)
{
	char first, last;
	
	if (number < 10)
	{
		first = number + '0';
		write (1, &first, 1);
	}
	else
	{
		first = number / 10 + '0';
		last = number % 10 + '0';
		write (1, &first, 1);
		write (1, &last, 1);
	}
}

int is_prime(int number)
{
	int i = 2;

	while(i * i < number)
	{
		if (number % i == 0)
			return (0);
		i++;
	}
	return(1);
}

int	main(int ac, char *av[])
{
	int i = 0, soma = 0;

	if (ac == 2)
	{
		int number = ft_atoi(av[1]);

		while(i <= number)
		{
			if (is_prime(i))
				soma += i;
			i++;
		}
		soma -= 5;
		putnbr(soma);
	}
	else
		putnbr(0);
	write(1, "\n", 1);
}
