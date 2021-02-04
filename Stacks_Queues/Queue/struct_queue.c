#include<stdlib.h>
#include<stdio.h>
struct queue
{
	int *item;
	int f;
	int r;
	int size;
};

int qinsert(int ,struct queue *);
int qdelete(struct queue*);
void display(struct queue);
int main()
{
  
  struct queue q;
  int ch,k,x;
  q. f=q.r=-1;
  printf("Enter the size of the queue..");
  scanf("%d",&q.size);

  q.item=(int*)malloc(sizeof(int)*q.size);
  while(1)
  {
    display(q);
    printf("\n1..Insert");
    printf("\n2..Delete");
    printf("\n3..display");
    printf("\n4..EXIT");
    scanf("%d",&ch);
    switch(ch)
    {
       case 1:printf("Enter the value..");
              scanf("%d",&x);
              k=qinsert(x,&q);
              if(k>=0)
                 printf("Element inserted successfully\n");
               break;
       case 2:k=qdelete(&q);
              if(k>=0)
                printf("element deleted=%d\n",k);
              break;
        case 4:exit(0); 
   }
  }
 }

  int qinsert(int x,struct queue *p)
  {
     //check if the queue is full;
	 
	 if(p->r==p->size-1)
	 {
		 printf("Queue full.. Cannot insert.\n");
		 return -1;
	 }
	 
	 p->r++;  // increment rear
	 p->item[p->r]=x;
	 if(p->f==-1)
		 p->f=0;  // if first element
	 return 1;
  }
	 
	 int qdelete(struct queue *p)
	 {
	   int x;
	   //check if queue is empty
	   
	   if(p->f==-1)
	   {
		   printf("Queue empty..\n");
	       return -1;
	   }
	   
	   x=p->item[p->f];
	   if(p->f==p->r)//only one element
	      p->f=p->r=-1;
	else
	     p->f++; // increment front after deletion
	 return x;
	 }
	 
	 void display(struct queue p)
	 {
		 
		 int i;
		 if(p.f==-1)
			 printf("Empty Queue...\n");
		 else
		 {
			 for(i=p.f;i<=p.r;i++)
				 printf("%d ",p.item[i]);
		 }
	 }
	 
		 
	 
	 
	 
    






