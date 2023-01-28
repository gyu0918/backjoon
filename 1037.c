#include <stdio.h>
#include <stdlib.h>

int	compare(const void *first, const void *second)
{
	if (*(int*)first > *(int*)second)
		return (1);
	else if (*(int*)first < *(int*)second)
		return (-1);
	else
		return (0);
}

int	main()
{
	int	N, i, j, flag;
	int	divisor[51] = {0};

	scanf("%d", &N);
	i = 0;
	while (i < N)
	{
		scanf("%d", &divisor[i]);
		i++;
	}
	qsort(divisor, N, sizeof(int), compare);
	printf("%d", divisor[0]*divisor[N-1]);
	return (0);
}
