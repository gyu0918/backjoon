#include <stdio.h>

int	main()
{
	int	N, k;
	int	i, j;
	int	temp;
	int	result[1000] = {0};

	scanf("%d %d", &N, &k);

	i = 0;
	while (i < N)
	{
		scanf("%d", &result[i]);
		i++;
	}
	i = 0;
	while (i < N)
	{
		temp = 0;
		j = i + 1;
		while (j < N)
		{
			if (result[i] < result[j])
			{
				temp = result[i];
				result[i] = result[j];
				result[j] = temp;
			}
			j++;
		}
		i++;
	}
	printf("%d", result[k - 1]);
	return (0);
}
