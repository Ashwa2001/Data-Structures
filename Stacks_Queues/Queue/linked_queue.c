#include<stdlib.h>
#include<stdio.h>
struct node
{
  int data;
  struct node *next;
};

struct queue
{
	struct node * front;
	struct node *rear;
};


void qinsert(int , struct queue*);
int  qdelete(struct queue *);
void qdisplay(struct queue* );

int main()
{
 	int k,x,ch;
 	struct queue q;
  	q.front=q.rear=NULL;
  	while(1)
  	{
    	printf("\n1..insert");
    	printf("\n2..remove");
    	printf("\n3..display");
    	printf("\n4..EXIT\n");
    	scanf("%d",&ch);
    	switch(ch)
    	{
       		case 1:	printf("Enter the value..");
              		scanf("%d",&x);
              		qinsert(x,&q); 
               		break;
       		case 2:	k=qdelete(&q);
	   				if(k>=0)
   	     				printf("The element deleted = %d\n",k);
              		break;
            case 3: qdisplay(&q);
            		break;
        	case 4:exit(0); 
   		}
  	}
}
 
 
void qinsert(int x, struct queue *p)
{
	struct node *temp; 
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	//is this the first element 
	if(p->front==NULL)
	{
 		p->front=p->rear=temp;
	}
	else
	{
		p->rear->next=temp;
		p->rear=temp;
	}
}
 
int qdelete(struct queue *p)
{
	int x;
	struct node *t;
	if(p->front==NULL)
	{
		printf ("Empty queue..\n");
		return -1;
	}
	t=p->front;
	x=t->data;
	//if there is only one node
	if(p->front==p->rear)
	{
	 	 p->front=p->rear=NULL;
	}
	else
	{
	 	 p->front=t->next; // make front point to next node
	}
	free(t);
	return x;
}
		 
void qdisplay(struct queue *p)
{
	struct node *t;	 
	t=p->front;
	if(t==NULL)
	{
		printf("Empty queue..\n");
	}
	else
	{
		while(t!=p->rear)
		{
		   	printf("%d ",t->data);
			t=t->next;
	    }
		printf("%d ",t->data);//print the last node
	}
}	 
			 
		 
		 
		 
	 
	 
	 
	 
		 
	 
 
 
 
 
 
