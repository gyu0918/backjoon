#include <stdio.h>

int	main()
{
	int	N, M, i, j, flag;
	int	original[500000] = {0};
	int	compare[500000] = {0};

	scanf("%d", &N);
	i = 1;
	while (i <= N)
	{
		scanf("%d", &original[i]);
		i++;
	}
	scanf("%d", &M);
	i = 1;
	while (i <= M)
	{
		scanf("%d", &compare[i]);
		i++;
	}
	i = 1;
	while (i <= M)
	{
		flag = 0;
		j = 1;
		while (j <= N)
		{
			if (compare[i] == original[j])
				flag = 1;
			j++;
		}
		printf("%d ", flag);
		i++;
	}
	return (0);
}
