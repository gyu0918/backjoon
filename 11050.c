#include <stdio.h>


int	factorial(int num)
{
	int	result = 1;
	int	i;
	
	i = 1;
	while (i <= num)
	{
		result *= i;
		i++;
	}
	return (result);
}

int	main()
{
	int	N, K;
	int	A,B,C;

	scanf("%d %d", &N, &K);
	A = factorial(N);
	B = factorial(K);
	C = factorial(N-K);
	printf("%d\n", A/(B*C));
	return (0);
}	
	
