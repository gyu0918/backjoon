#include<stdio.h>

int main()
{
	int N;
	int i, j;
	int num;
	int count[10001]={0};

	scanf("%d", &N);
	i = 0;
	while (i < N)
    {
		scanf("%d", &num);
		count[num] = count[num] + 1;
        i++; 
	}
	i = 1;
	while (i<10001)
    {
        j = 1;
		while (j <= count[i])
        { 
			printf("%d\n", i);
            j++;
		}
        i++;
	}
	return 0;
}