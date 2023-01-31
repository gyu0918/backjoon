#include <stdio.h>

int	Euclidean(int first, int second)
{
	int	temp;

	if (first < second)
	{
		temp = first;
		first = second;
		second = temp;
	}
	if (second == 0)
		return (first);
	return (Euclidean(second, first%second));
}		

int	main()
{
	int	N;
	int	i;
	int	ring[100] = {0};
	int	divisor;

	scanf("%d", &N);
	i = 0;
	while (i < N)
	{
		scanf("%d", &ring[i]);
		i++;
	}
	i = 1;
	while (i < N)
	{
		divisor = Euclidean(ring[0], ring[i]);
		printf("%d/%d\n", ring[0]/divisor, ring[i]/divisor);
		i++;
	}
	return (0);
}
