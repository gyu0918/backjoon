#include <stdio.h>

int	main()
{
	long long	N, i, min;
	long long	result, cur;

	scanf("%lld", &N);
	long long	A[N-1];
	i = 0;
	while (i < N - 1)
	{
		scanf("%lld", &A[i]);
		i++;
	}
	result = 0;
	i = 0;
	cur = 0;
	min = 0;
	while (i < N - 1)
	{
		scanf("%lld", &cur);
		if (i == 0 || min > cur)
			min = cur;
		result += min * A[i];
		i++;	
	}
	printf("%lld", result);
	return (0);
}
