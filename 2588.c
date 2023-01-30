#include <stdio.h>

int	main()
{
	int	A,B;
	int	z,x,c,m;

	scanf("%d", &A);
	scanf("%d", &B);
	z = A*(B%10);
	m = B%100;
	x = A*(m/10);
	c = A*(B/100);
	printf("%d\n", z);
	printf("%d\n", x);
	printf("%d\n", c);
	printf("%d\n", z + x*10 + c*100);
	return (0);
}
