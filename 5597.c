#include <stdio.h>

/*void	check(int *result, int n)
{
	int	i, j;
	int	temp;

	i = 0;
	printf("%d", result[0]);
	temp = 0;
	while (i <= n)
	{
		j = 0;
		while (j <= n - i)
		{
			if (result[j] > result[j + 1])
			{
				temp = result[j];
				result[j] = result[j + 1];
				result[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	printf("%d\n", result[0]);
	printf("%d", result[1]);
}*/

int	main()
{
	int	i, j, n;
	int	number[28] = {0};
	int	result[28] = {0};
	int	flag;
	int	temp;

	i = 0;
	while (i < 28)
	{
		scanf("%d", &number[i]);
		i++;
	}
	n = 1;
	j = 0;
	while (n <= 30)
	{	
		flag = 0;
		i = 0;
		while (i < 28)
		{
			if (number[i] == n)	
				flag = 1;
			i++;
		}
		if (flag == 0)
		{
			result[j] = n;
			j++;
		}
		n++;
	}
	temp = 0;
	if (result[0] > result[1])
	{
		temp = result[0];
		result[0] = result[1];
		result[1] = temp;
	}
	printf("%d\n", result[0]);
	printf("%d", result[1]);
	return (0);
}
