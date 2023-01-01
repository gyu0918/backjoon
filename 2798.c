#include <stdio.h>

int	check_card(char card[101], int N, int M)
{
	int	i;
	int	result;
	char	sum[];

	i = 0;
	result = 0;
	while (1)
	{
		if (card[i + 2] == NULL)
			break ;
		sum[i] = card[i] + card[i + 1] + card[i + 2] 
		if (sum[i] == M)
			return (sum[i]);
			break;
		else if (sum[i] > M)
			break ;
		ddddd




}

int	main()
{
	int	N,M,i;
	char	card[101];
	int	result;

	scanf("%d %d\n",&N,&M);
	i = 0;
	while(i < N)
	{
		scanf("%d",card[i]);
		if (card[i] > M)
			return (0);
		i++;
	}
	result = check_card(card[101],N,M);
	printf("%d",result);
	return (0);
}
