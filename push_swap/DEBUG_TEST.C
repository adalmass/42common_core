#include <stdio.h>
#include <string.h>

int	if_double(char *s1, char *s2, int len_s2)
{
	int	i;
	int	j;

	i = 0;
	if (strlen(s1) == len_s2)
	{
		while (s1[i])
		{
			j = 0;
			while (s1[i + j] == s2[j] && s1[i] && s2[i])
			{
				if (j == len_s2)
					return (1);
				j++;
			}
			i++;
		}
	}
	return (0);
}

int main(int ac, char **av)
{
	(void)ac;

	printf("%d\n", if_double(av[1], av[2], strlen(av[2])));
}