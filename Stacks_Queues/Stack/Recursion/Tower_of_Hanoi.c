#include<stdio.h>

void toh(int n,char s, char d,char t)
{
	if(n==1)
	{
		printf("Move disk %d from %c to %c\n",n,s,d);
		return;
	}
	toh(n-1, s, t, d);		// moving disks from 1st to 2nd tower
	printf("Move disk %d from %c to %c\n",n,s,d);	//moving largest disks
	toh(n-1, t, d, s);		// moving disks from 2nd to 3rd tower
}

int main()
{
	void toh(int n,char a,char b,char c);
	int n;
	printf("Enter no of disks : ");
	scanf("%d",&n);
	toh(n,'A','B','C');
	printf("\n");
	return 0;
}

