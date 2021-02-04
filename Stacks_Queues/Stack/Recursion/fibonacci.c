#include<stdio.h>
#include<stdlib.h>

int fib(int n)
{
	if(n==0 || n==1)
		return n;
	else
		return fib(n-1) + fib(n-2);
}

int main()
{
	int n;
	printf("Enter no. of fibonacci numbers : ");
	scanf("%d",&n);
	int res = fib(n);
	printf("%d\n",res);
	return 0;
}