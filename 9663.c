#include <stdio.h>

int vx[16], vy[16];

int ft_abs(int a, int b)
{
	if (a - b >= 0)
		return a - b;
	else
		return (a - b) * - 1;
}

int n_queen(int x, int y, int n)
{
	int i;
	i = 0;
	while (i < y) // 백트래킹을 위한 반복문
    // 왜 i < y일까? 우리는 main에서 x좌표를 기준잡고 올렸다. 그리고 재귀로 
    // x좌표에 i, 즉 1씩 증가하고, y좌표는 고정되어있다.(+ 1만큼만)
    // 그렇기에 y좌표까지만 고정하고, x좌표를 이동시키면서 진행시킨다.
    // 이해가 안된다면 디버깅을 n = 4로잡고 다시 해보자.
	{
		if (y == vy[i]) // y좌표가 같을경우 가지치기
			return 0;
		if (x == vx[i]) // x좌표가 같을경우 가지치기
			return 0;
		if (ft_abs(x, vx[i]) == ft_abs(y, vy[i])) // 대각선이 같을경우 가지치기
			return 0;
		i++;
	}
	if (y == n - 1) // 좌표는 0부터 시작하기에 n - 1까지 세준다.
		return 1;
	vx[y] = x; // 왜 vx[y]일까? 위에서 말했듯 y는 고정시켜야 한다.
    // vx[1] = 2, vy[1] = 1 이라고 하면, 두번째줄에 좌표가 2,1에 퀸을 놓는다는 의미.
	vy[y] = y;
	int count = 0;
	i = 0;
	while (i < n)
	{
		count = count + n_queen(i, y + 1, n);
		i++;
	}
	return count;
}

int main()
{
	int i, n;
	int count = 0;
	scanf("%d", &n);
	i = 0;
	while (i < n)
	{
		count = count + n_queen(i, 0, n);
		i++;
	}
	printf("%d", count);
}