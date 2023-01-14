#include <stdio.h>

void	DFS2(int *result, int count, int N, int M)
{
	int i, j;
	
	i = 1;
	while (i <= N)
	{
		if (count == 0)
			result[0] = i;
		else
		{
			j = 0;
			while (j < count)
			{
				if (result[j] >= i)
					break ;
				j++;
			}
			if (j == count)
				result[count] = i;
			else
				continue ;
		}
		if (M - 1 == count)
		{
			int n = 0;
			while (n < M)
				printf("%d ", result[n++]);
			printf("\n");
		}
		else
			DFS2(result, count + 1, N, M);
		i++;
	}

}

int	main()
{
	int	N, M;
	int	result[8];
	
	scanf("%d %d", &N, &M);
	DFS2(result, 0, N, M);
	return (0);
}
