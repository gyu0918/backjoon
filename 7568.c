#include <stdio.h>

int	main()
{
	int	n, i, j, rank;
	int	weight[50] = {0};
	int	tall[50] = {0};

	scanf("%d\n", &n);
	i = 0;
	while (i < n)
	{
		scanf("%d %d\n", &weight[i], &tall[i]);
		i++;
	}
	i = 0;
	while (i < n)
	{
		j = 0;
		rank = 0;
		while (j < n)
		{
			if (weight[i] < weight[j] && tall[i] < tall[j])
			{
				rank++;
			}
			j++;
		}
		i++;
		printf("%d ", rank + 1);
	}
	return (0);
}
