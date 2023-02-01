#include <stdio.h>

int	Factorial(int num)
{
	int	i;
	int	result;

	result = 1;
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
	int	result;
	int	A, B, C;

	scanf("%d %d", &N, &K);
	A = Factorial(N);
	B = Factorial(K);
	C = Factorial(N - K);
	result = A/(B*C);
	printf("%d\n", result%10007);
	return (0);
}
