#include <stdio.h>

int	main(void)
{
	int	N,M;
	int	card[100] = { 0 };
	int	max, result = 0;

	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++)
		scanf("%d", &card[i]);
	for(int i = 0; i < N; i++)
	{
		for(int j = i + 1; j < N; j++)
		{
			for(int k = j + 1; k< N; k++)
			{
				max = card[i] + card[j] + card[k];
				if (max > result && max <= M)
					result = max;
			}
		}
	}
	printf("%d\n", result);
}
