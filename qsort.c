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
	int	i;
	int	arr[7] = {1, 4, 30, 5, 10, 22, 56};

	// 정렬 전
	i = 0;
	while (i < 7)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");

	// 정렬 후 
	qsort(arr, 7, sizeof(int), compare);
	i = 0;
	while (i < 7)
	{
		printf("%d ", arr[i]);
		i++;
	}
	return (0);
}
