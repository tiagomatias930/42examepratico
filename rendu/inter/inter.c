/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 20:49:43 by timatias          #+#    #+#             */
/*   Updated: 2024/06/30 20:49:44 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	tem_char (char *str, char c)
{
	int	i = 0;
	while(str[i] != '\0')
	{
		if(str[i] == c)
			return 1;
		i++;
	}
	return 0;
}


int	main(int argc, char **argv)
{
	int	i = 0;
	int	j = 0;
	char	aux[126] = {0};
	if(argc == 3)
	{
		while(argv[1][i] != '\0')
		{
			if(tem_char(argv[2], argv[1][i]) && !tem_char(aux, argv[1][i]))
			{
				write(1, &argv[1][i], 1);
				aux[j] = argv[1][i]; 
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);


}
