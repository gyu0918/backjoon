#include <stdio.h>

void	DFS4(int *result, int count, int N, int M)
{
	int	i, j, flag;

	if (count == M)
	{
		i = 0;
		while (i < count)
		{
			printf("%d ", result[i]);
			i++;
		}
	}
	i = 1;
	while (i <= N)
	{
		flag = 0;
		j = 0;
		while (j < count)
		{
			if (result[j] == i + 1)
				flag = 1;
			j++;
		}
		if (flag == 0)
		{
			result[count] = i;	
			DFS4(result, count + 1, N, M);
		}
		i++;
	}
}

int	main()
{
	int	N, M;

	scanf("%d %d", &N, &M);
	int	result[1000] = {0};

	DFS4(result, 0, N, M);
	return (0);
}
