#include <stdlib.h>
#include <stdio.h>

int main(int ac, char *av[])
{
	if (ac == 4)
	{
		if(av[2][0] == '*')
			printf ("%d", (atoi(av[1]) * atoi(av[3])));
		else if (av[2][0] == '/')
			printf ("%d", (atoi(av[1]) / atoi(av[3])));
		else if (av[2][0] == '%')
			printf ("%d", (atoi(av[1]) % atoi(av[3])));
		else if (av[2][0] == '+')
			printf ("%d", (atoi(av[1]) + atoi(av[3])));
		else if (av[2][0] == '-')
			printf ("%d", (atoi(av[1]) - atoi(av[3])));
		else
			printf("\n");
	}
	printf ("\n");
	return (0);
}
