#include<stdio.h>
#include<stdlib.h>

int array_sum(int* a, int n)
{
	if(n==0)
	{
		return a[n];
	}
	else
	{
		return a[n]+array_sum(a,n-1); 
	}
}

int main()
{
	int a[] = {1,2,3,4,5};
	int n = 4;
	int sum;
	sum = array_sum(a,n);
	printf("sum is : %d \n",sum);
	return 0;
}