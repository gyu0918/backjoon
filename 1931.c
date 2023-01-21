#include <stdio.h>

void	sort(int *A, int *B, int N)
{
	int	i, j, tempA, count;
	int	tempB;

	count = 0;
	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N - i)
		{
			if (B[j] > B[j + 1])
			{
				tempB = B[j];
				B[j] = B[j + 1];
				B[j + 1] = tempB;
				tempA = A[j];
				A[j] = A[J + 1];
				A[j + 1] = tempA; 	
			}
			j++;
		}
		i++:
	}
	i = 0;
	while (i < N)
	{
		if (B[i] < A[i + 1])
			
}

int	main()
{
	int	N, i;
	int	count;
	scanf("%d", &N);
	int	A[N] = {0};
	int	B[N] = {0};
	
	i = 0;
	count = 0;
	while (i < N)
	{
		scanf("%d %d", A[i], B[i]);
		i++:
	}
	sort(A, B, N);
	return (0);
}
