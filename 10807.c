#include <stdio.h>

int	main()
{
	int	count;
	int	i;
	int	N,V;
	int	result[100] = {0};

	scanf("%d", &N);
	i = 0;
	while (i < N)
	{
		scanf("%d ", &result[i]);
		i++;
	}
	scanf("%d", &V);
	i = 0;
	count = 0;
	while (i < N)
	{
		if (result[i] == V)
			count++;
		i++;
	}
	printf("%d", count);
	return (0);
}
