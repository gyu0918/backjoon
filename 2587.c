#include <stdio.h>

int	main()
{
	int	N;
	int	i, j;
	int	temp;
	int	result[1000] = {0};

	N = 5;
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
			if (result[i] > result[j])
			{
				temp = result[i];
				result[i] = result[j];
				result[j] = temp;
			}
			j++;
		}
		i++;
	}
	i = result[0] + result[1] + result[2] + result[3] + result[4];
	printf("%d\n", i/5);
	printf("%d", result[2]);
	return (0);
}
