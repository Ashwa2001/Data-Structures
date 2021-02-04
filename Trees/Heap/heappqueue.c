#include<stdlib.h>
#include<stdio.h>
//implement priority queue with heap(max heap)
//each element has value and priority field

struct element
{
  int data,pty;
};

void pqinsert(struct element *,struct element,int*);
struct element pqdelete(struct element *, int*);
void display(struct element*,int);
void heapify(struct element* , int);
int main()
{
  
    struct element hpq[100],temp;
    int size,p,count,ch,k; 
    count=0;
    while(1)
    {
        display(hpq,count);
        printf("\n1..Insert");
        printf("\n2..Delete");
        printf("\n3..Display");
        printf("\n4..EXIT");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the value and the priority..");
                    scanf("%d %d",&temp.data,&temp.pty);
                    pqinsert(hpq,temp,&count);
                    break;

            case 2: temp=pqdelete(hpq,&count);
                    printf("Element = %d Priority= %d\n",temp.data, temp.pty);
                    break;

            case 3:exit(0); 
        }
    }
}

void pqinsert(struct element *h, struct element key, int *count)    //top down approach
{
	int c,p;
	c=*count;
	h[c]=key;  //last element
	++*count;
	p=(c-1)/2; //find the parent
	while((c>0) &&(key.pty > h[p].pty))
	{
		h[c]=h[p];
		c=p;
		p=(c-1)/2;
	}
	h[c]=key;
}
	
		
struct element pqdelete(struct element *h, int *count)
{
    struct element key;
    key=h[0];
    h[0]=h[*count-1];   //copy last element into 1st
    --*count;           //decrement count
    heapify(h,*count-1);
    return key;
}

void heapify(struct element * h, int n)
{
    int i,j;
    struct element key;
    j=0;
    key=h[j];
   
    i=2*j+1;//find the child
    while(i<=n)//repeat until left child exists
    {
        if((i+1)<=n)//check if right child exists
        {
            if(h[i+1].pty >h[i].pty)//get the largest child
            {
                i++;
            }
        }
        if(key.pty < h[i].pty)
        {
            h[j]=h[i];//move the child up
            j=i;
            i=2*j+1;//find new left child
        }
        else
        {
            break;
        }
    }
    h[j]=key;//insert the key
}


  
   
void display(struct element *h, int count)
{
    int i;
    printf("\nThe elements in the priority queue are..\n");
    
    for(i=0;i<count;i++)
    {
        printf("Element= %d , Priority = %d\n",h[i].data,h[i].pty);
    }
    printf("\n");
}





