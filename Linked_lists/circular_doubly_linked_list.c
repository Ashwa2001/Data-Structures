//program to implement circular doubly linked List
#include<stdio.h>
#include<stdlib.h>
struct node
{
 	int data;
  	struct node* next,*prev;
};

void insert_head(struct node**,int);
void insert_tail(struct node**,int);
void delete_node(struct node**,int);
void display(struct node*);

int main()
{
	struct node *head;
  	int ch,x,pos;
  	head=NULL;//pointer to the first node of the list

 	while(1)
  	{ 
    	display(head);
    	printf("\n1..Insert Head\n");
    	printf("2..Insert Tail\n");
    	printf("3..Delete a Node..\n");
    	printf("4..Display\n");
    	printf("5..Exit\n");
    	scanf("%d",&ch);
    	switch(ch)
    	{
     		case 1:printf("Enter the number...");
            	scanf("%d",&x);
            	insert_head(&head,x);
            	break;
     		case 2:printf("Enter the number...");
            	scanf("%d",&x);
            	insert_tail(&head,x);
            	break;
    		case 3: printf("Enter the value of the node to be deleted...");
            	scanf("%d",&x);
            	delete_node(&head,x);
            	break;
     		case 4:display(head);
            	break;
     		case 5:exit(0);
   		}
 	}
}

void delete_node(struct node**p,int x)
{
	struct node *q,*r;

  	q=*p;//copy of the first node
 	//move till you find the node
 	//or you reach the last node
  	while((q->next!=*p)&&(q->data!=x))
  	{
        q=q->next;
  	}
 	if(q->data==x)//node found
  	{
    	if(q->next==q)//only one node
      	{
        	*p=NULL; // make head NULL
    	}
      	else
        {
            if(q==*p) //first node
            {
                *p=q->next; //make head point to next node		
            }
            q->prev->next=q->next; 
	    	q->next->prev=q->prev;
        }
       free(q);
	}
   	else
   	{
    	printf("Node not found..\n");
   	}
}
        
void insert_head(struct node**p,int x)
{
	struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=temp->prev=temp;

    if(*p==NULL)
    {
    	*p=temp;
    }
    else
    {
		(*p)->prev->next=temp;
		temp->prev=(*p)->prev;
        temp->next=*p;
        (*p)->prev=temp;
		*p=temp;
    }
}

void display(struct node *p)
{
	struct node *q;
  	if(p==NULL)
  	{
   		printf("\nEmpty list..\n");
   	}
 	else
  	{
  		q=p;
   		while(q->next!=p)
   		{
      		printf("%d<->",q->data);
      		q=q->next;
   		}
  		printf("%d< ->",q->data);//last node
  	}
}


  void insert_tail(struct node**p,int x)
 {
    struct node *temp;

    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=temp->prev=temp;
    if(*p==NULL)
    {
        *p=temp;
    }
    else
    {
    	(*p)->prev->next=temp;
    	temp->prev=(*p)->prev;
    	temp->next=*p;
    	(*p)->prev=temp; 
    }
}
  
  












