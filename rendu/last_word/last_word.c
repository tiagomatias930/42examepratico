/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 21:10:23 by timatias          #+#    #+#             */
/*   Updated: 2024/06/30 21:24:11 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>


void	last_word (char *str)
{
	int	i = 0;
	int	j = 0;
	
 
	while(str[i] != '\0')
	{
		if(str[i] == ' ' && str[i + 1] >= 33 && str[i +1] <= 126)
			j = i + 1;
		i++;
	
	}
	while(str[j] >= 33 && str[j] <= 127)
	{
		write(1, &str[j], 1);
		j++;
	}
}


int	main(int argc, char **argv)
{
	if(argc == 2)
		last_word(argv[1]);
	write(1, "\n", 1);




}
