#include <stdio.h>

void	DFS(int	*result, int count, int N, int M)
{
	int	i,j;
	int	exists;

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
			exists = 0;
			j = 0;
			while (j < count)
			{
				if (result[j] == i)
					exists = 1;
				j++;
			}
			if (!exists)
			{
				result[count] = i;
				DFS(result, count + 1, N, M);
			}
			i++;
		}
	}
}

int	main()
{
	int	N,M;
	scanf("%d %d", &N, &M);
	
	int	result[M];
	DFS(result, 0, N, M);
	return (0);
}
