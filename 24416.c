#include <stdio.h>

int f[100] = {0};
int num1;
int num2;

int fib(int n) 
{
    if (n == 1 || n == 2)
        return (1);
    num1++;
    return (fib(n - 1) + fib(n - 2));
    
}

int fibonacci(int n) 
{ 
    int i;

    f[1] = 1;
    f[2] = 1;
    i = 3;
    while (i <= n)
    {    
        f[i] = f[i - 1] + f[i - 2];
        num2++;
        i++;
    }
    return f[n];
}

int main()
{
    int n;

    scanf("%d", &n);
    fib(n);
    fibonacci(n);
    printf("%d %d", num1+1, num2);
    return (0);
}



