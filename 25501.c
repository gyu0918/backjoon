#include <stdio.h>
#include <string.h>

int	cnt;

int	count()
{
	cnt += 1;
	return cnt;
}

int	recursion(const char *s, int l, int r)
{
	if (l >= r) 
		return 1;
	else if (s[l] != s[r]) 
		return 0;
	else 
	{
		count();
		return recursion(s, l+1, r-1);
	}
}

int	isPalindrome(const char *s)
{
	return recursion(s, 0, strlen(s) - 1);
}

int	main()
{
	int	N;
	int	i;	
	char	result[1001] = {0};
	
	scanf("%d", &N);
	i = 0;
	while (i < N)
	{
		scanf("%s", result);
		printf("%d ", isPalindrome(result));
		printf("%d\n", count());
		cnt = 0;
		i++;
	}
}
