#include<stdio.h>

void	QuickSort(int arr[], int left, int right)
{
	int	L = left, R = right;
	int	temp;
	int	pivot = arr[(left + right) / 2];
	int	i;

  	while (L <= R)
	{
		while (arr[L] < pivot)
			L++;
		while (arr[R] > pivot)
			R--;
		if (L <= R)
		{
			if (L != R)
			{
				temp = arr[L];
				arr[L] = arr[R];
				arr[R] = temp;
			}
			L++; R--;
    		}
  	}
  	if (left < R)
    		QuickSort(arr, left, R);
  	if (L < right)
    		QuickSort(arr, L, right);
}

int	main(void)
{
	int	i, N;
	scanf("%d", &N);
	int result[1000000] = {0};

	i = 0;
	while (i < N)
	{
		scanf("%d", &result[i]);
		i++;
	}
	QuickSort(result, 0, N - 1); // 9 = 10-1
	i = 0;
	while (i < N)
	{
		printf("%d\n", result[i]);
		i++;
	}
	return 0;
}
