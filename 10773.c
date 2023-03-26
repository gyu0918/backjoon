#include <stdio.h>
#define SIZE 100000
int stack[SIZE];
int top = -1;

void push(int data)
{
	top++;
	stack[top] = data;
}

void pop()
{
	stack[top] = 0;
	top--;
}

int main(void)
{
	int k, i, data, sum;
	scanf("%d", &k);
	for(i=0; i<k; i++){
		scanf("%d", &data);
		if(data == 0)	pop();
		else	push(data);
	}
	sum = 0;
	for(i = 0; i<=top; i++){
		sum = sum + stack[i];
	}
	printf("%d", sum);
	return 0;
}