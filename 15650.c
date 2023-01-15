#include <stdio.h>

void	DFS2(int *result, int count, int N, int M)
{
	int 	i, j, flag;
	int	prev;

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
		prev = 1;
		if (count > 0)
			prev = result[count - 1];
		i = prev;
		while (i <= N)
		{
			j = 0;
			flag = 0;
			while (j < count)
			{
				if (result[j] == i)
					flag = 1;
				j++;
			}
			if (flag == 0)
			{
				result[count] = i;
				DFS2(result, count + 1, N, M);
			}
			i++;
		}
	}
}

int	main()
{
	int	N, M;
	scanf("%d %d", &N, &M);
	
	int	result[M];
	DFS2(result, 0, N, M);
	return (0);
}
