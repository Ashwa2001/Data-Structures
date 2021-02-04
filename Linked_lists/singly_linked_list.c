#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};

int main()
{
	struct node* head;
 	int ch,x,y,pos;
  	void insert_head(struct node **, int);
  	void display(struct node *);
  	void insert_tail(struct node **, int);
  	void delete_first(struct node **);
  	void delete_node(struct node **,int);
  	void delete_pos(struct node **,int);
  	void reverse(struct node **);
  	void insert_pos(struct node **, int , int);
  
  	head=NULL;//pointer to the first node

  	while(1)
  	{
   		display(head);
	   	printf("\n1..Insert head\n");
	    printf("2..Insert tail\n");
	    printf("3..Display\n");
		printf("4..Delete First\n");
		printf("5..Delete a node\n");
		printf("6.Delete at position\n");
		printf("7.Reverse a List\n");
		printf("8. Insert at a position\n");
		printf("9.exit\n");
	    scanf("%d",&ch);
	    switch(ch)
	    {
	    	case 1:	printf("Enter the number\n");
			       	scanf("%d",&x);
			       	insert_head(&head,x);
			       	break;
						
	        case 2:	printf("Enter the number\n");
	              	scanf("%d",&x);
	              	insert_tail(&head,x);
	              	break; 
	        case 3:	display(head);
	              	break;
			case 4:	delete_first(&head);
			      	break;
			case 5:	printf("Enter the value of the node\n");
			       	scanf("%d",&x);
			       	delete_node(&head,x);
			       	break;
			case 6:	printf("Enter the position");
			       	scanf("%d",&x);
			       	delete_pos(&head,x);
			       	break; 	
			case 7:	reverse(&head);
			       	break;
			case 8: printf("Enter the value and the position of the node..");
			        scanf("%d %d",&x,&pos);
					insert_pos(&head,x,pos);
					break;
			case 9: exit(0);
	    }
  	}
}

void insert_pos(struct node **p, int x, int pos)
{
	struct node *prev,*temp,*q;
	int i=1;
	prev=NULL;
	q=*p;
	//create a node
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;	
	//move forward until the position is found
	while((q!=NULL)&&(i<pos))
	{
		prev=q;
		q=q->next;
		i++;
	}
	
	if(q!=NULL) // position found
	{
	    if(prev==NULL) // first position
	    {
			temp->next=*p;
			*p=temp;
	    }
	    else
	    {
			prev->next=temp; //somewhere between 2 and last node
			temp->next=q;
	    }
	}
    else //q==NULL
    {
	   	if(i==pos) //insert at end, last position
	   	{
	     	prev->next=temp;
	   	}
	   	else
	   	{
	     	printf("Invalid Position");
	   	}
    }
}		   
	   
			
		

void reverse( struct node **p)
{
	
	struct node *prev, *temp, *curr;
	prev=NULL;
	curr=*p;
	while(curr!=NULL)
	{
		temp=curr->next;
		curr->next=prev;
		prev=curr;
		curr=temp;
	}
	*p=prev;
} 
	
void delete_pos(struct node **p, int x)
{
	struct node *prev, *q;
	int i;
	i=1;
	prev=NULL;
	q=*p;
	//move forward until the position is found
	
	while((q!=NULL)&&(i<x))
	{  
        prev=q;
		q=q->next;
		i++;
	}
	if(q==NULL)
	{
	    printf("Invalid position");
	}
	else if(prev==NULL) //first postion
	{
	   *p=q->next;//*p=(*p)->next;
	}
	else
	{
	    prev->next=q->next; //delete the node
	}
	free(q);
}
	   
	  
	

void delete_node(struct node **p, int x)
{
	struct node *prev, *q;
	prev=NULL;
	q=*p;//make q point to the first node
	//move forward until you find the node to be deleted
	//or you go beyond the last node
	while( (q!=NULL)&&(q->data!=x))
	{
		prev=q;
		q=q->next;
	}	
	if(q==NULL) // node not found
	{
		printf("Node not found..\n");
	}
	else if(prev==NULL) // first node
	{
	    *p=q->next;	 
	}
	else
	{
	    prev->next=q->next; // some where in middle or last node
	}
	free(q);
}
		
	 
void delete_first(struct node **p)
{
	struct node *q;
	
	q=*p; 
	*p=q->next;  // make head point to next node
	free(q);
}	 
	 

void  insert_tail(struct node **p,int x)
{
	//create node 
	struct node *temp,*q;	
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	
	if(*p==NULL)//is the list empty
	{
	   *p=temp;
	}
	else
	{
		q=*p;
		while(q->next!=NULL)//move forward until you reach the last node
		{
		  q=q->next;
		}
		q->next=temp; //link the new node to last node     
	}
}

void insert_head(struct node **p,int x)
{
	struct node *temp; 
	 //create a node
	 temp=(struct node*)malloc(sizeof(struct node));
	 temp->data=x;
	 temp->next=NULL;
	 
	if(*p==NULL) //is is the first node or list empty 
	{
	  *p=temp;
	}
	else
	{
		temp->next=*p; //link the new node to the existing first node
		*p=temp;//make head point to the first node
	}
}
		  
void display(struct node *p) 
{
	if(p==NULL)
	{
	    printf("Empty List");
	}
	else
	{
		while(p!=NULL)
		{
			printf("%d->",p->data);
			p=p->next;
		}
	}
	printf("\n");
}
	