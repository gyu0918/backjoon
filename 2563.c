#include <stdio.h>

int	main()
{
	int	N,r,h;
	int	result[100][100] = {0};
	int	count = 0;
	int	i, m, k, j;

	scanf("%d", &N);
	i = 0;
	while (i < N)
	{
		scanf("%d %d", &r, &h);
		m = 100 - (h + 10);
		while (m < 100 - h)
		{
			k = r;
			while (k < r + 10)
			{
				result[m][k] = 1;
				k++;
			}
			m++;
		}
		i++;
	}
	i = 0;
	while (i < 100)
	{
		j = 0;
		while (j < 100)
		{
			if (result[i][j] == 1)
				count++;
			j++;
		}
		i++;
	}
	printf("%d", count);
	return (0);
}
