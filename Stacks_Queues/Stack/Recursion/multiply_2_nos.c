#include<stdio.h>
#include<stdlib.h>

int mult(int a, int b)
{
	if(a==1)
	{
		return b;
	}
	else
	{
		return b + mult(a-1,b) ;
	}
}

int main()
{
	int a=5, b=6;
	int prod = mult(a,b);
	printf("Product of %d and %d =  %d \n",a,b,prod);
	return 0;
}