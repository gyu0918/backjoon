#include <stdio.h>
int main()
{
	long long int p1[101][101],p2[101][101];
	int n, m, i, j, cnt = 15;
	long long int temp;
	scanf("%d%d", &n, &m);
	for (i = 0; i <= n; i++)
	{
		p1[i][0] = 1;
		p1[i][i] = 1;
	}
	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= n; j++)
			p2[i][j] = 0;
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j < i; j++)
		{
			p1[i][j] = p1[i - 1][j - 1] + p1[i - 1][j];
			p2[i][j] = p2[i - 1][j - 1] + p2[i - 1][j];
			if (p1[i][j] >= 10000000000000000)
			{	
				p2[i][j]++;
				p1[i][j] -= 10000000000000000;
			}
		}
	}
	temp = p1[n][m];
	while (temp > 9)
	{
		temp /= 10;
		cnt--;
	}
	if (p2[n][m] == 0)
		printf("%lld\n", p1[n][m]);
	else if (p1[n][m] > 0)
	{
		printf("%lld", p2[n][m]);
		while (cnt--)
			printf("0");
		printf("%lld", p1[n][m]);
	}
	return 0;
}