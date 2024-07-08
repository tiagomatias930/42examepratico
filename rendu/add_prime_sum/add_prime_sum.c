/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 23:36:19 by timatias          #+#    #+#             */
/*   Updated: 2024/07/04 00:11:46 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	resu = 0;

	while (*str >= '0' && *str <= '9')
	{
		resu = resu * 10 + *str - '0';
		str++;
	}
	return (resu );
}

int	is_prime(int number)
{
	int i = 2;
	
	if (number <= 1)
		return (0);
	while (i * i <= number)
	{
		if (number % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void	putnbr(int number)
{
	if (number > 9)
		putnbr(number / 10);
	char test = number % 10 + '0';
	write (1, &test, 1);
	/*char first, last;

	if (number >= 9)
	{
		first = number + '0';
		write (1, &first, 1);
	}
	else if (number <= 10)
	{
		first = number / 10 + '0';
		last = number % 10 + '0';
		write (1, &first, 1);
		write (1, &last, 1);
	}*/
}

int	main(int ac, char *av[])
{
	int	i = 0, suma = 0;

	if (ac == 2)
	{
		int	number = ft_atoi(av[1]);
		//putnbr(number);
		while (i <= number)
		{
			if (is_prime(i) == 1)
				suma += i;
			i++;
		}
		putnbr(suma);
	}
	else
		putnbr(0);
	write (1, "\n", 1);
	return (0);
}
