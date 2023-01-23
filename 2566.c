#include <stdio.h>

int	main()
{
	int	i, j, N;
	int	result[9][9] = {0};
	
	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			scanf("%d", &result[i][j]);
			j++;
		}
		i++;
	}
	N = 99;
	while (N >= 0)
	{
		i = 0;
		while (i < 9)
		{
			j = 0;
			while (j < 9)
			{
				if (result[i][j] == N)
				{
					printf("%d\n", N);
					printf("%d %d", i + 1 , j + 1);
					return (0);
				}
				j++;
			}
			i++;
		}
		N--;
	}
	return (0);
}
