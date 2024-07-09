#include <unistd.h>

int main(int ac, char *av[])
{
	int i = 0;

	if (ac == 2)
	{
		char *ti;
		ti = (char *) av[1];
		while (ti[i] == ' ' || ti[i] == '\t')
			i++;
		while(ti[i] && ti[i] != ' ' && ti[i] != '\t')
		{
			write(1, &ti[i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
