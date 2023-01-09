#include <stdio.h>

int	main()
{
	int	death_count = 0;
	int	N;
	int	check = 0;
	int	count = 0;
	int	num;

	scanf("%d", &N);

	num = 666;
	while (1)
	{
		count = 0;
		check = num;
		while (check > 0)
		{
			if (check % 10 == 6)
				count++;
			else
				count = 0;
			if (count == 3)
			{
				death_count++;
				break ;
			}
			check = check / 10;
		}
		if (death_count == N)
			break;
		num++;
	}
	printf("%d\n", num);
}
