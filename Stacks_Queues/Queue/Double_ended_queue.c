#include<stdlib.h>
#include<stdio.h>
//dequeue using array(use circular list concept)
struct node
{
 	int data;
	struct node *next,*prev;
};

struct dequeue
{
	struct node *front;
 	struct node *rear;
};

void qdisplay(struct dequeue);
void qinsert_head(int ,struct dequeue*);
void qinsert_tail(int ,struct dequeue*);
int  qdelete_head(struct dequeue*);
int  qdelete_tail(struct dequeue*);

int main()
{
 	int k,x,ch;
 	struct dequeue dq; 
 	dq.front=dq.rear=NULL;
  	while(1)
  	{
    	printf("\n1..insert head");
    	printf("\n2..insert Tail");
    	printf("\n3..Delete Head");
    	printf("\n4..Delete Tail");
    	printf("\n5..display");
    	printf("\n6..EXIT");
    	scanf("%d",&ch);
    	switch(ch)
    	{
       		case 1:	printf("Enter the value..");
              		scanf("%d",&x);
              		qinsert_head(x,&dq);
               		break;

       		case 2:	printf("Enter the value..");
              		scanf("%d",&x);
              		qinsert_tail(x,&dq);      
              		break;

       		case 3:	k=qdelete_head(&dq);
	          		if(k>=0)
                 		printf("Element deleted = %d\n",k);
              		break;

       		case 4:	k=qdelete_tail(&dq);
	          		if(k>=0)
                    	printf("Element deleted = %d\n",k);
              		break;

        	case 5: qdisplay(dq); break;

        	case 6: exit(0);
   		}
  	}
}

void qinsert_head(int x, struct dequeue *p)
{
	struct node *temp;  
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=x;
	temp->prev=NULL;
	temp->next=NULL;
	  
	  
    if(p->front==NULL)//empty queue
    {
		p->front=temp;
		p->rear=temp;
	}
    else
	{
	  temp->next=p->front;
      p->front->prev=temp;
	  p->front =temp;
	}
}
  
void  qinsert_tail(int x, struct dequeue *p)
{
	struct node *temp; 
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=x;
	temp->prev=NULL;
	temp->next=NULL;
	
	if(p->front==NULL)//empty queue
	{
		p->front=temp;
		p->rear=temp;
	}
	else
	{
		p->rear->next=temp;
		temp->prev=p->rear;
		p->rear=temp;
	}
}
		  
int qdelete_head(struct dequeue *p)
{
	struct node *q;
	int x;
		
	if(p->front == NULL)//checking if queue is empty
	{
	    return -1;
	}

	q=p->front;
	x=q->data;
	if(p->front==p->rear)//only 1 node
	{
		p->front=NULL;
		p->rear =NULL;
	}
	else
	{
		p->front=q->next;//p->front->next
		p->front->prev=NULL;
	}
    free(q);
	return x;
}


		
int qdelete_tail(struct dequeue *p)
{
	struct node *q;
    int x;	   
	if(p->front==NULL)//check for empty queue
	{
	   return -1;
	}
	q=p->rear;
	x=q->data;

    if(p->front==p->rear)//only one node
    {
	    p->front=p->rear=NULL;
    }
	else
	{
	    p->rear=q->prev;
	    p->rear->next=NULL;
	}
	free(q);
    return x;
}
			 	
  
void qdisplay(struct dequeue dq)
{
    struct node *p;
    if(dq.front==NULL)
    {
        printf("Empty Queue...\n");
    }
    else
    {
       for(p=dq.front;p!=dq.rear;p=p->next)
        {
        	printf("%d ",p->data);
        }
       	printf("%d ",p->data);   //print last node
    }
}