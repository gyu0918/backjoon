#include <stdio.h>

int	main()
{
	int	i, N, K, count;
	int	asset[10] = {0};

	scanf("%d %d", &N, &K);
	i = 0;
	while (i < N)
	{
		scanf("%d", &asset[i]);
		i++;
	}
	i = N - 1;
	count = 0;
	while (K > 0)
	{
		if (asset[i] > K)
		{
			i--;
		}
		else
		{
			K = K - asset[i];
			count++;
		}
	}
	printf("%d", count);
	return (0);
}