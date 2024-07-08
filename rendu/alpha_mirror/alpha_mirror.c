/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 19:03:36 by timatias          #+#    #+#             */
/*   Updated: 2024/06/30 19:11:20 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	main(int argc, char **argv)
{
	int	i = 0;
	char	*str;

	str = (char*)argv[1];

	if(argc == 2)
	{
		while(str[i] != '\0')
		{
			if(str[i] >= 'a' && str[i]<= 'z')
				str[i] = 'z' - str[i] + 'a';

			else if (str[i] >= 'A' && str[i]<= 'Z')
                                str[i] = 'Z' - str[i] + 'A';
			write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return 0;
}
