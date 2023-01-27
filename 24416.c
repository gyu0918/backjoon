#include <stdio.h>

int	count1;
int	count2;

void	fib(n) 
{
	count1++;
	if (n = 1 || n = 2)
		 return 1;
	else return (fib(n - 1) + fib(n - 2));
}

void	fibonacci(n) 
{
	count2++;
	f[1] <- f[2] <- 1;
	for i <- 3 to n
		f[i] <- f[i - 1] + f[i - 2];
	return f[n];
}

int	main()
{
	int	n;
	
	scanf("%d", &n);
	fib(n);
	fibonacci(n);	
	printf("%d %d", count1, count2);
	return (0);
}
