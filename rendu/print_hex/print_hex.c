#include <unistd.h>

int	ft_atoi(char *str)
{
	int resu = 0, i = 0;

	while(str[i] != '\0')
	{
		resu *= 10;
		resu = resu + str[i] - '0';
		i++;
	}
	return(resu);
}

void	apresentaHex(int numero)
{
	char hex [] = "0123456789abcdef";

	if (numero >= 16)
		apresentaHex(numero / 16);
	write (1, &hex[numero % 16], 1);
}

int	main(int ac, char *av[])
{
	if (ac == 2)
	{
		int numero = ft_atoi(av[1]);
		apresentaHex(numero);
	}
	write (1, "\n", 1);
	return (0);
}
