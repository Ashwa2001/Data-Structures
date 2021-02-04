#include<stdio.h>
#include<stdlib.h>
//program to implement descending priority queue
struct pqueue
{
    int pty;
    int data;
};

void pqinsert(int,int,struct pqueue*,int*);
struct pqueue pqdelete(struct pqueue*,int*);
void qdisplay(struct pqueue*,int);

int main()
{
    int k,ch,pty,x;
    struct pqueue pq[100];
  
    struct pqueue temp;
    int count=0;
    while(1)
    {
        printf("\n1..insert");
        printf("\n2..remove");
        printf("\n3..display");
        printf("\n4..EXIT\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the priority..");  
                    scanf("%d",&pty);
                    printf("Enter the value");
                    scanf("%d",&x);
                    pqinsert(x,pty,pq,&count);
                    break;

            case 2: temp=pqdelete(pq,&count);
                    if(temp.data>0)
                    {
                        printf("deleted element:-       data=%d",temp.data);
                        printf("                    priority=%d\n",temp.pty);
                    }
                    break;
            case 3: qdisplay(pq,count);
                    break;

            case 4: exit(0); 
        }
    }
}


struct pqueue pqdelete(struct pqueue *pq, int *count)
{
	int i;
	struct pqueue temp;
	if(*count==0)//empty queue
	{
		temp.data=-1; 
		temp.pty=-1;
	}
	else
	{
		temp=pq[0]; // get the first element
		for(i=1; i<=*count-1;i++)
        {
			pq[i-1]=pq[i];//move element up
        }
		(*count)--;
	}
    return temp; //return the element
} 
			
			
void pqinsert(int x, int pty, struct pqueue *pq, int *count)
{
	int j;
	struct pqueue key;
	key.data=x;
	key.pty=pty; 
	j  = *count-1;
	
	//while the priority of element at location j
	//is greater than the priority of element being inserted
	while( (j>=0) && (pq[j].pty > key.pty ) )
	{
		pq[j+1]=pq[j]; //move the element down
		j--;
	}
	pq[j+1]=key; // insert the element at its correct position
	(*count)++; //increment count
}

	
	
void qdisplay(struct pqueue *q, int count)
{
    int i;
    if(count==0)
    {
     printf("Empty Queue");
    }
    else
    {
        for(i=0;i<count;i++)
        {
            printf("\ndata = %d",q[i].data);
            printf("  pty=%d",q[i].pty);
            printf("\n");
        }  
    }
}


    