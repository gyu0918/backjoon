#include <stdio.h>

int	main()
{
	int	N, M;
	int	i, j;
	int	result[200][100];
	scanf("%d %d", &N, &M);
	i = 0;
	while (i < 2*N)
	{
		j = 0;
		while (j < M)
		{
			scanf("%d", &result[i][j]);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < M)
		{
			printf("%d ", result[i][j] + result[i + N][j]);
			j++;
		}
		i++;
		printf("\n");
	}
	return (0);
}
