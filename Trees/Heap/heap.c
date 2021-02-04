#include<stdio.h>
//implement heap by using bottom up technique
void bot_heap(int*,int);
void top_heap(int *, int);
  
int main()
{
	int h[100];//heap;
    int i,n;//no of elements
    printf("Enter the no of elements..\n");
    scanf("%d",&n);
    printf("Enter the elements..\n");
    for(i=0;i<n;i++)
    {
     	scanf("%d",&h[i]);
    }
   	// bot_heap(h,n-1);//pass index of last element
   	top_heap(h,n);//pass index of the last element 
   	printf("After creating heap..\n");
    for(i=0;i<n;i++)
    {
    	printf("%d ",h[i]);
    }
   
}


void top_heap(int *h, int n)
{
	int c,p,i,key;
	for(i=1;i<n;i++)
	{
		c=i;
		key= h[c];
		p=(c-1)/2; 		//find the parent
						//while key is greater than the parent
						//or root is reached
		while((c>0)&&(key > h[p]))
		{
			h[c]=h[p];//move the parent down
			c=p;
			p=(c-1)/2;
		}
		h[c]=key;
	}
			
}

void bot_heap(int *h, int n) 
{
	
  	//n is the index of the last element
	int k,i,p,key;

	for(k=(n-1)/2; k>=0;k--)
	{
		p=k;
		key=h[p];
		
		i=2*p+1;//get the index of left child
		while(i<=n)//until left child exists
		{
			if((i+1)<=n)//check if right child exists
			{
				if(h[i+1]>h[i])
				{
					i++; //get the index of largest child
				}
			}
			if(key<h[i])
			{
				h[p]=h[i];//move child up
				p=i;
				i=2*p+1; //get the left child
			}
			else{
				break;	
			}
		}
     	h[p]=key;//insert the key
	}	 
}

	
 














 













































      






















