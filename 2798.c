#include <stdio.h>

int	main(void)
{
	int	N,M,i,j,k;
	int	card[100] = { 0, };
	int	result,max = 0;

	scanf("%d %d",&N,&M);
	i = 0;
	j = 0;
	k = 0;
	while(i < N)
		scanf("%d",&card[i++]);
	i = 0;
	while (i < N)
	{
		j = i + 1;
		while(j < N)
		{
			k = j + 1;
			while(k < N)
			{
				max = card[i] + card[j] + card[k];
				if (max > result && max <= M)
					result = max;
				k++;
			}
			j++;
		}
		i++;
	}
	printf("%d",result);
}
