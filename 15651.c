#include <stdio.h>

void	DFS3(int *result, int count, int N, int M)
{
	int	i;

	if (count == M)
	{
		i = 0;
		while (i < M)
		{
			printf("%d ", result[i]);
			i++;
		}
		printf("\n");
	}
	else
	{
		i = 1;
		while (i <= N)
		{
			result[count] = i;
			DFS3(result, count + 1, N, M);
			i++;
		}
	}
}

int	main()
{
	int	N, M;
	
	scanf("%d %d", &N, &M);
	int	result[1000] = {0};

	DFS3(result, 0, N, M);
	return (0);
}
