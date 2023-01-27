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
	int data[10] = { 2, 9, 4, 18, 5, 1, 7, 8, 15, 12 };

	printf(" --정렬 전 순서--\n"); //정렬하기 전 상태 출력.
	for (int i = 0; i < 10; i++) 
	{
		printf("%d ", data[i]);
	}
	printf("\n\n");
	
	QuickSort(data, 0, 9); // 9 = 10-1

	printf(" --정렬 후 순서--\n"); //정렬한 후 상태 출력.
	for (int i = 0; i < 10; i++) 
	{
		printf("%d ", data[i]);
	}
	printf("\n");
	return 0;
}
