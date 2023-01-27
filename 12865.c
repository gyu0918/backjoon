#include <stdio.h>

int	main()
{
	int	N, K;
	int	max;
	int	weight[100] = {0};
	int	value[100] = {0};

	scanf("%d %d", &N, &K);
	i = 0;
	while (i < N)
	{
		scanf("%d %d", &weight[i], &value[i]);
		i++;
	}
	i = 0;
	while (i < N)
	{
		if (weight[i] <= K)
		{
			if (value[i] > value[i + 1])
				max = value[i];
		}
		i++;
	}
	







	return (0);
}
