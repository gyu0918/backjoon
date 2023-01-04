#include <stdio.h>

int main(void)
{
	int	i;
	int	n;
	int	result;
	int	temp;
	
	scanf("%d", &n);
	i = 1;
	while(i <= n)
	{
		temp = i;
		result = i;
		while(temp > 0)
		{
			result += temp % 10;
			temp /= 10;
		}
		if(result == n)
		{
			printf("%d\n", i);
			break ;
		}
		if(i == n)
		{
			printf("0");
			break;
		}
		i++;
	}
}
