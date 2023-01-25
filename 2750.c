#include <stdio.h>

int	main()
{
	int	N;
	int	i, j;
	int	temp;

	scanf("%d", &N);
	int	result[1000] = {0};
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
	i = 0;
	while (i < N)
	{
		printf("%d\n", result[i]);
		i++;
	}
	return (0);
}
