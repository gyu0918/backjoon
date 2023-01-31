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
	int	N, flag, i;
	int	A[] = {0};	
	int	count;

	scanf("%d", &N);
	i = 0;
	while (i < N)
	{
		scanf("%d\n", &A[i]);
		i++;
	}
	qsort(A, N, sizeof(int), compare);
	count = 2;
	while (count <=  A[N-1])
	{
		i = 0;
		flag = 0;
		while (i < N)
		{
			if (A[i]%count != A[i+1]%count)
				flag = 1;
			i++;
		}
		if (flag == 0)
			printf("%d ",count);
		count++;
	}
	return (0);
}
